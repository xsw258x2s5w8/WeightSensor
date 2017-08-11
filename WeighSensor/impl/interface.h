#ifndef INTERFACE_H
#define INTERFACE_H
#include <QString>
class Interface
{
public:
    Interface();
    int getInterfaceId();
    void setInterfaceId(int interfaceId);
    QString getInterfaceName();
    void setInterfaceName(QString interfaceName);
private:
    int interfaceId;//界面id
    QString interfaceName;//界面名称
};

#endif // INTERFACE_H
