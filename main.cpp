#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QDebug>
#include <QQuickWindow>
#include <QSettings>
#include <QDir>
#include <QJsonDocument>

#include "logic.h"

void myMessageHandler(QtMsgType type, const QMessageLogContext &, const QString & msg)
{
    QString txt;
    switch (type) {
    case QtDebugMsg:
        txt = QString("Debug: %1").arg(msg);
        break;
    case QtWarningMsg:
        txt = QString("Warning: %1").arg(msg);
    break;
    case QtCriticalMsg:
        txt = QString("Critical: %1").arg(msg);
    break;
    case QtFatalMsg:
        txt = QString("Fatal: %1").arg(msg);
    break;
    }
    QFile outFile("log");
    outFile.open(QIODevice::WriteOnly | QIODevice::Append);
    QTextStream ts(&outFile);
    ts.setCodec("UTF-8");
    ts << txt << endl;
}

int main(int argc, char *argv[])
{
    qInstallMessageHandler(myMessageHandler); // Install the handler
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    if (engine.rootObjects().isEmpty()){
        return -1;
    }

    QFile file(QDir::currentPath() + "\\settings.json");
    file.open(QFile::ReadOnly | QIODevice::Text);
    QJsonParseError jsonError;
    QJsonDocument doc = QJsonDocument::fromJson(file.readAll(),&jsonError);
    if (jsonError.error != QJsonParseError::NoError){
        qDebug() << "!settings!parseError = " <<  jsonError.errorString();
    }

    LogicClass* logic = new LogicClass(&doc);

    QObject *topLevel = engine.rootObjects().value(0);
    QQuickWindow *window = qobject_cast<QQuickWindow *>(topLevel);

    QObject::connect(window, SIGNAL(submitTextField(QString)), logic, SLOT(cppSlot(QString)));
    QObject::connect(window, SIGNAL(textDNAChanged(QString)), logic, SLOT(updateDNAText(QString)));

    QObject::connect(logic, SIGNAL(setMusicTrack(QVariant)), window, SLOT(setMusicTrack(QVariant)));
    QObject::connect(logic, SIGNAL(setDNAText(QVariant)), window, SLOT(setOutputDNAText(QVariant)));

    return app.exec();
}
