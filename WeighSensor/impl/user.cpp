#include "user.h"

User::User()
{
}
int User::getUserId()
{
    return userId;
}
void User::setUserId(int userId)
{
    this->userId = userId;
}
QString User::getUserName()
{
    return userName;
}
void User::setUserName(QString userName)
{
    this->userName = userName;
}
QString User::getPassword()
{
    return password;
}
void User::setPassword(QString password)
{
    this->password = password;
}
int User::getAuthority()
{
    return authority;
}
void User::setAuthority(int authority)
{
    this->authority = authority;
}
