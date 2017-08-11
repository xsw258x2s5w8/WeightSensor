#include "userimpl.h"

UserImpl::UserImpl()
{
    //创建数据库连接
    if(QSqlDatabase::contains("qt_sql_default_connection"))
        database = QSqlDatabase::database("qt_sql_default_connection");
    else
        database = QSqlDatabase::addDatabase("QSQLITE");

    //设置数据库
    database.setDatabaseName("/opt/sqlite/D28QT.db");
}

int UserImpl::login(int userId,QString password)//根据userId和password来判断该用户是否登录成功
{
    int result = -1;
    if(database.open())
    {
        QSqlQuery query;

        QString userid = QString::number(userId, 10);
        QString select_sql = "select count(*) from user where userId="+userid+" and password='"+password+"'";
        query.prepare(select_sql);


        if(!query.exec())
        {
             qDebug()<<query.lastError();
        }
        else
        {
            while(query.next())
            {
                result = query.value(0).toInt();
            }


        }
    }
    database.close();
    return result;
}

int UserImpl::modifyPassword(int userId,QString pwNew)//根据userId和pwOld来判断该用户能够更改密码，然后用pwNew来替代之前的密码
{
    if(database.open())
    {
        QSqlQuery query;
        QString id = QString::number(userId,10);
        QString update_sql = "update  user set password=? where id="+id;
        query.prepare(update_sql);
        QVariantList GroupPassword;
        GroupPassword.append(pwNew);
        query.addBindValue(GroupPassword);
        if(!query.execBatch())
        {
             qDebug()<<query.lastError();
             database.close();
             return -1;
        }
        else
        {
             qDebug()<<"password update success";
             database.close();
             return 1;
         }
    }
    database.close();
    return -1;
}

int UserImpl::getAuthority(int userId)//根据userId来获取权限值
{
    int authority=0;
    if(database.open())
    {
        QSqlQuery query;

        QString id = QString::number(userId,10);
        QString select_sql = "select authority from user where userId="+id;
        query.prepare(select_sql);

        if(!query.exec())
        {
             qDebug()<<query.lastError();
        }
        else
        {
            while(query.next())
            {
                authority = query.value(0).toInt();
            }


        }
    }
    database.close();
    return authority;
}

int UserImpl::getUserId(QString userName)//根据uerName来获取权限值
{
    int userId;
    if(database.open())
    {
        QSqlQuery query;

        QString select_sql = "select userId from user where userName='"+userName+"'";
        query.prepare(select_sql);

        if(!query.exec())
        {
             qDebug()<<query.lastError();
        }
        else
        {
            while(query.next())
            {
                userId = query.value(0).toInt();
            }


        }
    }
    database.close();
    return userId;
}
