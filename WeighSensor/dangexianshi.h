#ifndef DANGEXIANSHI_H
#define DANGEXIANSHI_H
#include "lib/DataStruct.h"
#include <QWidget>
#include "lib/sensorisnthread.h"
#include "lib/analysissensordata.h"

namespace Ui {
class Dangexianshi;
}

class Dangexianshi : public QWidget
{
    Q_OBJECT
    
public:
    explicit Dangexianshi(Group_Sensor_Info group_Sensor_Info,int address,QWidget *parent = 0);
    ~Dangexianshi();
    
private:
    Ui::Dangexianshi *ui;

public slots:
    void returnIndex();//主页
    void returnPage();//返回上一页

    void slotReceviedIsnThread(State_Inode state_Inode);//接收线程传过来的传感器内码信息

private:
     SensorIsnThread sensorThread;//读传感器内码的线程
     AnalysisSensorData analysisSensor;

     Group_Sensor_Info group_Sensor_Info;
     int address;
};

#endif // DANGEXIANSHI_H
