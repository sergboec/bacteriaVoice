#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QDebug>
#include <QQuickWindow>
#include <QSettings>
#include <QDir>
#include <QJsonDocument>

#include "logic.h"

int main(int argc, char *argv[])
{
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
        qDebug() << jsonError.errorString();
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
