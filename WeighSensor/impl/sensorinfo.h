#ifndef SENSORINFO_H
#define SENSORINFO_H
#include <QString>
class SensorInfo
{
public:
    SensorInfo();

    int getId();
    void setId(int id);
    int getSensorId();
    void setSensorId(int sensorId);
    QString getProtocol();
    void setProtocol(QString protocol);
    QString getAddress();
    void setAddress(QString address);
    float getZeroIsn();
    void setZeroIsn(float zeroIsn);
private:
    int id;//id
    int sensorId;//传感器id
    QString protocol;//协议
    QString address;//地址
    float   zeroIsn;//传感器零点时的内码
    //float   corner;//传感器的角差系数

};

#endif // SENSORINFO_H
