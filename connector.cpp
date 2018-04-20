#include <QObject>
#include <QQmlApplicationEngine>
#include <QQuickWindow>
#include <QGuiApplication>
#include <QGuiApplication>
#include <QDebug>
#include "connector.h"
#include "sqliteconnector.h"
#include "engine.h"

Connector::Connector(int argc, char *argv[], QObject *parent) : QObject(parent)
{
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    //QObject *topLevel = engine.rootObjects().value(0);
    //QQuickWindow *window = qobject_cast<QQuickWindow *>(topLevel);
    SQLiteConnector* myDB = new SQLiteConnector();
    connect(myDB, SIGNAL(getPositions(int, int)), this, SLOT(positionUpdater(int, int)));

    myDB->updatePositionFromDB();

    engineThread = new QThread();
    Engine* myEngine = new Engine(xPos,yPos);
    myEngine->moveToThread(engineThread);
    connect(engineThread, SIGNAL (started()), myEngine, SLOT (itemRun()));

    QObject *topLevel = engine.rootObjects().value(0);
    QQuickWindow *window = qobject_cast<QQuickWindow *>(topLevel);

    connect(myEngine, SIGNAL(posChanged(QVariant, QVariant)), window, SLOT(updatePos(QVariant, QVariant)));

    engineThread->start();

    connect(window, SIGNAL(buttonClicked(bool)), myEngine, SLOT(setProgramStatus(bool)), Qt::DirectConnection);

    app.exec();
    myDB->savePosition(xPos, yPos);
    delete myDB;
}

Connector::~Connector()
{
    engineThread->quit();
    engineThread->wait();
}

void Connector::test(bool button)
{
    qDebug()<<button;
}

void Connector::positionUpdater(int x, int y)
{
    xPos = x;
    yPos = y;
}
