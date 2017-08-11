#include "maininterfaceimpl.h"

MainInterfaceImpl::MainInterfaceImpl()
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
        QString createTable_sql = "create table if not exists MainInterface(mainId int,paraName varchar(40),isMust int,isSelected int,site int,para varchar(40),otherName varchar(40))";
        query.prepare(createTable_sql);
        if(!query.exec())
        {
            qDebug() << query.lastError();
        }
    }

    database.close();
}
int MainInterfaceImpl::deleteInterface()//删除表中数据
{
    if(database.open())
    {
        QSqlQuery query;
        QString delete_sql = "delete from MainInterface";//进行字符串拼接
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
int MainInterfaceImpl::insertInterface(MainInterface interface)//向表中添加数据
{
    if(database.open())
    {

        qDebug()<<"database opened"<<endl;
        QSqlQuery query;
        QString insert_sql = "insert into MainInterface values(?,?,?,?,?,?,?)";
        //插入数据
        query.prepare(insert_sql);
        //给数据赋值
        QVariantList GroupMainId;
        GroupMainId.append(interface.getMainId());
        QVariantList GroupParaName;
        GroupParaName.append(interface.getParaName());
        QVariantList GroupIsMust;
        GroupIsMust.append(interface.getIsMust());
        QVariantList GroupIsSelected;
        GroupIsSelected.append(interface.getIsSelected());
        QVariantList GroupSite;
        GroupSite.append(interface.getSite());
        QVariantList GroupPara;
        GroupPara.append(interface.getPara());
        QVariantList GroupOtherName;
        GroupOtherName.append(interface.getOtherName());
        //插入到sql语句中
        query.addBindValue(GroupMainId);
        query.addBindValue(GroupParaName);
        query.addBindValue(GroupIsMust);
        query.addBindValue(GroupIsSelected);
        query.addBindValue(GroupSite);
        query.addBindValue(GroupPara);
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
QList<MainInterface> MainInterfaceImpl::selectInterface()//获得表中所有数据
{
    QList<MainInterface> list;
    if(database.open())
    {
        QSqlQuery query(database);

        QString select_all_sql = "select * from MainInterface order by isMust desc";
        query.prepare(select_all_sql);
        if(!query.exec())
        {
             qDebug()<<query.lastError();
        }
        else
        {
            while(query.next())
            {
                MainInterface interface;
                interface.setMainId(query.value(0).toInt());
                interface.setParaName(query.value(1).toString());
                interface.setIsMust(query.value(2).toInt());
                interface.setIsSelected(query.value(3).toInt());
                interface.setSite(query.value(4).toInt());
                interface.setPara(query.value(5).toString());
                interface.setOtherName(query.value(6).toString());
                list.append(interface);
            }
        }
    }
    database.close();
    return list;
}
QList<MainInterfaceTemp> MainInterfaceImpl::selectInterfaceTemp()//获得表中所要向临时表添加的数据
{
    QList<MainInterfaceTemp> list;
    if(database.open())
    {
        QSqlQuery query(database);

        QString select_all_sql = "select * from MainInterface  where isSelected=1 order by site limit 0,6";
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
                interface.setParaName(query.value(1).toString());
                interface.setSite(query.value(4).toInt());
                interface.setPara(query.value(5).toString());
                interface.setOtherName(query.value(6).toString());
                list.append(interface);
            }
        }
    }
    database.close();
    return list;
}
