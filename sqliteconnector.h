#ifndef SQLITECONNECTOR_H
#define SQLITECONNECTOR_H

#include <QObject>

class SQLiteConnector : public QObject
{
    Q_OBJECT
public:
    explicit SQLiteConnector(QObject *parent = 0);

signals:

public slots:
};

#endif // SQLITECONNECTOR_H