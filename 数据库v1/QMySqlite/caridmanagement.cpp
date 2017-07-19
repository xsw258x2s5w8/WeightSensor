#include "caridmanagement.h"

CarIdManagement::CarIdManagement()
{    
    id=NULL;
}
int CarIdManagement::getId()
{
    return id;
}
void CarIdManagement::setId(int id)
{
    this->id = id;
}
QString CarIdManagement::getCarId()
{
    return carId;
}
void CarIdManagement::setCarId(QString carId)
{
    this->carId = carId;
}
float CarIdManagement::getTare()
{
    return tare;
}
void CarIdManagement::setTare(float tare)
{
    this->tare = tare;
}


