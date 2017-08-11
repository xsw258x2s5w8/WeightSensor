#ifndef USERALIVEIMPL_H
#define USERALIVEIMPL_H
#include "useralive.h"
#include <QtSql>
#include "useralive.h"
class UserAliveImpl
{
public:
    UserAliveImpl();

    int deleteInfo();//删除数据库
    int addInfo(UserAlive useralive);//添加在线用户信息
    UserAlive getAuthorityInfo();//返回在线用户信息

private:
    QSqlDatabase database;
};

#endif // USERALIVEIMPL_H
