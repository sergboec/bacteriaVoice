#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QDebug>
#include <QQuickWindow>

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

    LogicClass* logic = new LogicClass();

    QObject *topLevel = engine.rootObjects().value(0);
    QQuickWindow *window = qobject_cast<QQuickWindow *>(topLevel);

    QObject::connect(window, SIGNAL(submitTextField(QString)), logic, SLOT(cppSlot(QString)));
    QObject::connect(logic, SIGNAL(setMusicTrack(QVariant)), window, SLOT(setMusicTrack(QVariant)));

    return app.exec();
}
