#ifndef BIAODING_1_H
#define BIAODING_1_H

#include "lib/sensorisnthread.h"
#include "lib/steedythread.h"
#include <QWidget>
#include "impl/weightplatform.h"
#include "impl/weightplatformimpl.h"

namespace Ui {
class Biaoding_1;
}

class Biaoding_1 : public QWidget
{
    Q_OBJECT
    
public:
    explicit Biaoding_1(WeightPlatform weightPlatform,QWidget *parent = 0);
    ~Biaoding_1();
    
private:
    Ui::Biaoding_1 *ui;

private:
    SensorIsnThread sensorIsnThread;
    SteedyThread steedyThread;

    //DemarcateWeightSTR demarcateWeightSTR;//标定的参数
    //State_Inode state_Inode;  //保存零点内码的信息
    float currentAllISN;  //滤波后的内码，从steedyThread传过来

    WeightPlatformImpl weightPlatformImpl;//秤台参数数据库接口
    WeightPlatform weightPlatform;

public slots:
    void returnIndex();//主页
    void returnPage();//返回上一页
    void showConfirmCalibration();//点击确认进入第二个标定点界面
    void showSkipCalibration();//点击跳过 进入第二个标定界面。

    void slotRevceviedSteedyFlag(QString str,float currentAllISN,State_Inode state_Inode);//收到稳定符号
};

#endif // BIAODING_1_H
