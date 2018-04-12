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
public:
    explicit Engine(QObject *parent = 0);


signals:
    void posChanged(QVariant xPos, QVariant yPos);

public slots:
    void itemRun();
};

#endif // ENGINE_H
