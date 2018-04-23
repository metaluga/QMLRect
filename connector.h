#ifndef CONNECTOR_H
#define CONNECTOR_H

#include <QObject>
#include <QThread>
#include "engine.h"

class Connector : public QObject
{
    Q_OBJECT
    bool objectIsMove = false;
    int xPos = 0;
    int yPos = 0;
    QThread engineThread;
    Engine* myEngine;
public:
    explicit Connector(int argc, char *argv[] ,QObject *parent = 0);
    ~Connector();
signals:
    void programStatusChanged(bool status);
private slots:
    void positionUpdater(int x, int y);
    void threadController(const bool isRectMoved);
};

#endif // CONNECTOR_H
