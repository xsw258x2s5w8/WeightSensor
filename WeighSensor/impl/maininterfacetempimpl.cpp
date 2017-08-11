#include "maininterfacetempimpl.h"

MainInterfaceTempImpl::MainInterfaceTempImpl()
{
    //创建数据库连接
    if(QSqlDatabase::contains("qt_sql_default_connection"))
      this->database = QSqlDatabase::database("qt_sql_default_connection");
    else
      this->database = QSqlDatabase::addDatabase("QSQLITE");
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
        QString createTable_sql = "create table if not exists MainInterfaceTemp(id int,para varchar(40),site int,paraName varchar(40),otherName varchar(40))";
        query.prepare(createTable_sql);
        if(!query.exec())
        {
            qDebug() << query.lastError();
        }
    }

    database.close();
}

int MainInterfaceTempImpl::deleteMainInterfaceTemp()//删除表内数据
{
    if(database.open())
    {
        QSqlQuery query;
        QString delete_sql = "delete from MainInterfaceTemp";//进行字符串拼接
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
QList<MainInterfaceTemp> MainInterfaceTempImpl::selectMainInterfaceTemp()//读取表内数据
{   QList<MainInterfaceTemp> list;
    if(database.open())
    {
        QSqlQuery query(database);

        QString select_all_sql = "select * from MainInterfaceTemp";
        query.prepare(select_all_sql);
        if(!query.exec())
        {
             qDebug()<<query.lastError();
        }
        else
        {
            while(query.next())
            {
                MainInterfaceTemp interface;
                interface.setId(query.value(0).toInt());
                interface.setPara(query.value(1).toString());
                interface.setSite(query.value(2).toInt());
                interface.setParaName(query.value(3).toString());
                interface.setOtherName(query.value(4).toString());
                list.append(interface);
            }
        }
    }
    database.close();
    return list;

}
int MainInterfaceTempImpl::insertMainInterfaceTemp(MainInterfaceTemp mainInterfaceTemp)//插入数据
{
    if(database.open())
    {

        qDebug()<<"database opened"<<endl;
        QSqlQuery query;
        QString insert_sql = "insert into MainInterfaceTemp values(?,?,?,?,?)";
        //插入数据
        query.prepare(insert_sql);
        //给数据赋值
        QVariantList GroupId;
        GroupId.append(mainInterfaceTemp.getId());
        QVariantList GroupPara;
        GroupPara.append(mainInterfaceTemp.getPara());
        QVariantList GroupSite;
        GroupSite.append(mainInterfaceTemp.getSite());
        QVariantList GroupParaName;
        GroupParaName.append(mainInterfaceTemp.getParaName());
        QVariantList GroupOtherName;
        GroupOtherName.append(mainInterfaceTemp.getOtherName());
        //插入到sql语句中
        query.addBindValue(GroupId);
        query.addBindValue(GroupPara);
        query.addBindValue(GroupSite);
        query.addBindValue(GroupParaName);
        query.addBindValue(GroupOtherName);

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
