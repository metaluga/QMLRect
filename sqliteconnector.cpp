#include "sqliteconnector.h"
#include <QDebug>
#include <QtSql>

void SQLiteConnector::createDBTable()
{
    QSqlQuery a_query;
    QString str = "CREATE TABLE rectPosition ("
            "xPos integer, "
            "yPos integer"
            ");";

    bool b = a_query.exec(str);
    if (!b) {
        qDebug() << "Table create error!";
    }

    QString str_insert = "INSERT INTO rectPosition(xPos, yPos) "
            "VALUES (%1, '%2');";
    str = str_insert.arg(QString::number(rectPosX))
            .arg(QString::number(rectPosY));
    b = a_query.exec(str);
    if (!b) {
        qDebug() << "Data insert error!";
    }
}

SQLiteConnector::SQLiteConnector(QObject *parent) : QObject(parent)
{
    QSqlDatabase sdb = QSqlDatabase::addDatabase("QSQLITE");
    sdb.setDatabaseName("db_name.sqlite");
    sdb.open();
    if (! sdb.tables().contains( QLatin1String("rectPosition") ))
    {
        createDBTable();
    }
}

SQLiteConnector::~SQLiteConnector()
{

}

void SQLiteConnector::updatePositionFromDB()
{
    QSqlQuery query("SELECT * FROM rectPosition");
    int idNameX = query.record().indexOf("xPos");
    int idNamey = query.record().indexOf("yPos");
    query.last();

    rectPosX = query.value(idNameX).toInt();
    rectPosY = query.value(idNamey).toInt();
    qDebug() << rectPosX <<rectPosY;
    emit getPositions(rectPosX, rectPosY);
}

void SQLiteConnector::savePosition(const int &xPos, const int &yPos)
{
    QSqlQuery a_query;
    QString str_insert = "INSERT INTO rectPosition(xPos, yPos) "
            "VALUES (%1, '%2');";
    QString str = str_insert.arg(QString::number(xPos))
            .arg(QString::number(yPos));
    bool b = a_query.exec(str);
    if (!b) {
        qDebug() << "Data insert error!";
    }
}

