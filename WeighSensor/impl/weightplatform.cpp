#include "weightplatform.h"

WeightPlatform::WeightPlatform()
{
    wpfmId = -1;
    scale = 0;
    decimalPlaces = 0;
    filterMethod = 0;
    tradeModel = 0;
    subZero = 0;
    zeroTrack = 0;
    manualZero = 0;
    turnonZero = 0;
    measurement = 0;
    fullRange = 0;
    switchScale1 = 0;
    switchScale2 = 0;
    emptyScale = 0;
    firstThread = 0;
    secondThread = 0;
    loadPoint = 0;
}
int WeightPlatform::getWpfmId()
{
    return wpfmId;
}
void WeightPlatform::setWpfmId(int wpfmId)
{
    this->wpfmId = wpfmId;
}
int WeightPlatform::getScale()
{
    return scale;
}
void WeightPlatform::setScale(int scale)
{
    this->scale = scale;
}
int WeightPlatform::getDecimalPlaces()
{
    return decimalPlaces;
}
void WeightPlatform::setDecimalPlaces(int decimalPlaces)
{
    this->decimalPlaces = decimalPlaces;
}
int WeightPlatform::getFilterMethod()
{
    return filterMethod;
}
void WeightPlatform::setFilterMethod(int filterMethod)
{
    this->filterMethod = filterMethod;
}
int WeightPlatform::getTradeModel()
{
    return tradeModel;
}
void WeightPlatform::setTradeModel(int tradeModel)
{
    this->tradeModel = tradeModel;
}
int WeightPlatform::getSubZero()
{
    return subZero;
}
void WeightPlatform::setSubZero(int subZero)
{
    this->subZero = subZero;
}
int WeightPlatform::getZeroTrack()
{
    return zeroTrack;
}
void WeightPlatform::setZeroTrack(int zeroTrack)
{
    this->zeroTrack = zeroTrack;
}
int WeightPlatform::getManualZero()
{
    return manualZero;
}
void WeightPlatform::setManualZero(int manualZero)
{
    this->manualZero = manualZero;
}
int WeightPlatform::getTurnonZero()
{
    return turnonZero;
}
void WeightPlatform::setTurnonZero(int turnonZero)
{
    this->turnonZero = turnonZero;
}
int WeightPlatform::getMeasurement()
{
    return measurement;
}
void WeightPlatform::setMeasurement(int measurement)
{
    this->measurement = measurement;
}
float WeightPlatform::getFullRange()
{
    return fullRange;
}
void WeightPlatform::setFullRange(float fullRange)
{
    this->fullRange = fullRange;
}
float WeightPlatform::getSwitchScale1()
{
    return switchScale1;
}
void WeightPlatform::setSwitchScale1(float switchScale1)
{
    this->switchScale1 = switchScale1;
}
float WeightPlatform::getSwitchScale2()
{
    return switchScale2;
}
void WeightPlatform::setSwitchScale2(float switchScale2)
{
    this->switchScale2 = switchScale2;
}
float WeightPlatform::getEmptyScale()
{
    return emptyScale;
}
void WeightPlatform::setEmptyScale(float emptyScale)
{
    this->emptyScale = emptyScale;
}
float WeightPlatform::getFirstThread()
{
    return firstThread;
}
void WeightPlatform::setFirstThread(float firstThread)
{
    this->firstThread = firstThread;
}
float WeightPlatform::getSecondThread()
{
    return secondThread;
}
void WeightPlatform::setSecondThread(float secondThread)
{
    this->secondThread = secondThread;
}
float WeightPlatform::getLoadPoint()
{
    return loadPoint;
}
void WeightPlatform::setLoadPoint(float loadPoint)
{
    this->loadPoint = loadPoint;
}


float WeightPlatform::getLoadPoint2()
{
    return loadPoint2;
}


void WeightPlatform::setLoadPoint2(float loadPoint)
{
     this->loadPoint2 = loadPoint;
}
