#include "steedythread.h"
#include<QDebug>
#include <QtGlobal>

SteedyThread::SteedyThread()
{
    //初始化
    threadStopFlag=false;
    threadRecvFlag=false;//刚开始不触发，收到数据后触发
    currentAllISNOriginal=0;
    currentAllISN=0;

    GSlobo.ADBCount=0;
}


void SteedyThread::run()
{

    //循环访问数据，不满足条件跳出
    while(!threadStopFlag){
        if(threadRecvFlag){//这个标志位确保第一次获得数据
            msleep(500);


            //添加所有内码
            Weight_AddAllIsn(1);

            //对内码进行滤波
            isn_Lvbo(2);

            //稳定计数
            Steedy_Fun();

            //发送数据
            if(steadyCount>3){//稳定
                emit SendSteedyFlag("稳定",currentAllISN,state_Inode); //发送读取到的数据
            }else{
                emit SendSteedyFlag("不稳定",currentAllISN,state_Inode);
            }

            qDebug()<<"判断稳定线程中："<<state_Inode.CellState[0].isn;
            qDebug()<<"判断稳定线程中原始总量："<<currentAllISNOriginal;
            qDebug()<<"判断稳定线程中进行滤波之后总量："<<currentAllISN;
        }
//        threadRecvFlag=false;//执行完关闭

    }
}


void SteedyThread::close()
{
    threadStopFlag=true;
    qDebug()<<"关闭线程函数："<<threadStopFlag;
    this->quit();
    this->wait();
}



void SteedyThread::slotGetISN(State_Inode state_Inode,int sensorNumber)
{
    this->state_Inode=state_Inode;
    this->sensorNumber=sensorNumber;
    threadRecvFlag=true;//更新收到数据标志位
    qDebug()<<"我已经获取数据了啊啊啊啊啊啊啊"<<this->sensorNumber;
}


void SteedyThread::Weight_AddAllIsn(int type)
{
    //type=0,1;  角叉系数为1，角叉系数为传感器的角叉

    currentAllISNOriginal=0;//每次都要初始化为0

    float temp_corner;
    if(type==1){
        temp_corner=1.0;
    }

    for(int i=0;i<sensorNumber;i++){
        currentAllISNOriginal+=state_Inode.CellState[i].isn*temp_corner;
    }
    qDebug()<<"..........................................";
    qDebug()<<"得到的原始重量："<<currentAllISNOriginal;
    qDebug()<<"..........................................";
}


void SteedyThread::isn_Lvbo(int filtType)
{
    INT8U i,C_temp0;
    FP32  F_temp,F_temp0,F_temp1;

    INT8U OADBufflength=0;  //原始AD缓冲区长度
    INT8U ADBufflength=0;   //1阶滤波后的AD缓冲区长度

    FP32 diag_ad=0;  //一个分度对应的内码
    FP32 OAD_max_temp=0;      //最小值
    FP32 OAD_min_temp=0;      //最小值
    FP32 OAD_average_temp=0;  //平均值

    //1个分度对应的内码
    diag_ad=12;//这边需要查数据库 获得 线性和分度值。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。
    if(filtType==0){
        //初始化
        if(GSlobo.ADBCount<NBUFF){
           for(i=0;i<NBUFF;i++){
               GSlobo.OADBuff[i] = currentAllISNOriginal;
           }
           GSlobo.ADBCount  = NBUFF;
           GSlobo.ADTSCount = 0;
           currentAllISN= currentAllISNOriginal;
           qDebug()<<"..........................................";
           qDebug()<<"初始化的"<<currentAllISNOriginal;
           qDebug()<<"..........................................";
           return ;

        //其他
        }else{
            //计数大于15
            if(GSlobo.ADTSCount >15){  //判断是否稳定下来了，并对缓存区更改。以及对滤波后的总内码进行赋值
                    F_temp =qAbs(currentAllISNOriginal - currentAllISN);
                    if(F_temp<(diag_ad/(FP32)(2))){//0.5d对应的内码
                        for(i=0;i<NBUFF;i++){
                            GSlobo.OADBuff[i] = currentAllISNOriginal;
                        }
                        GSlobo.ADTSCount = 0;
                    }

                    currentAllISN= currentAllISNOriginal;
                    qDebug()<<"..........................................";
                    qDebug()<<"这是大于15情况";
                    qDebug()<<"ADTScount:"<<GSlobo.ADTSCount;
                    qDebug()<<"currentALLISN:"<<currentAllISN;
                    qDebug()<<"currentALLISNOriginal"<<currentAllISNOriginal;
                    qDebug()<<"..........................................";
                     return;
            }

            //计数大于10
            if(GSlobo.ADTSCount >10) {//没有影响至原始码缓存区?       对滤波后的总内码进行赋值
                currentAllISN = currentAllISNOriginal;
                GSlobo.ADTSCount ++;

                qDebug()<<"..........................................";
                qDebug()<<"这是大于10的情况";
                qDebug()<<"ADTScount:"<<GSlobo.ADTSCount;
                qDebug()<<"currentALLISN:"<<currentAllISN;
                qDebug()<<"currentALLISNOriginal"<<currentAllISNOriginal;
                qDebug()<<"..........................................";
                return;
            }

            //其他情况
            F_temp = qAbs(currentAllISNOriginal - currentAllISN);
            if(F_temp>(diag_ad/(FP32)(2))){//变化范围大    为什么一个分度内码的一半就算变化范围小？ 这里应该是变换范围大
                GSlobo.ADTSCount++;
                if(GSlobo.ADTSCount>Outtime){
                    currentAllISN = currentAllISNOriginal;
                    for(i=0;i<NBUFF;i++){
                        GSlobo.OADBuff[i]=currentAllISNOriginal;
                    }
                }

                qDebug()<<"..........................................";
                qDebug()<<"这是小于10的大于情况";
                qDebug()<<"ADTScount:"<<GSlobo.ADTSCount;
                qDebug()<<"currentALLISN"<<currentAllISN;
                qDebug()<<"currentALLISNOriginal"<<currentAllISNOriginal;
                qDebug()<<"..........................................";
                return;
             }else{			 //F_temp 小于 一个分度内码的一半，只对缓存区的第一位做修改，并取平均值
                 GSlobo.ADTSCount = 0;
                 for(i=(NBUFF-1);i>0;i--){
                       GSlobo.OADBuff[i] = GSlobo.OADBuff[i-1];
                 }
                 GSlobo.OADBuff[0] = currentAllISNOriginal;
                 OAD_average_temp =0;
                 for(i=0;i<NBUFF;i++){
                      OAD_average_temp += GSlobo.OADBuff[i];//总和
                 }
                 OAD_average_temp = OAD_average_temp/NBUFF;
                 currentAllISN = OAD_average_temp;   //得到滤波后的重量内码

                 qDebug()<<"..........................................";
                 qDebug()<<"这是小于10的小于情况";
                 qDebug()<<"ADTScount:"<<GSlobo.ADTSCount;
                 qDebug()<<"currentALLISN"<<currentAllISN;
                 qDebug()<<"currentALLISNOriginal"<<currentAllISNOriginal;
                 qDebug()<<"OAD_average_temp"<<OAD_average_temp;
                 qDebug()<<"..........................................";
                 return ;
             }

        }
    }


    //滤波的其他几种方式，主要不同-------------------
    //根据滤波方式选择 滤波缓冲区长度
      ADBufflength  = LuBo_arr[filtType];    //filtype是滤波方式  14，18，28，32，40
      OADBufflength = LuBo_OAD_arr[filtType];  //8，10，15，15，20

      if(GSlobo.ADBCount!=ADBufflength){//初始化缓冲区
        for(i=0;i<OADBufflength;i++){  //滤波前的  8
                GSlobo.OADBuff[i] = currentAllISNOriginal;
         }
        for(i=0;i<ADBufflength;i++){   //滤波后的		14
                  GSlobo.FADBuff[i] = currentAllISNOriginal;
         }
         GSlobo.ADTState  = TREND_UP;//上升下降状态
         GSlobo.ADTSCount = 0;
         GSlobo.ADBCount  = ADBufflength;
      }

    //移位进入最新原始AD缓冲区  //数组向右移一位
    for(i=(OADBufflength-1);i>0;i--){
        GSlobo.OADBuff[i] =  GSlobo.OADBuff[i-1];
    }
    GSlobo.OADBuff[0] = currentAllISNOriginal;

    //一阶滤波最新滤波值=此缓冲区[1]*比列+最新AD值*（1-比列）
    for(i=0;i<(ADBufflength-1);i++){
        GSlobo.FADBuff[(ADBufflength-1)-i] = GSlobo.FADBuff[(ADBufflength-2)-i];
    }
    GSlobo.FADBuff[0]=(GSlobo.FADBuff[1]*filter_step_arr1[filtType]+currentAllISNOriginal*filter_step_arr2[filtType]);

    //原始内码处理=================
    //取出、在OADBuff中的平均值
      OAD_average_temp =0;
      for(i=0;i<OADBufflength;i++){
         OAD_average_temp += GSlobo.OADBuff[i];//总和
      }

      OAD_max_temp = GSlobo.OADBuff[0];
      OAD_min_temp = GSlobo.OADBuff[0];
      for(i=1;i<OADBufflength;i++){
         if(OAD_max_temp<GSlobo.OADBuff[i]){//取最大值
            OAD_max_temp = GSlobo.OADBuff[i];
         }
         if(OAD_min_temp>GSlobo.OADBuff[i]){//取最小值
            OAD_min_temp = GSlobo.OADBuff[i];
         }
      }
      OAD_average_temp = OAD_average_temp-OAD_max_temp-OAD_min_temp;
      OAD_average_temp = OAD_average_temp /(OADBufflength-2);

    //实现稳定值快速处理
      //优点:对于静态比较有效，如砝码检定。
      //缺点:如果内码本身很稳定

      F_temp0 = OAD_max_temp -OAD_min_temp;
      if(F_temp0<(diag_ad/(FP32)5.0)){  //如果大于 平均值就没有更改FADBuff了
           C_temp0 = ADBufflength/2;
           for(i=ADBufflength-1;i>C_temp0;i--){
                    GSlobo.FADBuff[i] = GSlobo.FADBuff[i-C_temp0];
           }

           for(i=0;i<(C_temp0+1);i++){   //前一半保存平均值//后一半保存前面一半的数据
                    GSlobo.FADBuff[i] = OAD_average_temp;//FADBuff[0];
           }
          GSlobo.ADTState = TREND_UP;//上升下降状态
          GSlobo.ADTSCount = 0;
      }

    //===========状态处理==============
    //TREND_UP部分
      if(GSlobo.ADTState == TREND_UP){
             if(OAD_average_temp<(currentAllISN+(LuBo_steedy_arr[filtType]*diag_ad))){
                  GSlobo.ADTSCount = 1;
                  GSlobo.ADTState  = TREND_DOWN;
               } else{  //大于
                       GSlobo.ADTSCount++;
             }
    //TREND_DOWN部分
     }else{
            if(OAD_average_temp>(currentAllISN-(FP32)LuBo_steedy_arr[filtType]*diag_ad)){
                  GSlobo.ADTSCount =1;
                  GSlobo.ADTState = TREND_UP;
            }else{   //小于
                  GSlobo.ADTSCount++;
            }
     }

    //=====end of 状态处理================
      if(GSlobo.ADTSCount>LuBo_holding_arr[filtType]){   //8，10，15，15，20
           GSlobo.ADTSCount =LuBo_holding_arr[filtType];
              // GSlobo.ADTState = 0;
           C_temp0 = LuBo_Remove_arr[filtType];  //4，5，7，8，10
           for(i=ADBufflength-1;i>C_temp0;i--){
                    GSlobo.FADBuff[i] = GSlobo.FADBuff[i-C_temp0];
           }
           for(i=0;i<(C_temp0+1);i++) {
                     GSlobo.FADBuff[i] = OAD_average_temp;//GSlobo.FADBuff[0];//FADBuff[0];
           }
      }

       //去最大与最小值再进行平均得总滤波值
       F_temp =0;
       for(i=0;i<ADBufflength;i++){
             F_temp += GSlobo.FADBuff[i];//更新数据缓冲区
       }

      //去掉最大值
       F_temp0 = GSlobo.FADBuff[0];
       F_temp1 = GSlobo.FADBuff[0];
       for(i=1;i<ADBufflength;i++){
          if(F_temp0<GSlobo.FADBuff[i]){//取最小值
                F_temp0 = GSlobo.FADBuff[i];
          }
            if(F_temp1>GSlobo.FADBuff[i]){//取最小值
                     F_temp1 = GSlobo.FADBuff[i];
            }
       }
       F_temp =F_temp-F_temp0-F_temp1;
       currentAllISN= F_temp/(ADBufflength-2);

}


void SteedyThread::Steedy_Fun()
{
      float F_temp;
      float I_temp; //用于判断稳定的分量大小
      INT8U i;
      FP32 max_temp;      //最大值
      FP32 min_temp;      //最小值

      //确定稳定分量
      float fullWeight=3000;
      if(fullWeight/diagarrs[1]>5000){//读满量程，分度值...................................................
         I_temp=(signed long)fullWeight/5000;
      }else{
         I_temp=diagarrs[1];
      }

      I_temp=10000;//先自己模拟 为了让数据模拟稳定。。。。。。。。。。。。。。。。

      //更新判稳依据数据
      for(i=1;i<11;i++){
        steadyOldGrossISN[11-i] =steadyOldGrossISN[11-i-1];
      }
      steadyOldGrossISN[0] = currentAllISN;

      //取最大值和最小值
      max_temp = steadyOldGrossISN[0];
      min_temp = steadyOldGrossISN[0];

      for(i=1;i<10;i++){//只判断10个缓冲区数据
         if(max_temp<steadyOldGrossISN[i]){//取最小值
            max_temp = steadyOldGrossISN[i];
         }
         if(min_temp>steadyOldGrossISN[i]){//取最小值
            min_temp = steadyOldGrossISN[i];
         }
      }
      //============================================================================
      F_temp = max_temp - min_temp;
      qDebug()<<"..........................................";
      qDebug()<<"最大与最小的差："<<F_temp;
      qDebug()<<"..........................................";
      if((F_temp)<I_temp){
        if(steadyCount<10){
            steadyCount = 10;
         }else{
            steadyCount++;
            if(steadyCount>250){
              steadyCount = 250;
            }
         }
      }else{
          steadyCount = 0;
      }
}
