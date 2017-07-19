#ifndef ARTIDMANAGEMENTIMPL_H
#define ARTIDMANAGEMENTIMPL_H
#include <QtSql>
#include "artidmanagement.h"
#include <QString>
class ArtIdManagementImpl
{
public:
    ArtIdManagementImpl();
    int insertData(ArtIdManagement artIdManagement);//把ArtIdManagement对象插入数据的功能,返回值为插入结果
    QList<ArtIdManagement> selectData();//接收ArtIdManagement对象数据,若对象数据为NULL，则为查找失败或者无数据
    int deleteData(ArtIdManagement artIdManagement);//删除数据库中ArtIdManagement对象数据,返回值为删除结果
    int updateData(ArtIdManagement artIdManagement);//修改ArtIdManagement数据

private:
    QSqlDatabase database;
};

#endif // ARTIDMANAGEMENTIMPL_H
