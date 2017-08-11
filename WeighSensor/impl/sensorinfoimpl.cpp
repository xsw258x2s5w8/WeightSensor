#include "sensorinfoimpl.h"

SensorInfoImpl::SensorInfoImpl()
{
    //创建数据库连接
    if(QSqlDatabase::contains("qt_sql_default_connection"))
      database = QSqlDatabase::database("qt_sql_default_connection");
    else
      database = QSqlDatabase::addDatabase("QSQLITE");
    //设置数据库
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
        QString createTable_sql = "create table if not exists SensorInfo(id INTEGER PRIMARY KEY AUTOINCREMENT,sensorId int,protocol varchar(20),address varchar(30),zeroIsn REAL);";
        query.prepare(createTable_sql);
        if(!query.exec())
        {
            qDebug() << query.lastError();
        }
    }

    database.close();
}
QList<SensorInfo> SensorInfoImpl::selectSensorinfo()//读取传感器信息表内所有信息
{
    QList<SensorInfo> list;
    if(database.open())
    {
        QSqlQuery query(database);

        QString select_all_sql = "select * from SensorInfo";
        query.prepare(select_all_sql);
        if(!query.exec())
        {
             qDebug()<<query.lastError();
        }
        else
        {
            while(query.next())
            {
                SensorInfo sensorInfo;
                sensorInfo.setId(query.value(0).toInt());
                sensorInfo.setSensorId(query.value(1).toInt());
                sensorInfo.setProtocol(query.value(2).toString());
                sensorInfo.setAddress(query.value(3).toString());
                sensorInfo.setZeroIsn(query.value(4).toFloat());
                list.append(sensorInfo);
            }


        }
    }
    database.close();
    return list;
}
int SensorInfoImpl::deleteSensorinfo()//删除传感器信息表所有信息
{
    if(database.open())
    {
        QSqlQuery query;
        QString delete_sql = "delete from SensorInfo";
        query.prepare(delete_sql);
        if(!query.exec())
        {
            qDebug()<<query.lastError();
            database.close();
            return -1;
        }
        else
        {
            qDebug()<<"delete success";
            database.close();
            return 1;
        }
    }
    database.close();
    return -1;
}
int SensorInfoImpl::insertSensorinfo(SensorInfo sensorInfo)//插入传感器信息
{
    QTextCodec::setCodecForTr(QTextCodec::codecForLocale());
    if(database.open())
    {

        qDebug()<<"database opened"<<endl;
        QSqlQuery query;
        QString insert_sql = "insert into SensorInfo(sensorId,protocol,address,zeroIsn) values(?,?,?,?)";
        //插入数据
        query.prepare(insert_sql);
        //给数据赋值
        QVariantList GroupSensorId;
        GroupSensorId.append(sensorInfo.getSensorId());
        QVariantList GroupProtocol;
        GroupProtocol.append(sensorInfo.getProtocol());
        QVariantList GroupAddress;
        GroupAddress.append(sensorInfo.getAddress());
        QVariantList GroupZeroIsn;
        GroupZeroIsn.append(sensorInfo.getZeroIsn());
        //插入到sql语句中
        query.addBindValue(GroupSensorId);
        query.addBindValue(GroupProtocol);
        query.addBindValue(GroupAddress);
        query.addBindValue(GroupZeroIsn);

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
