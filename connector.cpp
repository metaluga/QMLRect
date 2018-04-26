#include <QObject>
#include <QQmlApplicationEngine>
#include <QQuickWindow>
#include <QGuiApplication>
#include <QGuiApplication>
#include <QDebug>
#include "connector.h"
#include "sqliteconnector.h"

Connector::Connector(int argc, char *argv[], QObject *parent) : QObject(parent)
{
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    SQLiteConnector* myDB = new SQLiteConnector();
    connect(myDB, SIGNAL(getPositions(int, int)), this, SLOT(positionUpdater(int, int)));

    myDB->updatePositionFromDB();

    myEngine = new Engine(xPos,yPos);
    myEngine->moveToThread(&engineThread);
    connect(&engineThread, SIGNAL (started()), myEngine, SLOT (itemRun()));

    QObject *topLevel = engine.rootObjects().value(0);
    QQuickWindow *window = qobject_cast<QQuickWindow *>(topLevel);

    connect(myEngine, SIGNAL(posChanged(QVariant, QVariant)), window, SLOT(updatePos(QVariant, QVariant)));

    threadController(true);

    connect(this, SIGNAL(programStatusChanged(bool)), myEngine, SLOT(setProgramStatus(bool)), Qt::DirectConnection);
    connect(window, SIGNAL(buttonClicked(bool)), this, SLOT(threadController(bool)));
    connect(window, SIGNAL(positionUpdate()), this, SLOT(windowIsUpdate()));
    app.exec();
    threadController(false);
    myDB->savePosition(myEngine->getXPosition(), myEngine->getYPosition());
    delete myDB;
}

Connector::~Connector()
{
    threadController(false);
    myEngine->setProgramStatus(false);
    engineThread.quit();
    engineThread.wait();
    delete myEngine;
}

void Connector::windowIsUpdate()
{
    if (objectIsMove)
    {
        engineThread.quit();
        engineThread.wait();
        engineThread.start();
    }
}

void Connector::positionUpdater(int x, int y)
{
    xPos = x;
    yPos = y;
}

void Connector::threadController(const bool isRectMoved)
{
    if (objectIsMove != isRectMoved)
    {
        emit programStatusChanged(isRectMoved);

        objectIsMove = isRectMoved;
        if(isRectMoved)
        {
            engineThread.start();
        }
        else
        {
            engineThread.quit();
            engineThread.wait();
        }
    }
}
