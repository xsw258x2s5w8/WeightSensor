#ifndef USERALIVE_H
#define USERALIVE_H
#include <QString>
class UserAlive
{
public:
    UserAlive();
    int getId();
    void setId(int id);
    int getUserId();
    void setUserId(int userId);
    QString getUserName();
    void setUserName(QString userName);
    int getAuthority();
    void setAuthority(int authority);
private:
    int id;
    int userId;//用户id
    QString userName;//用户名称
    int authority;//用户相对应的权限

};

#endif // USERALIVE_H
