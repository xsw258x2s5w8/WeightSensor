#ifndef YAJIAOQUERENDIZHI_H
#define YAJIAOQUERENDIZHI_H
#include "lib/sensorisnthread.h"
#include "lib/steedythread.h"
#include <QWidget>
#include <QLabel>

namespace Ui {
class Yajiaoquerendizhi;
}

class Yajiaoquerendizhi : public QWidget
{
    Q_OBJECT
    
public:
    explicit Yajiaoquerendizhi(All_Link_Sensor_ID all_Link_Sensor_ID,State_Inode empty_State_Inode,Set_Address_Sensor Ori_set_Address_Sensor,QWidget *parent = 0);
    ~Yajiaoquerendizhi();
    
private:
    Ui::Yajiaoquerendizhi *ui;

    void GenerateLabels(int length);//根据传感器数量生成对应的label标识
    void SelectLabelPaint(bool select_label,int pos);//根据是否被选中，以及第几个label来确定label的显示

    int biggestSensorAddr(float bigvalue,int runtype);//返回变化量最大的传感器  标准参数， runtype确定是否使用传感器的角差
    int confirmBtn();//判断传感器是否设置过

private:
    QList<QLabel *> listLabel;//Generatelabels 生成的label
    int sensorAddress;  //用于显示待确认的传感器地址

    All_Link_Sensor_ID all_Link_Sensor_ID;//扫描的传感器ID 和数量
    State_Inode empty_State_Inode;//空秤时的传感器信息  1号地址内码，2号地址内码 这样排下去
    State_Inode state_Inode;//压角获得传感器信息

private:
    int biggestAddress;// 真实地址为 biggestddress+1
    SensorIsnThread sensorIsnThread;//读内码线程

    Set_Address_Sensor set_Address_Sensor;//设置的信息 组称根据id和地址
    Set_Address_Sensor Ori_set_Address_Sensor;//原先的信息
    QList<QString> addressList;//用于判断角位是否被确认过

public slots:
    void returnIndex();//主页
    void returnPage();//返回上一页
    void slotConfirmBtn();//确定按钮的槽函数
    void slotRestoreBtn();//还原

    void slotReceviedIsnThread(State_Inode state_Inode,int);//收到读传感器内码线程传来的信息
};

#endif // YAJIAOQUERENDIZHI_H
