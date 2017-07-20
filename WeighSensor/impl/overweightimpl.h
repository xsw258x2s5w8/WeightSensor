#ifndef OVERWEIGHTIMPL_H
#define OVERWEIGHTIMPL_H
#include <QtSql>
#include "overweight.h"
class overWeightImpl
{
public:
    overWeightImpl();
    int insertData(overWeight overweight);//把overWeight对象插入数据的功能,返回值为插入结果
    QList<overWeight> selectData();//接收overWeight对象数据,若对象数据为NULL，则为查找失败或者无数据
    int deleteData(overWeight overweight);//删除数据库中overWeight对象数据,返回值为删除结果
private:
    QSqlDatabase database;
};

#endif // OVERWEIGHTIMPL_H
