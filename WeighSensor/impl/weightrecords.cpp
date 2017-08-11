#include "weightrecords.h"

WeightRecords::WeightRecords()
{
    //类初始化
    userId = -1;
    ponderation = 0;
    complete = -1;
    monitorId = -1;
    deduction = 0;
    netWeight = 0;
    tare = 0;
    grossWeight = 0;
    spareWeight = 0;
}
int WeightRecords::getId()
{
    return id;
}
void WeightRecords::setId(int id)
{
    this->id = id;
}
int WeightRecords::getUserId()
{
    return userId;
}
void WeightRecords::setUserId(int userId)
{
    this->userId = userId;
}
QString WeightRecords::getDate1()
{
    return date1;
}
void WeightRecords::setDate1(QString date1)
{
    this->date1 = date1;
}
QString WeightRecords::getTime1()
{
    return time1;
}

void WeightRecords::setTime1(QString time1)
{
    this->time1 = time1;
}
QString WeightRecords::getDate2()
{
    return date2;
}
void WeightRecords::setDate2(QString date2)
{
    this->date2= date2;
}
QString WeightRecords::getTime2()
{
    return time2;
}

void WeightRecords::setTime2(QString time2)
{
    this->time2 = time2;
}
QString WeightRecords::getFactoryIn()
{
    return factoryIn;
}
void WeightRecords::setFactoryIn(QString factoryIn)
{
    this->factoryIn = factoryIn;
}
QString WeightRecords::getFactoryOut()
{
    return factoryOut;
}
void WeightRecords::setFactoryOut(QString factoryOut)
{
    this->factoryOut = factoryOut;
}
QString WeightRecords::getCarId()
{
    return carId;
}
void WeightRecords::setCarId(QString carId)
{
    this->carId = carId;
}
QString WeightRecords::getArtId()
{
    return artId;
}
void WeightRecords::setArtId(QString artId)
{
    this->artId = artId;
}
float WeightRecords::getGrossWeight()
{
    return grossWeight;
}
void WeightRecords::setGrossWeight(float grossWeight)
{
    this->grossWeight = grossWeight;
}
float WeightRecords::getTare()
{
    return tare;
}
void WeightRecords::setTare(float tare)
{
    this->tare = tare;
}
float WeightRecords::getNetWeight()
{
    return netWeight;
}
void WeightRecords::setNetWeight(float netWeight)
{
    this->netWeight = netWeight;
}

float WeightRecords::getDeduction()
{
    return deduction;
}
void WeightRecords::setDeduction(float deduction)
{
    this->deduction = deduction;
}
int WeightRecords::getMonitorId()
{
    return monitorId;
}
void WeightRecords::setMonitorId(int monitorId)
{
    this->monitorId = monitorId;
}
QString WeightRecords::getRemark()
{
    return remark;
}
void WeightRecords::setRemark(QString remark)
{
    this->remark = remark;
}
int WeightRecords::getPonderation()
{
    return ponderation;
}
void WeightRecords::setPonderation(int ponderation)
{
    this->ponderation = ponderation;
}
int WeightRecords::getComplete()
{
    return complete;
}
void WeightRecords::setComplete(int complete)
{
    this->complete = complete;
}
QString WeightRecords::getReserved1()
{
    return reserved1;
}
void WeightRecords::setReserved1(QString reserved1)
{
    this->reserved1 = reserved1;
}
QString WeightRecords::getReserved2()
{
    return reserved2;
}
void WeightRecords::setReserved2(QString reserved2)
{
    this->reserved2 = reserved2;
}
QString WeightRecords::getReserved3()
{
    return reserved3;
}
void WeightRecords::setReserved3(QString reserved3)
{
    this->reserved3 = reserved3;
}
QString WeightRecords::getReserved4()
{
    return reserved4;
}
void WeightRecords::setReserved4(QString reserved4)
{
    this->reserved4 = reserved4;
}
float WeightRecords::getSpareWeight()
{
    return spareWeight;
}
void WeightRecords::setSpareWeight(float spareWeight)
{
    this->spareWeight = spareWeight;
}
