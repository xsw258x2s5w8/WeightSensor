#include "sensorisnthread.h"
#include<QDebug>
#include <QtGlobal>

SensorIsnThread::SensorIsnThread()
{
    //模拟数据的初始化,实际直接发命令获得
   // state_Inode.state=0;//0 数据正常
  //  for(int i=0;i<16;i++){
  //      state_Inode.CellState[i].isn=65.35;
  //  }
    //初始化
    threadStopFlag=false;
    SensorNumber=0;

    //启动常规采集的配置。。。。。。。。。。。。。。。。。。。(需在设置传感器个数的函数里启动常规采集比较好)

    //模拟数据的初始化,实际直接发命令获得  获得内码的命令。。。。。。。。。。。。。。。。。。
    state_Inode.state=0;//0 数据正常
    for(int i=0;i<16;i++){
        state_Inode.CellState[i].isn=65.35*(qrand()%100);
        state_Inode.CellState[i].state0=0xFF;
        state_Inode.CellState[i].state1=0xFF;
    }



}


void SensorIsnThread::run()
{


    //循环访问数据，不满足条件跳出
    while(!threadStopFlag){
        //无限制读数据
        float temp=state_Inode.CellState[SensorNumber-1].isn;
        for(int i=SensorNumber-1;i>0;i--){
            state_Inode.CellState[i].isn=state_Inode.CellState[i-1].isn;
        }
        state_Inode.CellState[0].isn=65.35*(qrand()%100);;

        msleep(500);
        emit SendISN(state_Inode,SensorNumber); //发送读取到的数据
        qDebug()<<"读取内码线程中："<<state_Inode.CellState[0].state0;

       //QByteArray *s=state_Inode.CellState[0].state0;
       // qDebug()<<"字节数据"<<s;
    }

   // int di=0;
    //cout<<di;
}


void SensorIsnThread::close()
{
    threadStopFlag=true;
    qDebug()<<"关闭线程函数："<<threadStopFlag;
    this->quit();
    this->wait();
}


void SensorIsnThread::SetSensorNumber(int number)
{
    SensorNumber=number;
}


