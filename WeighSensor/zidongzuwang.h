#ifndef ZIDONGZUWANG_H
#define ZIDONGZUWANG_H
#include "lib/DataStruct.h"
#include <QWidget>

namespace Ui {
class Zidongzuwang;
}

class Zidongzuwang : public QWidget
{
    Q_OBJECT
    
public:
    explicit Zidongzuwang(QWidget *parent = 0);
    ~Zidongzuwang();
    
private:
    Ui::Zidongzuwang *ui;


public slots:
    void returnIndex();//主页
    void returnPage();//返回上一页、
    void showKongcheng();//进入空秤确认界面，这里需要发送组称根据id，地址设置地址（地址随机分配，初始化）

private:
    All_Link_Sensor_ID all_Link_Sensor_ID;// 组称 扫描所有传感器id

    Set_Address_Sensor set_Address_Sensor;//设置的信息 组称根据id和地址
    Group_Sensor_Address group_Sensor_Address;//返回的信息  组称根据id和地址

};

#endif // ZIDONGZUWANG_H
