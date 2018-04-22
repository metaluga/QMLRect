#ifndef ENGINE_H
#define ENGINE_H

#include <QObject>
#include <QVariant>

class Engine : public QObject
{
    Q_OBJECT
    int x = 250;
    int y = 0;
    int screenH = 480;
    int updateDelay = 5;
    bool isProgramWork = true;

public:
    explicit Engine(int xPos, int yPos, QObject *parent = 0);
    int getXPosition();
    int getYPosition();

signals:
    void posChanged(QVariant xPos, QVariant yPos);

public slots:
    void itemRun();
    void setProgramStatus(bool workStatus);
};

#endif // ENGINE_H
