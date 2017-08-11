#ifndef MAININTERFACEIMPL_H
#define MAININTERFACEIMPL_H
#include "maininterface.h"
#include "maininterfacetemp.h"
#include <QtSql>
class MainInterfaceImpl
{
public:
    MainInterfaceImpl();
    int deleteInterface();//删除表中数据
    int  insertInterface(MainInterface interface);//向表中添加数据
    QList<MainInterface> selectInterface();//获得表中所有数据
    QList<MainInterfaceTemp> selectInterfaceTemp();//获得表中所要向临时表添加的数据
private:
    QSqlDatabase database;
};

#endif // MAININTERFACEIMPL_H
