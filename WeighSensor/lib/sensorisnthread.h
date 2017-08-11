#ifndef SENSORISNTHREAD_H
#define SENSORISNTHREAD_H
//读取传感器内码的线程,这里不考虑处理
#include "DataStruct.h"
#include <QThread>
#include <QLabel>



class SensorIsnThread:public QThread
{
Q_OBJECT

public:
    SensorIsnThread();
    void close();
    void SetSensorNumber(int number);

protected:
    void run();
signals:
    void SendISN(State_Inode state_Inode,int number);

private:
    int SensorNumber;//传感器个数
    State_Inode state_Inode;
    volatile bool threadStopFlag;//控制线程


};

#endif // SENSORISNTHREAD_H
