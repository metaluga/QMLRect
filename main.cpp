

#include "connector.h"
#include "engine.h"
#include "sqliteconnector.h"

int main(int argc, char *argv[])
{
    //QGuiApplication app(argc, argv);
    Connector* start = new Connector(argc, argv);

    delete start;
/*
    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

   /*  QThread* thread = new QThread();
     Engine* myEngine = new Engine(23,66);
     myEngine->moveToThread(thread);
     QObject::connect(thread, SIGNAL (started()), myEngine, SLOT (itemRun()));

     QObject *topLevel = engine.rootObjects().value(0);
     QQuickWindow *window = qobject_cast<QQuickWindow *>(topLevel);

     QObject::connect(myEngine, SIGNAL(posChanged(QVariant, QVariant)), window, SLOT(updatePos(QVariant, QVariant)));
     thread->start();
*/
    return 0; // app.exec();
}
