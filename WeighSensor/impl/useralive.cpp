#include "useralive.h"

UserAlive::UserAlive()
{
}
int UserAlive::getId()
{
    return id;
}
void UserAlive::setId(int id)
{
    this->id = id;
}
int UserAlive::getUserId()
{
    return userId;
}
void UserAlive::setUserId(int userId)
{
    this->userId = userId;
}
QString UserAlive::getUserName()
{
    return userName;
}
void UserAlive::setUserName(QString userName)
{
    this->userName = userName;
}
int UserAlive::getAuthority()
{
    return authority;
}
void UserAlive::setAuthority(int authority)
{
    this->authority = authority;
}
