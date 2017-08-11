#ifndef BIAODING_H
#define BIAODING_H
#include "lib/sensorisnthread.h"
#include "lib/steedythread.h"
#include <QWidget>
#include "impl/weightplatform.h"
#include "impl/weightplatformimpl.h"
#include "impl/sensorinfo.h"  //主要是为了保存 标定零点时各个传感器的内码
#include "impl/sensorinfoimpl.h"

namespace Ui {
class Biaoding;
}

class Biaoding : public QWidget
{
    Q_OBJECT
    
public:
    explicit Biaoding(QWidget *parent = 0);
    void PrepareData();//查数据库准备数据
    void saveZeroIsn();//保存零点内码
    ~Biaoding();
    
private:
    Ui::Biaoding *ui;

private:
    SensorIsnThread sensorIsnThread;
    SteedyThread steedyThread;

    //DemarcateWeightSTR demarcateWeightSTR;//标定的参数
    State_Inode state_Inode;  //保存零点内码的信息
    float currentAllISN;  //滤波后的内码，从steedyThread传过来

    WeightPlatformImpl weightPlatformImpl;//秤台参数数据库接口
    WeightPlatform weightPlatform;


public slots:
    void returnIndex();//主页
    void returnPage();//返回上一页
    void showCalibration();//点击确定按钮后的标定界面
    void showCalibration_skip();//跳过按钮

    void slotRevceviedSteedyFlag(QString str,float currentAllISN,State_Inode state_Inode);//收到稳定符号
};

#endif // BIAODING_H
