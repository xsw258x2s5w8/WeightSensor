#ifndef USER_H
#define USER_H
#include <QString>
class User
{
public:
    User();
    int getUserId();
    void setUserId(int id);
    QString getUserName();
    void setUserName(QString userName);
    QString getPassword();
    void setPassword(QString password);
    int getAuthority();
    void setAuthority(int authority);

private:
    int userId;//用户id
    QString userName;//用户名称
    QString password;//密码
    int authority;//用户权限：0：最高权限，1：普通用户权限
};

#endif // USER_H
