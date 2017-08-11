#ifndef ANALYSISSENSORDATA_H
#define ANALYSISSENSORDATA_H
#include "DataStruct.h"
#include<QString>
#include<QStringList>
//用于解析从传感器内码指令获得的数据

class AnalysisSensorData
{
public:
    AnalysisSensorData();

    void Analysis(State_Inode state_Inode); //用于对传过来的数据解析

private:
    void AnalysisState0(State_Inode state_Inode,int i); //对state0分析
    void AnalysisState1(State_Inode state_Inode,int i); //对state1 分析

public:
    State_Inode state_Inode;
    QString state;  //状态
    QStringList state0[16]; //状态0
    QStringList state1[16];  //状态1的信息
};

#endif // ANALYSISSENSORDATA_H
