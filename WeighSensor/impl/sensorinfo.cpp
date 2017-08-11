#include "sensorinfo.h"

SensorInfo::SensorInfo()
{
    id = -1;
}
int SensorInfo::getId()
{
    return id;
}
void SensorInfo::setId(int id)
{
    this->id = id;
}
int SensorInfo::getSensorId()
{
    return sensorId;
}
void SensorInfo::setSensorId(int sensorId)
{
    this->sensorId = sensorId;
}
QString SensorInfo::getProtocol()
{
    return protocol;
}
void SensorInfo::setProtocol(QString protocol)
{
    this->protocol = protocol;
}
QString SensorInfo::getAddress()
{
    return address;
}
void SensorInfo::setAddress(QString address)
{
    this->address = address;
}


void SensorInfo::setZeroIsn(float zeroIsn)
{
    this->zeroIsn=zeroIsn;
}


float SensorInfo::getZeroIsn()
{
    return zeroIsn;
}

