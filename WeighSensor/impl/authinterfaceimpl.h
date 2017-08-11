#ifndef AUTHINTERFACEIMPL_H
#define AUTHINTERFACEIMPL_H
#include <QtSql>
class AuthInterfaceImpl
{
public:
    AuthInterfaceImpl();

    int isEnter(int userId,int interfaceId);//根据用户id和界面id来判断该用户是否有权限进入该界面

private:
    QSqlDatabase database;
};

#endif // AUTHINTERFACEIMPL_H
