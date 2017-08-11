#include "useraliveimpl.h"

UserAliveImpl::UserAliveImpl()
{
    //创建数据库连接
    if(QSqlDatabase::contains("qt_sql_default_connection"))
        database = QSqlDatabase::database("qt_sql_default_connection");
    else
        database = QSqlDatabase::addDatabase("QSQLITE");

    //设置数据库
    database.setDatabaseName("/opt/sqlite/D28QT.db");

}
int UserAliveImpl::deleteInfo()//删除数据库
{
    if(database.open())
    {

        qDebug()<<"database opened"<<endl;
        QSqlQuery query;
        QString del_sql = "delete from userAlive";
        //插入数据
        query.prepare(del_sql);

        if(!query.exec())
        {
             qDebug()<<query.lastError();
             database.close();
             return -1;
        }
        else
        {
             qDebug()<<"删除成功";
             database.close();
             return 1;
         }

    }

}
int UserAliveImpl::addInfo(UserAlive useralive)//添加在线用户信息
{
    if(database.open())
    {

        qDebug()<<"database opened"<<endl;
        QSqlQuery query;
        QString insert_sql = "insert into userAlive(userId,userName,authority) values(?,?,?)";
        //插入数据
        query.prepare(insert_sql);
        //给数据赋值
        QVariantList GroupUserId;
        GroupUserId.append(useralive.getUserId());
        QVariantList GroupUserName;
        GroupUserName.append(useralive.getUserName());
        QVariantList GroupAuthority;
        GroupAuthority.append(useralive.getAuthority());
        //插入到sql语句中
        query.addBindValue(GroupUserId);
        query.addBindValue(GroupUserName);
        query.addBindValue(GroupAuthority);

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
UserAlive UserAliveImpl::getAuthorityInfo()//返回在线用户信息
{
    UserAlive useralive;
    if(database.open())
    {
        QSqlQuery query;

        QString select_sql = "select * from userAlive";
        query.prepare(select_sql);
        if(!query.exec())
        {
             qDebug()<<query.lastError();
        }
        else
        {
            while(query.next())
            {
                useralive.setUserId(query.value(1).toInt());
                useralive.setUserName(query.value(2).toString());
                useralive.setAuthority(query.value(3).toInt());
            }


        }
    }
    database.close();
    return useralive;

}
