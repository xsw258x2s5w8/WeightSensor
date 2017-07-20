#include "artidmanagementimpl.h"

ArtIdManagementImpl::ArtIdManagementImpl()
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
        QString createTable_sql = "create table if not exists ArtIdManagement(id INTEGER PRIMARY KEY AUTOINCREMENT,artId varchar(20),commonName varchar(20));";
        query.prepare(createTable_sql);
        if(!query.exec())
        {
            qDebug() << query.lastError();
        }
    }

    database.close();
}
int ArtIdManagementImpl::insertData(ArtIdManagement artIdManagement)//把ArtIdManagement对象插入数据的功能,返回值为插入结果
{
    QTextCodec::setCodecForTr(QTextCodec::codecForLocale());
    if(database.open())
    {

        qDebug()<<"database opened"<<endl;
        QSqlQuery query;
        QString insert_sql = "insert into ArtIdManagement(artId,commonName) values(?,?)";
        //插入数据
        query.prepare(insert_sql);
        //给数据赋值
        QVariantList GroupArtId;
        GroupArtId.append(artIdManagement.getArtId());
        QVariantList GroupCommonName;
        GroupCommonName.append(artIdManagement.getCommonName());
        //插入到sql语句中
        query.addBindValue(GroupArtId);
        query.addBindValue(GroupCommonName);

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

QList<ArtIdManagement> ArtIdManagementImpl::selectData()//接收ArtIdManagement对象数据,若对象数据为NULL，则为查找失败或者无数据
{
    QList<ArtIdManagement> artIdManagementlist;
    if(database.open())
    {
        QSqlQuery query(database);

        QString select_all_sql = "select * from ArtIdManagement";
        query.prepare(select_all_sql);
        if(!query.exec())
        {
             qDebug()<<query.lastError();
        }
        else
        {
            while(query.next())
            {
                ArtIdManagement management;
                management.setId(query.value(0).toInt());
                management.setArtId(query.value(1).toString());
                management.setCommonName(query.value(2).toString());
                artIdManagementlist.append(management);
            }


        }
    }
    database.close();
    return artIdManagementlist;
}
int ArtIdManagementImpl::deleteData(ArtIdManagement artIdManagement)//删除数据库中CarIdManagement对象数据,返回值为删除结果
{
    if(database.open())
    {
        QSqlQuery query;
        int intId = artIdManagement.getId();
        //把int类型转化为QString类型
        QString id = QString::number(intId, 10);
        QString delete_sql = "delete from ArtIdManagement where id="+id;//进行字符串拼接
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
int ArtIdManagementImpl::updateData(ArtIdManagement artIdManagement)//修改CarIdManagement数据
{
    if(database.open())
    {
        QSqlQuery query;
        int intId = artIdManagement.getId();
        QString id = QString::number(intId,10);
        QString update_sql = "update ArtIdManagement set commonName=? where id="+id;
        query.prepare(update_sql);
        QVariantList GroupCommonName;
        GroupCommonName.append(artIdManagement.getCommonName());
        query.addBindValue(GroupCommonName);
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
