#include "ipconfig.h"

IpConfig::IpConfig()
{

}
int IpConfig::getId()
{
    return id;
}
void  IpConfig::setId(int id)
{
    this->id = id;
}
QString IpConfig::getIp()
{
    return ip;
}
void IpConfig::setIp(QString ip)
{
    this->ip = ip;
}
QString IpConfig::getSubnetWay()
{
    return subnetWay;
}
void IpConfig::setSubnetWay(QString subnetWay)
{
    this->subnetWay = subnetWay;
}
QString IpConfig::getGateWay()
{
    return gateWay;
}
void IpConfig::setGateWay(QString gateWay)
{
    this->gateWay = gateWay;
}
QString IpConfig::getDns()
{
    return dns;
}
void IpConfig::setDns(QString dns)
{
    this->dns = dns;
}
