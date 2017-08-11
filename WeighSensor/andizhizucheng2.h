#ifndef ANDIZHIZUCHENG2_H
#define ANDIZHIZUCHENG2_H
#include "lib/DataStruct.h"
#include <QWidget>
#include "impl/sensorinfoimpl.h"
#include "impl/sensorinfo.h"
#include <QLabel>

namespace Ui {
class Andizhizucheng2;
}

class Andizhizucheng2 : public QWidget
{
    Q_OBJECT
    
public:
    explicit Andizhizucheng2(Group_Sensor_Info group_Sensor_Info,int length,QWidget *parent = 0);
    ~Andizhizucheng2();
    
private:
    Ui::Andizhizucheng2 *ui;
    QList<QLabel *> listAddressLabel;//保存用于显示数据信息的label

public slots:
    void returnIndex();//主页
    void returnPage();//返回上一页
    void slotSave();//保存传感器的信息  //协议,id,地址,个数

private:
    Group_Sensor_Info group_Sensor_Info;  //按地址扫描传感器的信息
    int length; //传感器个数

private:
    SensorInfoImpl *sensorInfoImpl;//传感器信息表

private:
    void generateLayout();//生成布局
    void showProtocol();//显示扫描到的信息
    QString confirmProtocol(int type);//根据传感器协议数字确定显示的协议类型
};

#endif // ANDIZHIZUCHENG2_H
