#include "weightrecordsimpl.h"

//初始化WeightRecords表
WeightRecordsImpl::WeightRecordsImpl()
{
    //创建数据库连接
    if(QSqlDatabase::contains("qt_sql_default_connection"))
      database = QSqlDatabase::database("qt_sql_default_connection");
    else
      database = QSqlDatabase::addDatabase("QSQLITE");
    //设置数据库
    //database.setDatabaseName("/home/hyl/Project/WeightSensor/WeighSensor/data/D28QT.db");
     database.setDatabaseName("/opt/sqlite/D28QT.db");
    //打开连接
    if( !database.open())
    {
       qDebug() << database.lastError();
    }
    else
    {
        qDebug( "Connected!" );
        QSqlQuery query;
        QString createTable_sql = "create table if not exists WeightRecords(id INTEGER PRIMARY KEY AUTOINCREMENT,carId varchar(20),artId varchar(20),grossWeight REAL,tare REAL,netWeight REAL,factoryIn varchar(80),factoryOut varchar(80),userId int,deduction REAL,date1 varchar(20),time1 varchar(20),date2 varchar(20),time2 varchar(20),monitorId int,complete int,ponderation int,remark varchar(255),reserved1 varchar(100),reserved2 varchar(100),reserved3 varchar(100),reserved4 varchar(100),spareWeight REAL)";
        query.prepare(createTable_sql);
        if(!query.exec())
        {
            qDebug() << query.lastError();
        }
    }

    database.close();
}

int WeightRecordsImpl::isComplete(QString carId)//根据车号来查询该车辆是否有未完成的二次过磅,若有则返回记录id
{

    int id = -1;
    if(database.open())
    {
        qDebug()<<"database opened";
        QSqlQuery query;
        //没有该车牌号 如果过磅未完成，属于第二次
        QString select_sql = "select id from WeightRecords where carId=\""+carId+"\"and complete=0 and ponderation=2"; //and complete=1 and ponderation=2";

        query.prepare(select_sql);

        if(!query.exec())
        {
             qDebug()<<query.lastError();
        }
        else
        {
            while(query.next())
            {
                id = query.value(0).toInt();
            }

        }

    }
    database.close();
    return id;
}


WeightRecords WeightRecordsImpl::selectWR(int id)//根据记录id来查找整条记录
{

    WeightRecords weightRecords;
    QString QId = QString::number(id, 10);
    if(database.open())
    {
        qDebug()<<"database opened";
        QSqlQuery query;

        QString select_sql = "select * from WeightRecords where id = " + QId;

        query.prepare(select_sql);

        if(!query.exec())
        {
             qDebug()<<query.lastError();
        }
        else
        {
            while(query.next())
            {
                weightRecords.setId(query.value(0).toInt());
                weightRecords.setUserId(query.value(8).toInt());
                weightRecords.setDate1(query.value(10).toString());
                weightRecords.setDate2(query.value(12).toString());
                weightRecords.setTime1(query.value(11).toString());
                weightRecords.setTime2(query.value(13).toString());
                weightRecords.setFactoryIn(query.value(6).toString());
                weightRecords.setFactoryOut(query.value(7).toString());
                weightRecords.setCarId(query.value(1).toString());
                weightRecords.setArtId(query.value(2).toString());
                weightRecords.setGrossWeight(query.value(3).toFloat());
                weightRecords.setTare(query.value(4).toFloat());
                weightRecords.setNetWeight(query.value(5).toFloat());
                weightRecords.setDeduction(query.value(9).toFloat());
                weightRecords.setMonitorId(query.value(14).toInt());
                weightRecords.setRemark(query.value(17).toString());
                weightRecords.setPonderation(query.value(16).toInt());
                weightRecords.setComplete(query.value(15).toInt());
                weightRecords.setReserved1(query.value(18).toString());
                weightRecords.setReserved2(query.value(19).toString());
                weightRecords.setReserved3(query.value(20).toString());
                weightRecords.setReserved4(query.value(21).toString());
                weightRecords.setSpareWeight(query.value(22).toFloat());
            }

        }

    }
    database.close();
    return weightRecords;
}

int WeightRecordsImpl::insertWeightRecords(WeightRecords weightrecords)//weightrecords为需要插入的记录
{
    if(database.open())
    {
        qDebug()<<"database opened"<<endl;
        QSqlQuery query;
        QString insert_sql = "insert into WeightRecords(carId,artId,grossWeight,tare,netWeight,factoryIn,factoryOut,userId,deduction,date1,time1,date2,time2,monitorId,complete,ponderation,remark,reserved1,reserved2,reserved3,reserved4,spareWeight) values(?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?)";
        //插入数据
        query.prepare(insert_sql);
        //给数据赋值
        QVariantList GroupCarId;
        GroupCarId.append(weightrecords.getCarId());

        QVariantList GroupArtId;
        GroupArtId.append(weightrecords.getArtId());

        QVariantList GroupGrossWeight;
        GroupGrossWeight.append(weightrecords.getGrossWeight());

        QVariantList GroupTare;
        GroupTare.append(weightrecords.getTare());

        QVariantList GroupNetWeight;
        GroupNetWeight.append(weightrecords.getNetWeight());

        QVariantList GroupFactoryIn;
        GroupFactoryIn.append(weightrecords.getFactoryIn());

        QVariantList GroupFactoryOut;
        GroupFactoryOut.append(weightrecords.getFactoryOut());

        QVariantList GroupUserId;
        GroupUserId.append(weightrecords.getUserId());

        QVariantList GroupDeduction;
        GroupDeduction.append(weightrecords.getDeduction());

        QVariantList GroupDate1;
        GroupDate1.append(weightrecords.getDate1());

        QVariantList GroupDate2;
        GroupDate2.append(weightrecords.getDate2());

        QVariantList GroupTime1;
        GroupTime1.append(weightrecords.getTime1());

        QVariantList GroupTime2;
        GroupTime2.append(weightrecords.getTime2());

        QVariantList GroupMonitorId;
        GroupMonitorId.append(weightrecords.getMonitorId());

        QVariantList GroupComplete;
        GroupComplete.append(weightrecords.getComplete());

        QVariantList GroupPonderation;
        GroupPonderation.append(weightrecords.getPonderation());

        QVariantList GroupRemark;
        GroupRemark.append(weightrecords.getRemark());

        QVariantList GroupReserved1;
        GroupReserved1.append(weightrecords.getReserved1());

        QVariantList GroupReserved2;
        GroupReserved2.append(weightrecords.getReserved2());

        QVariantList GroupReserved3;
        GroupReserved3.append(weightrecords.getReserved3());

        QVariantList GroupReserved4;
        GroupReserved4.append(weightrecords.getReserved4());

        QVariantList GroupSpareWeight;
        GroupSpareWeight.append(weightrecords.getSpareWeight());

        //插入到sql语句中
        query.addBindValue(GroupCarId);
        query.addBindValue(GroupArtId);
        query.addBindValue(GroupGrossWeight);
        query.addBindValue(GroupTare);
        query.addBindValue(GroupNetWeight);
        query.addBindValue(GroupFactoryIn);
        query.addBindValue(GroupFactoryOut);
        query.addBindValue(GroupUserId);
        query.addBindValue(GroupDeduction);
        query.addBindValue(GroupDate1);
        query.addBindValue(GroupTime1);
        query.addBindValue(GroupDate2);
        query.addBindValue(GroupTime2);
        query.addBindValue(GroupMonitorId);
        query.addBindValue(GroupComplete);
        query.addBindValue(GroupPonderation);
        query.addBindValue(GroupRemark);
        query.addBindValue(GroupReserved1);
        query.addBindValue(GroupReserved2);
        query.addBindValue(GroupReserved3);
        query.addBindValue(GroupReserved4);
        query.addBindValue(GroupSpareWeight);

        if(!query.execBatch())
        {
             qDebug()<<query.lastError();
             database.close();
             return -1;
        }
        else
        {
             qDebug()<<"插入记录成功";
             database.close();
             return 1;
         }

    }
}
int WeightRecordsImpl::updateWeightRecords(WeightRecords weightrecords)//用来更新二次过磅的第二次过磅数据
{
    if(database.open())
    {
        QSqlQuery query;
        int intId = weightrecords.getId();
        QString id = QString::number(intId,10);
        QString update_sql = "update WeightRecords set date2=?,time2=?,complete=?,grossWeight=?,tare=?,netWeight=?,factoryIn=?,factoryOut=?,deduction=?,spareWeight=? where id="+id;
        query.prepare(update_sql);
        QVariantList GroupDate2;
        GroupDate2.append(weightrecords.getDate2());
        QVariantList GroupTime2;
        GroupTime2.append(weightrecords.getTime2());
        QVariantList GroupComplete;
        GroupComplete.append(weightrecords.getComplete());
        QVariantList GroupGrossWeight;
        GroupGrossWeight.append(weightrecords.getGrossWeight());
        QVariantList GroupTare;
        GroupTare.append(weightrecords.getTare());
        QVariantList GroupNetWeight;
        GroupNetWeight.append(weightrecords.getNetWeight());
        QVariantList GroupFactoryIn;
        GroupFactoryIn.append(weightrecords.getFactoryIn());
        QVariantList GroupFactoryOut;
        GroupFactoryOut.append(weightrecords.getFactoryOut());
        QVariantList GroupDeduction;
        GroupDeduction.append(weightrecords.getDeduction());
        QVariantList GroupSpareWeight;
        GroupSpareWeight.append(weightrecords.getSpareWeight());
        query.addBindValue(GroupDate2);
        query.addBindValue(GroupTime2);
        query.addBindValue(GroupComplete);
        query.addBindValue(GroupGrossWeight);
        query.addBindValue(GroupTare);
        query.addBindValue(GroupNetWeight);
        query.addBindValue(GroupFactoryIn);
        query.addBindValue(GroupFactoryOut);
        query.addBindValue(GroupDeduction);
        query.addBindValue(GroupSpareWeight);
        if(!query.execBatch())
        {
             qDebug()<<query.lastError();
             database.close();
             return -1;
        }
        else
        {
             qDebug()<<"update success";
             database.close();
             return 1;
         }
    }
    database.close();
    return -1;
}

int WeightRecordsImpl::replaceLastWeightRecords(WeightRecords weightrecords)//用来实现替换上次功能
{
    if(database.open())
    {
        QSqlQuery query;
        int intId = weightrecords.getId();
        QString id = QString::number(intId,10);
        QString update_sql = "update WeightRecords set date1=?,time1=?,date2=?,time2=?,grossWeight=?,tare=?,netWeight=?,deduction=?,spareWeight=? where id="+id;
        query.prepare(update_sql);
        QVariantList GroupDate1;
        GroupDate1.append(weightrecords.getDate1());
        QVariantList GroupTime1;
        GroupTime1.append(weightrecords.getTime1());
        QVariantList GroupDate2;
        GroupDate2.append(weightrecords.getDate2());
        QVariantList GroupTime2;
        GroupTime2.append(weightrecords.getTime2());
        QVariantList GroupGrossWeight;
        GroupGrossWeight.append(weightrecords.getGrossWeight());
        QVariantList GroupTare;
        GroupTare.append(weightrecords.getTare());
        QVariantList GroupNetWeight;
        GroupNetWeight.append(weightrecords.getNetWeight());
        QVariantList GroupDeduction;
        GroupDeduction.append(weightrecords.getDeduction());
        QVariantList GroupSpareWeight;
        GroupSpareWeight.append(weightrecords.getSpareWeight());

        query.addBindValue(GroupDate1);
        query.addBindValue(GroupTime1);
        query.addBindValue(GroupDate2);
        query.addBindValue(GroupTime2);
        query.addBindValue(GroupGrossWeight);
        query.addBindValue(GroupTare);
        query.addBindValue(GroupNetWeight);
        query.addBindValue(GroupDeduction);
        query.addBindValue(GroupSpareWeight);
        if(!query.execBatch())
        {
             qDebug()<<query.lastError();
             database.close();
             return -1;
        }
        else
        {
             qDebug()<<"update success";
             database.close();
             return 1;
         }
    }
    database.close();
    return -1;
}

WeightRecords WeightRecordsImpl::selectWR1(QString carId)//根据记录id来查找整条记录//根据车号查找该车辆最新一次过磅记录
{
    WeightRecords weightRecords;
    if(database.open())
    {
        qDebug()<<"database opened";
        QSqlQuery query;

        QString select_sql = "select * from WeightRecords where carId='" + carId+"' and ponderation=1 order by id desc limit 0,1";
        query.prepare(select_sql);

        if(!query.exec())
        {
             qDebug()<<query.lastError();
        }
        else
        {
            while(query.next())
            {
                weightRecords.setId(query.value(0).toInt());
                weightRecords.setUserId(query.value(8).toInt());
                weightRecords.setDate1(query.value(10).toString());
                weightRecords.setDate2(query.value(12).toString());
                weightRecords.setTime1(query.value(11).toString());
                weightRecords.setTime2(query.value(13).toString());
                weightRecords.setFactoryIn(query.value(6).toString());
                weightRecords.setFactoryOut(query.value(7).toString());
                weightRecords.setCarId(query.value(1).toString());
                weightRecords.setArtId(query.value(2).toString());
                weightRecords.setGrossWeight(query.value(3).toFloat());
                weightRecords.setTare(query.value(4).toFloat());
                weightRecords.setNetWeight(query.value(5).toFloat());
                weightRecords.setDeduction(query.value(9).toFloat());
                weightRecords.setMonitorId(query.value(14).toInt());
                weightRecords.setRemark(query.value(17).toString());
                weightRecords.setPonderation(query.value(16).toInt());
                weightRecords.setComplete(query.value(15).toInt());
                weightRecords.setReserved1(query.value(18).toString());
                weightRecords.setReserved2(query.value(19).toString());
                weightRecords.setReserved3(query.value(20).toString());
                weightRecords.setReserved4(query.value(21).toString());
                weightRecords.setSpareWeight(query.value(22).toFloat());
            }

        }

    }
    database.close();
    return weightRecords;
}

WeightRecords WeightRecordsImpl::selectWR2(QString carId)//根据记录id来查找整条记录//根据车号查找该车辆最新二次过磅记录
{
    WeightRecords weightRecords;
    if(database.open())
    {
        qDebug()<<"database opened";
        QSqlQuery query;

        QString select_sql = "select * from WeightRecords where carId='" + carId+"' and ponderation=2 order by id desc limit 0,1";
        query.prepare(select_sql);

        if(!query.exec())
        {
             qDebug()<<query.lastError();
        }
        else
        {
            while(query.next())
            {
                weightRecords.setId(query.value(0).toInt());
                weightRecords.setUserId(query.value(8).toInt());
                weightRecords.setDate1(query.value(10).toString());
                weightRecords.setDate2(query.value(12).toString());
                weightRecords.setTime1(query.value(11).toString());
                weightRecords.setTime2(query.value(13).toString());
                weightRecords.setFactoryIn(query.value(6).toString());
                weightRecords.setFactoryOut(query.value(7).toString());
                weightRecords.setCarId(query.value(1).toString());
                weightRecords.setArtId(query.value(2).toString());
                weightRecords.setGrossWeight(query.value(3).toFloat());
                weightRecords.setTare(query.value(4).toFloat());
                weightRecords.setNetWeight(query.value(5).toFloat());
                weightRecords.setDeduction(query.value(9).toFloat());
                weightRecords.setMonitorId(query.value(14).toInt());
                weightRecords.setRemark(query.value(17).toString());
                weightRecords.setPonderation(query.value(16).toInt());
                weightRecords.setComplete(query.value(15).toInt());
                weightRecords.setReserved1(query.value(18).toString());
                weightRecords.setReserved2(query.value(19).toString());
                weightRecords.setReserved3(query.value(20).toString());
                weightRecords.setReserved4(query.value(21).toString());
                weightRecords.setSpareWeight(query.value(22).toFloat());
            }

        }

    }
    database.close();
    return weightRecords;
}
