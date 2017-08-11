#ifndef SHULIANGYUXIEYI_H
#define SHULIANGYUXIEYI_H

#include <QWidget>
#include<impl/sensorinfo.h>
#include<impl/sensorinfoimpl.h>

namespace Ui {
class Shuliangyuxieyi;
}

class Shuliangyuxieyi : public QWidget
{
    Q_OBJECT
    
public:
    explicit Shuliangyuxieyi(QWidget *parent = 0);
    ~Shuliangyuxieyi();
    
private:
    Ui::Shuliangyuxieyi *ui;
    SensorInfoImpl sensorInfoImpl;//传感器信息表

public slots:
    void returnIndex();//zhuye
    void returnPage();//fanhuicaidan

private:
    void showSensorData();//创建页面的时候查表显示传感器数据
    QString confirmProtocol(int type);//根据查表的protocol确定显示的协议类型
    int SensorCal(QList<SensorInfo> list);//传感器数量的计算
};

#endif // SHULIANGYUXIEYI_H
