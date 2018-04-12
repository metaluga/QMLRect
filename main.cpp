#include <QGuiApplication>
#include <QThread>
#include <QObject>
#include <QQmlApplicationEngine>
#include <QQuickWindow>
#include "engine.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

     QThread* thread = new QThread();
     Engine* myEngine = new Engine();
     myEngine->moveToThread(thread);
     QObject::connect(thread, SIGNAL (started()), myEngine, SLOT (itemRun()));

     QObject *topLevel = engine.rootObjects().value(0);
     QQuickWindow *window = qobject_cast<QQuickWindow *>(topLevel);

     QObject::connect(myEngine, SIGNAL(posChanged(QVariant, QVariant)), window, SLOT(updatePos(QVariant, QVariant)));
     thread->start();


    return app.exec();
}
