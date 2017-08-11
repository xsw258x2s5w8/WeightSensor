#ifndef AFTERSERVICEIMPL_H
#define AFTERSERVICEIMPL_H
#include <QtSql>
#include "afterservice.h"
class AfterServiceImpl
{
public:
    AfterServiceImpl();
    int deleteAfterService();//删除数据
    AfterService selectAfterService();//查询数据
    int insertAfterService(AfterService afterService);//插入数据
private:
    QSqlDatabase database;
};

#endif // AFTERSERVICEIMPL_H
