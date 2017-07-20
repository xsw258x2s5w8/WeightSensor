#include "sqliteimpl.h"

SqliteImpl::SqliteImpl()
{

}

void SqliteImpl::SqliteConnect()
{
    this->db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("D28QT.db");
}
