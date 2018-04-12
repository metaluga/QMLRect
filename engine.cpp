#include "engine.h"
#include <QThread>

Engine::Engine(QObject *parent) : QObject(parent)
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
