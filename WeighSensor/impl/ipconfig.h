#ifndef IPCONFIG_H
#define IPCONFIG_H
#include <QString>
class IpConfig
{
public:
    IpConfig();
    int getId();
    void  setId(int id);
    QString getIp();
    void setIp(QString ip);
    QString getSubnetWay();
    void setSubnetWay(QString subnetWay);
    void setGateWay(QString gateWay);
    QString getGateWay();
    QString getDns();
    void setDns(QString dns);
private:
    int id;//id
    QString ip;//ip地址
    QString subnetWay;//子网掩码
    QString gateWay;//网关
    QString dns;//dns
};

#endif // IPCONFIG_H
