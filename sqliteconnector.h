#ifndef SQLITECONNECTOR_H
#define SQLITECONNECTOR_H

#include <QObject>

class SQLiteConnector : public QObject
{
    Q_OBJECT

    int rectPosX = 250;
    int rectPosY = 250;
    void createDBTable();
public:
    explicit SQLiteConnector(QObject *parent = 0);
    virtual ~SQLiteConnector();

    void updatePositionFromDB();
signals:
    void getPositions(int xPos, int yPos);
public slots:
    void savePosition(const int &xPos,const int &yPos);
};

#endif // SQLITECONNECTOR_H
