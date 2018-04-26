#include "engine.h"
#include <QThread>
#include <QDebug>
#include <QCoreApplication>

Engine::Engine(int xPos, int yPos, QObject *parent) : QObject(parent), x(xPos), y(yPos)
{

}

int Engine::getXPosition()
{
    return x;
}

int Engine::getYPosition()
{
    return y;
}

void Engine::itemRun()
{

        if(isUp)
        {
            ++y;
        }
        else
        {
            --y;
        }
        if (isUp && (y > screenH))
        {
            isUp = false;
        }
        else if(!isUp && (y < 1))
        {
            isUp = true;
        }
        QThread::msleep(updateDelay);
        emit posChanged(x, y);

}

void Engine::setProgramStatus(bool workStatus)
{
    if (workStatus != isProgramWork)
    {
        isProgramWork = workStatus;
    }
}
