#ifndef CHENGTAIZHUANGTAI_H
#define CHENGTAIZHUANGTAI_H
#include "lib/sensorisnthread.h"
#include <QWidget>
#include "impl/sensorinfoimpl.h"
#include "impl/sensorinfo.h"
#include <QLabel>

namespace Ui {
class Chengtaizhuangtai;
}

class Chengtaizhuangtai : public QWidget
{
    Q_OBJECT
    
public:
    explicit Chengtaizhuangtai(QWidget *parent = 0);
    ~Chengtaizhuangtai();
    
private:
    Ui::Chengtaizhuangtai *ui;
    QList<QLabel *> listAddressLabel;//保存用于显示数据信息的label

public slots:
    void returnIndex();//主页
    void returnPage();//返回上一页

    void slotReceviedIsnThread(State_Inode state_Inode,int length);//从读内码线程中获取数据
    void slotBtnIsn();//内码按钮
    void slotBtnZeroIsn();//标定点按钮
    void slotBtnSwitch();//切换按钮

private:
    SensorInfoImpl sensorInfoImpl;//传感器信息表接口
    QList<SensorInfo> sensorList;//表中传感器信息

    SensorIsnThread sensorIsnThread;//读取内码线程
    State_Inode empty_State_Inode;

    int btnFlag;//0:表示内码按钮 ，1：标定点按钮
    int btnSwitchFlag;//0:不切换，1：切换

private:
    void generateLayout();//生成布局
};

#endif // CHENGTAIZHUANGTAI_H
