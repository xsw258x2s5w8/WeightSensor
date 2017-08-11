#include "instinfo.h"

InstInfo::InstInfo()
{
}
int InstInfo::getId()
{
    return id;
}
void InstInfo::setId(int id)
{
    this->id = id;
}
QString InstInfo::getVersion()
{
    return version;
}
void InstInfo::setVersion(QString version)
{
    this->version = version;
}
QString InstInfo::getMicrType()
{
    return micrType;
}
void InstInfo::setMicrType(QString micrType)
{
    this->micrType = micrType;
}
QString InstInfo::getInsId()
{
    return insId;
}
void InstInfo::setInsId(QString insId)
{
    this->insId = insId;
}
QString InstInfo::getCustInfo()
{
    return custInfo;
}
void InstInfo::setCustInfo(QString custInfo)
{
    this->custInfo = custInfo;
}

