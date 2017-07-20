#include "caridmanagementimpl.h"
#include <QTextCodec>
CarIdManagementImpl::CarIdManagementImpl()
{
    //创建数据库连接
    if(QSqlDatabase::contains("qt_sql_default_connection"))
      this->database = QSqlDatabase::database("qt_sql_default_connection");
    else
      this->database = QSqlDatabase::addDatabase("QSQLITE");
    //设置数据库
    database.setDatabaseName("/home/hyl/Project/WeightSensor/WeighSensor/data/D28QT.db");
    //打开连接
    if( !database.open())
    {
       qDebug() << database.lastError();
    }
    else
    {
        qDebug( "Connected!" );
        QSqlQuery query;
        QString createTable_sql = "create table if not exists CarIdManagement(id INTEGER PRIMARY KEY AUTOINCREMENT,carId varchar(20),tare REAL);";
        query.prepare(createTable_sql);
        if(!query.exec())
        {
            qDebug() << query.lastError();
        }
    }

    database.close();
}

int CarIdManagementImpl::insertData(CarIdManagement carIdManagement)//把CarIdManagement对象插入数据的功能,返回值为插入结果
{
    QTextCodec::setCodecForTr(QTextCodec::codecForLocale());
    if(database.open())
    {

        qDebug()<<"database opened"<<endl;
        QSqlQuery query;
        QString insert_sql = "insert into CarIdManagement(carId,tare) values(?,?)";
        //插入数据
        query.prepare(insert_sql);
        //给数据赋值
        QVariantList GroupCarId;
        GroupCarId.append(carIdManagement.getCarId());
        qDebug()<<carIdManagement.getCarId();
        QVariantList GroupTare;
        GroupTare.append(carIdManagement.getTare());
        //插入到sql语句中
        query.addBindValue(GroupCarId);
        query.addBindValue(GroupTare);

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

QList<CarIdManagement> CarIdManagementImpl::selectData()//接收CarIdManagement对象数据,若对象数据为NULL，则为查找失败或者无数据
{
    QList<CarIdManagement> carIdManagementlist;
    if(database.open())
    {
        QSqlQuery query(database);

        QString select_all_sql = "select * from CarIdManagement";
        query.prepare(select_all_sql);
        if(!query.exec())
        {
             qDebug()<<query.lastError();
        }
        else
        {
            while(query.next())
            {
                CarIdManagement management;
                management.setId(query.value(0).toInt());
                management.setCarId(query.value(1).toString());
                management.setTare(query.value(2).toFloat());
                carIdManagementlist.append(management);
            }


        }
    }
    database.close();
    return carIdManagementlist;
}
int CarIdManagementImpl::deleteData(CarIdManagement carIdManagement)//删除数据库中CarIdManagement对象数据,返回值为删除结果
{
    if(database.open())
    {
        QSqlQuery query;
        int intId = carIdManagement.getId();
        //把int类型转化为QString类型
        QString id = QString::number(intId, 10);
        QString delete_sql = "delete from CarIdManagement where id="+id;//进行字符串拼接
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
int CarIdManagementImpl::updateData(CarIdManagement carIdManagement)//修改CarIdManagement数据
{
    if(database.open())
    {
        QSqlQuery query;
        int intId = carIdManagement.getId();
        QString id = QString::number(intId,10);
        QString update_sql = "update CarIdManagement set tare=? where id="+id;
        query.prepare(update_sql);
        QVariantList GroupTare;
        GroupTare.append(carIdManagement.getTare());
        query.addBindValue(GroupTare);
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

float CarIdManagementImpl::selectDataByCarId(QString carId)//通过carId来查找车辆信息
{
    //CarIdManagement carIdManagement;
    float tare=-1;
    if(database.open())
    {
        QSqlQuery query;
        QString select_sql = "select * from CarIdManagement where carId='"+carId+"'";
        query.prepare(select_sql);

        if(!query.exec())
        {
             qDebug()<<query.lastError();
        }
        else
        {
            while(query.next())
            {
                tare = query.value(2).toFloat();
            }

        }
    }
    database.close();
    return tare;
}
