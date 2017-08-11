#ifndef DATASTRUCT_H
#define DATASTRUCT_H
#define max 16

//typedef unsigned char INT8Uªª//ÎÞ·ûºÅ8Î»ÕûÐÍ±äÁ¿
//typedef signed short  INT16Sªª//ÓÐ·ûºÅ16Î»ÕûÐÍ±äÁ¿
//typedef unsigned int  INT32Uªª//ÎÞ·ûºÅ32Î»ÕûÐÍ±äÁ¿
//typedef float         FP32ªª
typedef unsigned char   INT8U;
typedef unsigned short  INT16S;
typedef unsigned int  INT32U;
typedef float    FP32;

//查询配置
typedef struct Query_Config{
           INT8U     state;// 0，不处于出厂配置状态
                           //1 还未配置完成
                           //2 配置完成
           INT8U     temp1;    //±žÓÃ
           INT8U     temp2;    //±žÓÃ
           INT8U     temp3;    //±žÓÃ
 }Config;

//5¡获取内码和相关实时状态
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

//6 获取计量板支持协议版本
typedef struct  Get_Protocal_Version
{
    INT8U     C_type;      //CÐÍÐ­ÒéµÄÖ§³ÖÐÔ:0:²»Ö§³Ö;1:Ö§³Ö
    INT8U     C_ext_type;  //CÐ­ÒéÀ©Õ¹±àºÅ
    INT8U     E_type;      //EÐÍÐ­ÒéµÄÖ§³ÖÐÔ:0:²»Ö§³Ö;1:Ö§³Ö
    INT8U     E_ext_type;  //EÐ­ÒéÀ©Õ¹±àºÅ
    INT8U     K_type;      //KÐÍÐ­ÒéµÄÖ§³ÖÐÔ:0:²»Ö§³Ö;1:Ö§³Ö
    INT8U     K_ext_type;  //KÐ­ÒéÀ©Õ¹±àºÅ
    INT8U     CAN_type;    //CANÐÍÐ­ÒéµÄÖ§³ÖÐÔ:0:²»Ö§³Ö;1:Ö§³Ö
    INT8U     CAN_ext_type;//CANÐ­ÒéÀ©Õ¹±àºÅ
}Protocal_Version;

//7 读取传感器满量程
typedef struct Get_Full_Weight_Sensor{
            INT8U  state;
            INT8U  temp1;
            INT8U  temp2;
            INT8U  temp3;   //±žÓÃ
            INT8U  CellState[max];//Ž«žÐÆ÷×ŽÌ¬ Õý³£or not
            INT32U  fullWeight[max]; //Ž«žÐÆ÷µÄÂúÁ¿³Ì
}Full_Weight_Sensor;

//8读取传感器角度
typedef struct Get_Sensor_Angle{
            INT8U  state;   //ÊýŸÝ×ŽÌ¬
            INT8U  temp1;
            INT8U  temp2;
            INT8U  temp3;   //±žÓÃ
            INT8U  cornerXState[max];//Ž«žÐÆ÷µÄXœÇ¶È×ŽÌ¬
            INT16S cornerXDate[max];//Ž«žÐÆ÷µÄXœÇ¶ÈÖµ
            INT8U  cornerYState[max];//Ž«žÐÆ÷µÄYœÇ¶È×ŽÌ¬
            INT16S cornerYDate[max];//Ž«žÐÆ÷µÄYœÇ¶ÈÖµ
}Sensor_Angle;

//9读取传感器温度
typedef struct Get_Sensor_Temperature{
            INT8U  state;
            INT8U  temp1;
            INT8U  temp2;
            INT8U  temp3;   //±žÓÃ
            INT8U  temperatureState[max];//Ž«žÐÆ÷ÎÂ¶È×ŽÌ¬
            INT16S  temperatureData[max]; //Ž«žÐÆ÷µÄÎÂ¶ÈÖµ
}Sensor_Temperature;

//10 读取传感器湿度
typedef struct Get_Sensor_Humidity{
            INT8U  state;
            INT8U  temp1;
            INT8U  temp2;
            INT8U  temp3;   //±žÓÃ
            INT8U  humidityState[max];//Ž«žÐÆ÷Êª¶È×ŽÌ¬
            INT16S  humidityData[max]; //Ž«žÐÆ÷µÄÊª¶ÈÖµ
}Sensor_Humidity;

//11 采集传感器电流
typedef struct Get_Sensor_Current{
            INT8U  state;
            INT8U  temp1;
            INT8U  temp2;
            INT8U  temp3;   //±žÓÃ
            INT8U  currentState[max];//Ž«žÐÆ÷µçÁ÷×ŽÌ¬
            INT16S  currentData[max]; //Ž«žÐÆ÷µÄµçÁ÷Öµ
}Sensor_Current;

//12 读取当前传感器ID号
typedef struct Get_Current_Sensor_ID{
            INT8U  state;
            INT8U  temp1;
            INT8U  temp2;
            INT8U  temp3;   //±žÓÃ
            INT8U  CellState[max];//Ž«žÐÆ÷×ŽÌ¬
            INT8U  IDData[max]; //Ž«žÐÆ÷µÄID
}Current_Sensor_ID;

//13 组称时搜索所有连接的传感器ID号
typedef struct Get_All_Link_Sensor_ID
{
    INT8U     state;     //0£ºÊýŸÝÕý³£
                        //1£ºÊýŸÝÕýÔÚ³õÊŒ»¯ÖÐ
                        //2£ºÎŽÆô¶¯³£¹æ²ÉŒ¯¹ŠÄÜ
    INT8U     type  ;    //Ž«žÐÆ÷Ð­ÒéÀàÐÍ   2£ºEÐÍ 3:KÐÍ 4£ºCANÐÍ
    INT8U     number;   //Ž«žÐÆ÷žöÊý
    INT8U     temp1;    //±žÓÃ
    INT32U    IDData [16];   //Ž«žÐÆ÷µÄIDºÅ
}All_Link_Sensor_ID;

//14 根据ID号与地址号设置传感器地址（返回的信息）
typedef struct Group_Set_Sensor_Address
{
    INT8U    number;   //Ž«žÐÆ÷žöÊý
    INT8U    temp1;    //±žÓÃ
    INT8U    temp2;    //±žÓÃ
    INT8U    state[16];  //Ž«žÐÆ÷µÄµØÖ·
}Group_Sensor_Address;

//15 组称时按地址扫描传感器信息
typedef struct Group_Get_Sensor_Info
{
    INT8U     State[16];    //Ž«žÐÆ÷×ŽÌ¬ 0£ºÎÞ  1£ºCÐÍ 2£ºEÐÍ 3:KÐÍ 4£ºCANÐÍ
    INT32U    IDData [16];      //Ž«žÐÆ÷µÄID
}Group_Sensor_Info;

//16 按地址给传感器加密
typedef struct Encrypt_Sensor_Address_R
{
    INT8U     number;   //Ž«žÐÆ÷žöÊý
    INT8U     temp1;    //±žÓÃ
    INT8U     temp2;    //±žÓÃ
    INT8U     temp3;    //±žÓÃ
    INT8U     State[16];    //Ž«žÐÆ÷×ŽÌ¬ 0£ºÍšÑ¶³öŽí   1£ºÕý³£  2:ÃÜÂë²»Í¬ÎÞ·šŒÓÃÜ
}Encrypt_Sensor_Address_R;





//启动常规采集
typedef struct Start_System_Formal{
            INT8U  number;   //Ž«žÐÆ÷žöÊý
            INT8U  type;     //Ž«žÐÆ÷Ð­ÒéÀàÐÍ
            INT8U  config;   //²ÉŒ¯ÊýŸÝµÄÅäÖÃ
            INT8U  temp;     //±žÓÃ
            INT32U password; //ÍšÑ¶ÃÜÂë
}Start_System_Formal;

//根据id号与地址号设置传感器地址（传感尚永的信息）
typedef struct Set_Address_Sensor{
            INT8U  type;   //Ž«žÐÆ÷Ð­ÒéÀàÐÍ
            INT8U  number; //Ž«žÐÆ÷žöÊý
            INT8U  temp1;  //±žÓÃ
            INT8U  temp2;  //±žÓÃ
            INT32U ID[16];//Ž«žÐÆ÷µÄIDºÅ
            INT8U  address[16];//Ž«žÐÆ÷µØÖ· ŸÉµØÖ·
}Set_Address_Sensor;

//按地址加密
 typedef struct Encrypt_Sensor_Address{
            INT8U     type  ; //Ž«žÐÆ÷Ð­ÒéÀàÐÍ   0£ºÎÞ  1£ºCÐÍ 2£ºEÐÍ 3:KÐÍ 4£ºCANÐÍ
            INT8U     number;   //Ž«žÐÆ÷žöÊý
            INT8U     temp1;    //±žÓÃ
            INT8U     temp2;    //±žÓÃ
            INT32U    password; //ÍšÑ¶ÃÜÂë
            INT8U     address[16]; //Ž«žÐÆ÷µØÖ·
}Encrypt_Sensor_Address;

typedef struct Init_Data{
    char passwd[128];
    unsigned char config;
    unsigned char flag;
}Init_Data;




//*****************************内码滤波参数******************************************/
#define TREND_UP 1  //上升
#define TREND_DOWN 0  //下降
typedef struct nodeTYPELUBO{
    FP32 OADBuff[2];  //最新缓冲区
    INT8U OADSCount;   //稳定计数范围
    FP32 FADBuff[40];  //滤波后AD缓冲区
    INT8U ADBCount;    //滤波后缓冲奇数
    INT8U ADTSCount;   //上升下降计数
    INT8U ADTState;     //上升下降状态
}TYPELUBO;

//int ConveydataToArray(INT8U* array,Convey_Data *p);
//void QT_cmd_initial(char*passwd,unsigned char config,unsigned char flag);


//*****************************计量相关参数******************************************/
#define NBUFF    16
#define Outtime  4
const INT8U  diagarrs[]=  {1,2,5,10,20,50,100};
const FP32  filter_step_arr1[5] ={0.8,0.825,0.9,0.92,0.95};//{0.8,0.825,0.85,0.875,0.9};//老的数值占的比例
const FP32  filter_step_arr2[5] ={0.2,0.175,0.1,0.08,0.05};//{0.2,0.175,0.15,0.125,0.1};//新的数值占的比例
const INT8U LuBo_arr[5]         ={14,18,28,32,40};//滤波缓区长度
const INT8U LuBo_OAD_arr[5]     ={8,10,15,15,20};//滤波缓区长度
const INT8U LuBo_holding_arr[5] ={8,10,15,15,20};//滤波爬坡保持长度
const INT8U LuBo_Remove_arr[5]  ={4,5,7,8,10};//当滤波爬坡条件满足时的替代数据长度
const FP32  LuBo_steedy_arr[5]  ={0.1,0.2,0.25,0.3,0.6};//判定爬坡范围

const FP32  PN_ZeroTrackAreaArrs[10]={ 0,0.5,1.0,1.5,2.0,2.5,3.0,3.5,4.0,4.5 };//零点跟踪范围
const FP32  PN_ZeroManualAreaArrs[6]={ 0,0.02,0.04,0.10,0.20,1.0 };//置零范围
const FP32  PN_ZeroStartAreaArrs[6]={ 0,0.02,0.04,0.10,0.20,1.0};//开机置零


//标定结构
struct DemarcateWeightSTR
 {
      INT8U   weight2mark   ;                                                   //多点标定方式
      INT32U  importData    ;                                                   //输入的重量值
      FP32    AD[3]          ;                                                   //当前各点内码
      FP32    weighData[2]   ;                                                   //标定重量值
      FP32    saveAD[2]      ;                                                   //用于保存的AD数据
      FP32    slop[2]        ;                                                   //用于保存标定的线性数据
 };

#endif // DATASTRUCT_H
