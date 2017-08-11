#ifndef MAININTERFACETEMPIMPL_H
#define MAININTERFACETEMPIMPL_H
#include "maininterfacetemp.h"
#include <QtSql>
class MainInterfaceTempImpl
{
public:
    MainInterfaceTempImpl();
    int deleteMainInterfaceTemp();//删除表内数据
    QList<MainInterfaceTemp> selectMainInterfaceTemp();//读取表内数据
    int insertMainInterfaceTemp(MainInterfaceTemp mainInterfaceTemp);//插入数据

private:
    QSqlDatabase database;
};

#endif // MAININTERFACETEMPIMPL_H
