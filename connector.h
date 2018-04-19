#ifndef CONNECTOR_H
#define CONNECTOR_H

#include <QObject>

class Connector : public QObject
{
    Q_OBJECT
    bool objectIsMove = false;
    int xPos = 0;
    int yPos = 0;
public:
    explicit Connector(int argc, char *argv[] ,QObject *parent = 0);

signals:

private slots:
    void test(bool button);
    void positionUpdater(int x, int y);
};

#endif // CONNECTOR_H
