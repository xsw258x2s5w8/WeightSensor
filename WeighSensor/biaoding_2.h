#ifndef BIAODING_2_H
#define BIAODING_2_H

#include "lib/sensorisnthread.h"
#include "lib/steedythread.h"
#include <QWidget>
#include "impl/weightplatform.h"
#include "impl/weightplatformimpl.h"

namespace Ui {
class Biaoding_2;
}

class Biaoding_2 : public QWidget
{
    Q_OBJECT
    
public:
    explicit Biaoding_2(WeightPlatform weightPlatform,QWidget *parent = 0);
    ~Biaoding_2();
    
private:
    Ui::Biaoding_2 *ui;

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
    void slotConfirm();//确定按钮

    void slotRevceviedSteedyFlag(QString str,float currentAllISN,State_Inode state_Inode);//收到稳定符号
};

#endif // BIAODING_2_H
