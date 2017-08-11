#ifndef ZIDONGTIAOJIAOCHA_H
#define ZIDONGTIAOJIAOCHA_H
#include "lib/sensorisnthread.h"
#include "lib/steedythread.h"
#include <QWidget>

namespace Ui {
class Zidongtiaojiaocha;
}

class Zidongtiaojiaocha : public QWidget
{
    Q_OBJECT
    
public:
    explicit Zidongtiaojiaocha(QWidget *parent = 0);
    ~Zidongtiaojiaocha();
    
private:
    Ui::Zidongtiaojiaocha *ui;

private:
    SensorIsnThread sensorIsnThread;
    SteedyThread steedyThread;

    int sensorNumber;//传感器数量
    float emptyCurrentAllISN;//空秤时的总内码
    State_Inode empty_State_Inode;//保存的空秤信息

public slots:
    void returnIndex();//主页
    void returnPage();//返回上一页
    void showconfirmWeigh();//进入压角确认界面

    void slotRevceviedSteedyFlag(QString str,float currentAllISN,State_Inode state_Inode);//收到稳定符号
};

#endif // ZIDONGTIAOJIAOCHA_H
