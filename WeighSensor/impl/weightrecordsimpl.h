#ifndef WEIGHTRECORDSIMPL_H
#define WEIGHTRECORDSIMPL_H
#include "weightrecords.h"
#include <QtSql>

class WeightRecordsImpl
{
public:
    WeightRecordsImpl();
/*
    //基本接口
    int insert1Data(WeightRecords weightRecords);//插入一次过磅信息,返回值为插入结果
    int insert2Data(WeightRecords weightRecords);//插入二次过磅信息,返回值为插入结果
    QList<WeightRecords> selectData();//接收WeightRecords对象数据,若对象数据为NULL,则为查找失败或者无数据
    int deleteData(WeightRecords weightRecords);//删除数据库中WeightRecords对象数据,返回值为删除结果


    //其余接口
    QList<WeightRecords> selectCompleteDataByCondition(QString date,QString carId,QString artId);//通过日期、车号、货号进行查找完整记录(条件查找)
    QList<WeightRecords> selectUnCompleteDataByCondition(QString date,QString carId,QString artId);//通过日期、车号、货号进行查找不完整记录(条件查找)

    WeightRecords selectUnCompleteDataByCarId(QString carId);//通过车号来判断该车子是否有不完整记录，若有则返回该条不完整记录，若无则返回null
    int update2Data(WeightRecords weightRecords);//当进行二次过磅时，第二次进行过磅时可以进行修改数据,也可以方便‘替换上次’功能

    int deleteCompleteData();//删除完整记录的所有数据
    int deleteUnCompleteData();//删除不完整记录的所有数据
*/

    int isComplete(QString carId);//根据车号来查询该车辆是否有未完成的二次过磅,若有则返回记录id
    WeightRecords selectWR(int id);//根据记录id来查找整条记录
    int insertWeightRecords(WeightRecords weightrecords);//isfull 用来判断二次过磅时该车辆是空车还是载货，weightrecords为需要插入的记录
    int updateWeightRecords(WeightRecords weightrecords);//用来更新二次过磅的第二次过磅数据
    int replaceLastWeightRecords(WeightRecords weightrecords);//用来实现替换上次功能
    WeightRecords selectWR1(QString carId);//根据记录id来查找整条记录//根据车号查找该车辆最新一次过磅记录
    WeightRecords selectWR2(QString carId);//根据记录id来查找整条记录//根据车号查找该车辆最新二次过磅记录


private:
    QSqlDatabase database;
};

#endif // WEIGHTRECORDSIMPL_H
