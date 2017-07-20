#ifndef CARIDMANAGEMENTIMPL_H
#define CARIDMANAGEMENTIMPL_H
#include <QtSql>
#include "caridmanagement.h"
#include <QString>
class CarIdManagementImpl
{
public:
    CarIdManagementImpl();
    int insertData(CarIdManagement carIdManagement);//把CarIdManagement对象插入数据的功能,返回值为插入结果
    QList<CarIdManagement> selectData();//接收CarIdManagement对象数据,若对象数据为NULL，则为查找失败或者无数据
    int deleteData(CarIdManagement carIdManagement);//删除数据库中CarIdManagement对象数据,返回值为删除结果
    int updateData(CarIdManagement carIdManagement);//修改CarIdManagement数据

    //其他接口
    float selectDataByCarId(QString carId);//通过carId来查找车辆信息

private:
    QSqlDatabase database;
};

#endif // CARIDMANAGEMENTIMPL_H
