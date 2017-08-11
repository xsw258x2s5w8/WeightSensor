#ifndef SHEZHI_H
#define SHEZHI_H
//#include<stdio.h>
//#include<stdlib.h>
#include "lib/DataStruct.h"

#include <QWidget>


namespace Ui {
class Shezhi;
}

class Shezhi : public QWidget
{
    Q_OBJECT
    
public:
    explicit Shezhi(Group_Sensor_Info group_Sensor_Info,int address,QWidget *parent = 0);
    ~Shezhi();
    
private:
    Ui::Shezhi *ui;

public slots:
    void returnIndex();//主页
    void returnPage();//返回上一页
    void showSingleData();//显示单个传感器内码等信息

private:
    void showProtocol();//显示解析后的数据

private:
    Group_Sensor_Info group_Sensor_Info;//结构体
    int address;//几号地址
};

#endif // SHEZHI_H
