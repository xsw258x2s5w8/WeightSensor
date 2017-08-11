#ifndef USERIMPL_H
#define USERIMPL_H
#include <QString>
#include <QtSql>
class UserImpl
{
public:
    UserImpl();

    int login(int userId,QString password);//根据userId和password来判断该用户是否登录成功
    int modifyPassword(int userId,QString pwNew);//用pwNew来替代user之前的密码
    int getAuthority(int userId);//根据userId来获取权限值
    int getUserId(QString userName);//根据uerName来获取权限值

private:
    QSqlDatabase database;
};

#endif // USERIMPL_H
