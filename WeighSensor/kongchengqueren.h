#ifndef KONGCHENGQUEREN_H
#define KONGCHENGQUEREN_H
#include "lib/sensorisnthread.h"
#include "lib/steedythread.h"
#include <QWidget>


namespace Ui {
class Kongchengqueren;
}

class Kongchengqueren : public QWidget
{
    Q_OBJECT
    
public:
    explicit Kongchengqueren(All_Link_Sensor_ID all_Link_Sensor_ID,Set_Address_Sensor Ori_set_Address_Sensor,QWidget *parent = 0);
    ~Kongchengqueren();
    
private:
    Ui::Kongchengqueren *ui;

private:
    SensorIsnThread sensorIsnThread;
    SteedyThread steedyThread;

    Set_Address_Sensor Ori_set_Address_Sensor;//随机设地址的信息，需要传个下个界面，该数据从上个界面传过来

    All_Link_Sensor_ID all_Link_Sensor_ID;//扫描的传感器ID与数量
    State_Inode empty_State_Inode;//保存的空秤信息

public slots:
    void returnIndex();//主页
    void returnPage();//返回上一页、
    void showAngleAddress();//进入压角确认地址

   // void slotReceviedIsnThread(State_Inode state_Inode);
    void slotRevceviedSteedyFlag(QString str,float currentAllISN,State_Inode state_Inode);//收到稳定符号

};

#endif // KONGCHENGQUEREN_H
