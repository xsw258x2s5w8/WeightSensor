#include "authinterfaceimpl.h"
#include "userimpl.h"
AuthInterfaceImpl::AuthInterfaceImpl()
{
    //创建数据库连接
    if(QSqlDatabase::contains("qt_sql_default_connection"))
      database = QSqlDatabase::database("qt_sql_default_connection");
    else
      database = QSqlDatabase::addDatabase("QSQLITE");
    //设置数据库
    database.setDatabaseName("/opt/sqlite/D28QT.db");
}

int AuthInterfaceImpl::isEnter(int userId,int interfaceId)//根据用户id和界面id来判断该用户是否有权限进入该界面
{
    int authority=-1;
    UserImpl userImpl;
    int result = -1;
    authority = userImpl.getAuthority(userId);//得到返回的权限值
    if(database.open())
    {
        QSqlQuery query;

        QString authority1 = QString::number(authority, 10);
        QString interfaceid = QString::number(interfaceId, 10);
        QString select_sql = "select count(*) from authInterface where authority="+authority1+" and interfaceId="+interfaceid;
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
