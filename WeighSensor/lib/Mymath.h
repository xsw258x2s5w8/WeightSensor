#ifndef MYMATH_H
#define MYMATH_H
#include "DataStruct.h"
QStringList getSensorError(State_Inode state_Inode){

}

#endif // MYMATH_H

typedef struct  Get_State_Inode{
            INT8U  state;   //数据状态
            INT8U  temp1;   //±žÓÃ
            INT8U  temp2;   //±žÓÃ
            INT8U  temp3;   //±žÓÃ
            struct IsnSensor{  //传感器内码
                        FP32   isn;    //传感器内码
                        INT8U  state0; //状态字0
                        INT8U  state1; //状态字1
                        INT8U  temp4;  //±žÓÃ
                        INT8U  temp5;  //±žÓÃ
            }CellState[max];

}State_Inode;
