#include "engine.h"
#include <QThread>

Engine::Engine(int xPos, int yPos, QObject *parent) : QObject(parent), x(xPos), y(yPos)
{

}

void Engine::itemRun()
{
    bool isUp = true;
    while(true)
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
        emit posChanged(x, y);
        QThread::msleep(updateDelay);
     }
}
