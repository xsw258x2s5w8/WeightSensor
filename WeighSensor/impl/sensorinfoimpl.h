#ifndef SENSORINFOIMPL_H
#define SENSORINFOIMPL_H
#include <QtSql>
#include <QList>
#include "sensorinfo.h"
class SensorInfoImpl
{
public:
    SensorInfoImpl();
    QList<SensorInfo> selectSensorinfo();//读取传感器信息表内所有信息
    int deleteSensorinfo();//删除传感器信息表所有信息
    int insertSensorinfo(SensorInfo sensorInfo);//插入传感器信息
private:
    QSqlDatabase database;
};

#endif // SENSORINFOIMPL_H
