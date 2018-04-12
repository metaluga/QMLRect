#include "sqliteconnector.h"
#include <QDebug>
#include <QtSql>

SQLiteConnector::SQLiteConnector(QObject *parent) : QObject(parent)
{
    QSqlDatabase sdb = QSqlDatabase::addDatabase("QSQLITE");
    sdb.setDatabaseName("db_name.sqlite");
    if (!sdb.open())
    {
        qDebug() << sdb.lastError().text();
    }
}
