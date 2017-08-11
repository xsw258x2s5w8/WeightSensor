#include "analysissensordata.h"

AnalysisSensorData::AnalysisSensorData()
{
}


void AnalysisSensorData::Analysis(State_Inode state_Inode)
{
    //保存本来数据
    this->state_Inode=state_Inode;

    //传感器主状态判断
    if(state_Inode.state==0){
        state="数据正常";
    }else if(state_Inode.state==1){
        state="数据正在初始化中";
    }else if(state_Inode.state==2){
        state="未启动常规采集功能";
    }

    //每个装感器状态判断
    for(int i=0;i<16;i++){
        //状态0分析
        AnalysisState0(state_Inode,i);

        //状态1分析
        AnalysisState1(state_Inode,i);
    }


}


void AnalysisSensorData::AnalysisState0(State_Inode state_Inode,int i)
{
    //第一位
    if((state_Inode.CellState[i].state0>>0)&1==1){
        state0[i].append("备用正确1");
    }else{
        state0[i].append("备用错误1");
    }

    //第二位
    if((state_Inode.CellState[i].state0>>1)&1==1){
        state0[i].append("备用正确2");
    }else{
        state0[i].append("备用错误2");
    }

    //第三位
    if((state_Inode.CellState[i].state0>>2)&1==1){
        state0[i].append("备用正确3");
    }else{
        state0[i].append("备用错误3");
    }

    //第四位
    if((state_Inode.CellState[i].state0>>3)&1==1){
        state0[i].append("备用正确4");
    }else{
        state0[i].append("备用错误4");
    }

    //第五位
    if((state_Inode.CellState[i].state0>>4)&1==1){
        state0[i].append("备用正确5");
    }else{
        state0[i].append("备用错误5");
    }

    //第六位
    if((state_Inode.CellState[i].state0>>5)&1==1){
        state0[i].append("通讯密码正常");
    }else{
        state0[i].append("通讯密码错误");
    }

    //第七位
    if((state_Inode.CellState[i].state0>>6)&1==1){
        state0[i].append("备用正确");
    }else{
        state0[i].append("备用错误");
    }

    //第八位
    if((state_Inode.CellState[i].state0>>7)&1==1){
        state0[i].append("物理通讯正常");
    }else{
        state0[i].append("物理通讯错误");
    }
}


void AnalysisSensorData::AnalysisState1(State_Inode state_Inode,int i)
{
    //第一位
    if((state_Inode.CellState[i].state1>>0)&1==1){
        state1[i].append("AI检测正常");
    }else{
        state1[i].append("AI检测异常");
    }

    //第二位
    if((state_Inode.CellState[i].state1>>1)&1==1){
        state1[i].append("气密性正常");
    }else{
        state1[i].append("气密性异常");
    }

    //第三位
    if((state_Inode.CellState[i].state1>>2)&1==1){
        state1[i].append("角度正常");
    }else{
        state1[i].append("角度异常");
    }

    //第四位
    if((state_Inode.CellState[i].state1>>3)&1==1){
        state1[i].append("湿度正常");
    }else{
        state1[i].append("湿度异常");
    }

    //第五位
    if((state_Inode.CellState[i].state1>>4)&1==1){
        state1[i].append("温度正常");
    }else{
        state1[i].append("温度异常");
    }

    //第六位
    if((state_Inode.CellState[i].state1>>5)&1==1){
        state1[i].append("备用正常");
    }else{
        state1[i].append("备用错误");
    }

    //第七位
    if((state_Inode.CellState[i].state1>>6)&1==1){
        state1[i].append("AD芯片正常");
    }else{
        state1[i].append("AD芯片死机");
    }

    //第八位
    if((state_Inode.CellState[i].state1>>7)&1==1){
        state1[i].append("AD信号合理");
    }else{
        state1[i].append("AD信号超出范围");
    }
}
