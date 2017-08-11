#include "ipconfigimpl.h"
#include <QDebug>
IpConfigImpl::IpConfigImpl()
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
        QString createTable_sql = "create table if not exists IpConfig(id INTEGER PRIMARY KEY AUTOINCREMENT,ip varchar(30),subnetWay varchar(30),gateWay varchar(30),dns varchar(30));";
        query.prepare(createTable_sql);
        if(!query.exec())
        {
            qDebug() << query.lastError();
        }
    }

    database.close();
}
int IpConfigImpl::isExistIp()//判断表中是否存有ip数据
{
    int isExist = -1;
    if(database.open())
    {
        QSqlQuery query(database);

        QString select_all_sql = "select count(*) from IpConfig";
        query.prepare(select_all_sql);
        if(!query.exec())
        {
             qDebug()<<query.lastError();
        }
        else
        {
            while(query.next())
            {
                isExist = query.value(0).toInt();
            }


        }
    }
    database.close();
    return isExist;
}
int IpConfigImpl::insertIpConfig(IpConfig ipconfig)//把数据插入ip设置表中
{
    QTextCodec::setCodecForTr(QTextCodec::codecForLocale());
    if(database.open())
    {

        qDebug()<<"database opened"<<endl;
        QSqlQuery query;
        QString insert_sql = "insert into IpConfig(ip,subnetWay,gateWay,dns) values(?,?,?,?)";
        //插入数据
        query.prepare(insert_sql);
        //给数据赋值
        QVariantList GroupIp;
        GroupIp.append(ipconfig.getIp());
        QVariantList GroupSubnetWay;
        GroupSubnetWay.append(ipconfig.getSubnetWay());
        QVariantList GroupGateWay;
        GroupGateWay.append(ipconfig.getGateWay());
        QVariantList GroupDns;
        GroupDns.append(ipconfig.getDns());
        //插入到sql语句中
        query.addBindValue(GroupIp);
        query.addBindValue(GroupSubnetWay);
        query.addBindValue(GroupGateWay);
        query.addBindValue(GroupDns);
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
IpConfig IpConfigImpl::selectIpConfig()//查找表中的数据
{
    IpConfig ipconfig;
    if(database.open())
    {
        QSqlQuery query(database);

        QString select_all_sql = "select * from IpConfig";
        query.prepare(select_all_sql);
        if(!query.exec())
        {
             qDebug()<<query.lastError();
        }
        else
        {
            while(query.next())
            {
                ipconfig.setId(query.value(0).toInt());
                ipconfig.setIp(query.value(1).toString());
                ipconfig.setSubnetWay(query.value(2).toString());
                ipconfig.setGateWay(query.value(3).toString());
                ipconfig.setDns(query.value(4).toString());
            }


        }
    }
    database.close();
    return ipconfig;
}
int IpConfigImpl::deleteIpConfig()//删除表中的数据
{
    if(database.open())
    {
        QSqlQuery query;
        QString delete_sql = "delete from IpConfig";
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
