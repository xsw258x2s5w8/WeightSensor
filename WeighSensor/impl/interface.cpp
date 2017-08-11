#include "interface.h"

Interface::Interface()
{
}
int Interface::getInterfaceId()
{
    return interfaceId;
}
void Interface::setInterfaceId(int interfaceId)
{
    this->interfaceId = interfaceId;
}
QString Interface::getInterfaceName()
{
    return interfaceName;
}
void Interface::setInterfaceName(QString interfaceName)
{
    this->interfaceName = interfaceName;
}
