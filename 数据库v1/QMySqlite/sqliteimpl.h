#ifndef SQLITEIMPL_H
#define SQLITEIMPL_H

#include <QtSql>

class SqliteImpl
{
public:
    SqliteImpl();
    void SqliteConnect();
    
private:
    QSqlDatabase db;
};

#endif // SQLITEIMPL_H
