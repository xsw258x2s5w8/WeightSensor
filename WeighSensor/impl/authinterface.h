#ifndef AUTHINTERFACE_H
#define AUTHINTERFACE_H

class AuthInterface
{
public:
    AuthInterface();
    int getId();
    void setId(int id);
    int getAuthority();
    void setAuthority(int authority);
    int getInterfaceId();
    void setInterfaceId(int interfaceId);
private:
    int id;
    int authority;//权限值
    int interfaceId;//界面id
};

#endif // AUTHINTERFACE_H
