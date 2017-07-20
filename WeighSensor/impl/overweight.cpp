#include "overweight.h"

overWeight::overWeight()
{
    id=NULL;
}

int overWeight::getId()
{
    return id;
}
void overWeight::setId(int id)
{
    this->id=id;
}
QString overWeight::getDate()
{
    return date;
}
void overWeight::setDate(QString date)
{
    this->date=date;
}
QString overWeight::getTime()
{
    return time;
}
void overWeight::setTime(QString time)
{
    this->time=time;
}
float overWeight::getOverweight()
{
    return overweight;
}
void overWeight::setOverweight(float overweight)
{
    this->overweight=overweight;
}
