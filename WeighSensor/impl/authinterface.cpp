#include "authinterface.h"

AuthInterface::AuthInterface()
{

}

int AuthInterface::getId()
{
    return id;
}
void AuthInterface::setId(int id)
{
    this->id = id;
}
int AuthInterface::getAuthority()
{
    return authority;
}
void AuthInterface::setAuthority(int authority)
{
    this->authority = authority;
}
int AuthInterface::getInterfaceId()
{
    return interfaceId;
}
void AuthInterface::setInterfaceId(int interfaceId)
{
    this->interfaceId = interfaceId;
}
