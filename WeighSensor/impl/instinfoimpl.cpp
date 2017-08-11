#include "instinfoimpl.h"

InstInfoImpl::InstInfoImpl()
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
        QString createTable_sql = "create table if not exists InstInfo(id INTEGER PRIMARY KEY AUTOINCREMENT,version varchar(40),micrType varchar(40),insId varchar(40),custInfo varchar(255))";
        query.prepare(createTable_sql);
        if(!query.exec())
        {
            qDebug() << query.lastError();
        }
    }

    database.close();
}
int InstInfoImpl::deleteInstInfo()//删除数据信息
{
    if(database.open())
    {
        QSqlQuery query;
        QString delete_sql = "delete from InstInfo";
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
InstInfo InstInfoImpl::selectInstInfo()//查询表内信息
{
    InstInfo info;
    if(database.open())
    {
        QSqlQuery query(database);

        QString select_all_sql = "select * from InstInfo";
        query.prepare(select_all_sql);
        if(!query.exec())
        {
             qDebug()<<query.lastError();
        }
        else
        {
            while(query.next())
            {
                info.setId(query.value(0).toInt());
                info.setVersion(query.value(1).toString());
                info.setMicrType(query.value(2).toString());
                info.setInsId(query.value(3).toString());
                info.setCustInfo(query.value(4).toString());
            }

        }
    }
    database.close();
    return info;
}
int InstInfoImpl::insertInstInfo(InstInfo instInfo)//插入信息
{
    QTextCodec::setCodecForTr(QTextCodec::codecForLocale());
    if(database.open())
    {

        qDebug()<<"database opened"<<endl;
        QSqlQuery query;
        QString insert_sql = "insert into InstInfo(version,micrType,insId,custInfo) values(?,?,?,?)";
        //插入数据
        query.prepare(insert_sql);
        //给数据赋值
        QVariantList GroupVersion;
        GroupVersion.append(instInfo.getVersion());

        QVariantList GroupMicrType;
        GroupMicrType.append(instInfo.getMicrType());

        QVariantList GroupInsId;
        GroupInsId.append(instInfo.getInsId());

        QVariantList GroupCustInfo;
        GroupCustInfo.append(instInfo.getCustInfo());
        //插入到sql语句中
        query.addBindValue(GroupVersion);
        query.addBindValue(GroupMicrType);
        query.addBindValue(GroupInsId);
        query.addBindValue(GroupCustInfo);
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
