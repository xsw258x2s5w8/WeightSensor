#include "afterserviceimpl.h"

AfterServiceImpl::AfterServiceImpl()
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
        QString createTable_sql = "create table if not exists AfterService(id INTEGER PRIMARY KEY AUTOINCREMENT,companyName varchar(100),conPerson varchar(20),tel varchar(30))";
        query.prepare(createTable_sql);
        if(!query.exec())
        {
            qDebug() << query.lastError();
        }
    }

    database.close();
}
int AfterServiceImpl::deleteAfterService()//删除数据
{
    if(database.open())
    {
        QSqlQuery query;
        QString delete_sql = "delete from AfterService";
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
AfterService AfterServiceImpl::selectAfterService()//查询数据
{
    AfterService service;
    if(database.open())
    {
        QSqlQuery query(database);

        QString select_all_sql = "select * from AfterService";
        query.prepare(select_all_sql);
        if(!query.exec())
        {
             qDebug()<<query.lastError();
        }
        else
        {
            while(query.next())
            {
                service.setId(query.value(0).toInt());
                service.setCompanyName(query.value(1).toString());
                service.setConPerson(query.value(2).toString());
                service.setTel(query.value(3).toString());
            }

        }
    }
    database.close();
    return service;
}
int AfterServiceImpl::insertAfterService(AfterService afterService)//插入数据
{
    QTextCodec::setCodecForTr(QTextCodec::codecForLocale());
    if(database.open())
    {

        qDebug()<<"database opened"<<endl;
        QSqlQuery query;
        QString insert_sql = "insert into AfterService(companyName,conPerson,tel) values(?,?,?)";
        //插入数据
        query.prepare(insert_sql);
        //给数据赋值
        QVariantList GroupCompanyName;
        GroupCompanyName.append(afterService.getCompanyName());

        QVariantList GroupConPerson;
        GroupConPerson.append(afterService.getConPerson());

        QVariantList GroupTel;
        GroupTel.append(afterService.getTel());
        //插入到sql语句中
        query.addBindValue(GroupCompanyName);
        query.addBindValue(GroupConPerson);
        query.addBindValue(GroupTel);
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
