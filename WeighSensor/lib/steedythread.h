#ifndef STEEDYTHREAD_H
#define STEEDYTHREAD_H
//根据内码 计算稳定否
#include "DataStruct.h"
#include <QThread>



class SteedyThread:public QThread
{
Q_OBJECT

public:
    SteedyThread();
    void close();
protected:
    void run();

    void Weight_AddAllIsn(int type);//添加所有传感器的内码
    void isn_Lvbo(int filtType); //对内码进行滤波
    void Steedy_Fun();//计算数据稳定   调地址界面
    //void SetSensorNumber(int number);

signals:
    void SendSteedyFlag(QString str,float currentAllISN,State_Inode state_Inode);

public slots:
    void slotGetISN(State_Inode state_Inode,int sensorNumber);//用于接收从读取内码线程中传来的信息

private:
    int sensorNumber;//传感器个数
    State_Inode state_Inode;
    volatile bool threadStopFlag;//控制线程
    volatile bool  threadRecvFlag;//是否收到数据

    //判稳时所用到的对比值
    float  steadyOldGrossISN[11];
    int steadyCount;  //稳定计数 如果稳定大于3，表示数据稳定

    float   currentAllISNOriginal;                                               //当前传感器滤波前总内码(已角差处理)
    float   currentAllISN;                                                       //当前传感器总内码(已角差处理)

    TYPELUBO GSlobo;//滤波参数错误提示
};

#endif // STEEDYTHREAD_H
