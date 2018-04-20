#ifndef CONNECTOR_H
#define CONNECTOR_H

#include <QObject>
#include <QThread>

class Connector : public QObject
{
    Q_OBJECT
    bool objectIsMove = false;
    int xPos = 0;
    int yPos = 0;
    QThread* engineThread;
public:
    explicit Connector(int argc, char *argv[] ,QObject *parent = 0);
    ~Connector();
signals:

private slots:
    void test(bool button);
    void positionUpdater(int x, int y);
};

#endif // CONNECTOR_H
