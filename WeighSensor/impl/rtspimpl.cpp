#include "rtspimpl.h"
#include <QDebug>
RTSPimpl::RTSPimpl()
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
        QString createTable_sql = "create table if not exists RTSP(id INTEGER PRIMARY KEY AUTOINCREMENT,rtsp varchar(100),isUsed int);";
        query.prepare(createTable_sql);
        if(!query.exec())
        {
            qDebug() << query.lastError();
        }
    }

    database.close();
}
RTSP RTSPimpl::selectRtspById(int id)//根据id查询数据
{
    RTSP rtsp;
    if(database.open())
    {
        QSqlQuery query;
        QString Qid = QString::number(id,10);
        QString select_sql = "select * from RTSP where id="+Qid;
        query.prepare(select_sql);

        if(!query.exec())
        {
             qDebug()<<query.lastError();
        }
        else
        {
            while(query.next())
            {
                rtsp.setId(query.value(0).toInt());
                rtsp.setRtsp(query.value(1).toString());
                rtsp.setIsUsed(query.value(2).toInt());
            }

        }
    }
    database.close();
    return rtsp;
}
int RTSPimpl::updateRtsp(RTSP rtsp)//更新数据
{
    if(database.open())
    {
        QSqlQuery query;
        int intId = rtsp.getId();
        QString id = QString::number(intId,10);
        QString update_sql = "update RTSP set rtsp=?,isUsed=? where id="+id;
        query.prepare(update_sql);
        QVariantList GroupRtsp;
        GroupRtsp.append(rtsp.getRtsp());
        QVariantList GroupIsUsed;
        GroupIsUsed.append(rtsp.getIsUsed());
        query.addBindValue(GroupRtsp);
        query.addBindValue(GroupIsUsed);
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
int RTSPimpl::insertRtsp(RTSP rtsp)//插入数据
{
    QTextCodec::setCodecForTr(QTextCodec::codecForLocale());
    if(database.open())
    {

        qDebug()<<"database opened"<<endl;
        QSqlQuery query;
        QString insert_sql = "insert into RTSP(rtsp,isUsed) values(?,?)";
        //插入数据
        query.prepare(insert_sql);
        //给数据赋值
        QVariantList GroupRtsp;
        GroupRtsp.append(rtsp.getRtsp());
        QVariantList GroupIsUsed;
        GroupIsUsed.append(rtsp.getIsUsed());
        //插入到sql语句中
        query.addBindValue(GroupRtsp);
        query.addBindValue(GroupIsUsed);

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
int RTSPimpl::deleteRtspById(int id)//根据id删除数据
{
    if(database.open())
    {
        QSqlQuery query;
        //把int类型转化为QString类型
        QString QId = QString::number(id, 10);
        QString delete_sql = "delete from rtsp where id="+QId;//进行字符串拼接
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
