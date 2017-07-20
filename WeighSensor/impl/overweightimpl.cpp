#include "overweightimpl.h"
#include <QDebug>
overWeightImpl::overWeightImpl()
{
    //创建数据库连接
    if(QSqlDatabase::contains("qt_sql_default_connection"))
      this->database = QSqlDatabase::database("qt_sql_default_connection");
    else
      this->database = QSqlDatabase::addDatabase("QSQLITE");
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
        QString createTable_sql = "create table if not exists overWeight(id INTEGER PRIMARY KEY AUTOINCREMENT,date varchar(20),time varchar(20),overweight REAL);";
        query.prepare(createTable_sql);
        if(!query.exec())
        {
            qDebug() << query.lastError();
        }
    }

    database.close();
}

int overWeightImpl::insertData(overWeight overweight)//把overWeight对象插入数据的功能,返回值为插入结果
{
    if(database.open())
    {
        qDebug()<<"database opened"<<endl;
        QSqlQuery query;
        QString insert_sql = "insert into overWeight(date,time,overweight) values(?,?,?)";
        //插入数据
        query.prepare(insert_sql);
        //给数据赋值
        QVariantList GroupDate;
        GroupDate.append(overweight.getDate());
        QVariantList GroupTime;
        GroupTime.append(overweight.getTime());
        QVariantList GroupOverWeight;
        GroupOverWeight.append(overweight.getOverweight());
        //插入到sql语句中
        query.addBindValue(GroupDate);
        query.addBindValue(GroupTime);
        query.addBindValue(GroupOverWeight);

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
QList<overWeight> overWeightImpl::selectData()//接收overWeight对象数据,若对象数据为NULL，则为查找失败或者无数据
{
    QList<overWeight> overlist;
    if(database.open())
    {
        QSqlQuery query(database);

        QString select_all_sql = "select * from overWeight";
        query.prepare(select_all_sql);
        if(!query.exec())
        {
             qDebug()<<query.lastError();
        }
        else
        {
            while(query.next())
            {
                overWeight over;
                over.setId(query.value(0).toInt());
                over.setDate(query.value(1).toString());
                over.setTime(query.value(2).toString());
                over.setOverweight(query.value(3).toFloat());
                overlist.append(over);
            }


        }
    }
    database.close();
    return overlist;
}
int overWeightImpl::deleteData(overWeight overweight)//删除数据库中overWeight对象数据,返回值为删除结果
{
    if(database.open())
    {
        QSqlQuery query;
        int intId = overweight.getId();
        //把int类型转化为QString类型
        QString id = QString::number(intId, 10);
        QString delete_sql = "delete from overWeight where id="+id;//进行字符串拼接
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

