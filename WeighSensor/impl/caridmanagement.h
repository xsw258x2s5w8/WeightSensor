#ifndef CARIDMANAGEMENT_H
#define CARIDMANAGEMENT_H
#include <QString>
class CarIdManagement
{
public:
    CarIdManagement();
    int getId();
    void setId(int id);
    QString getCarId();
    void setCarId(QString carId);
    float getTare();
    void setTare(float tare);
private:
    int id;
    QString carId;//车号
    float tare;//皮重
};

#endif // CARIDMANAGEMENT_H
