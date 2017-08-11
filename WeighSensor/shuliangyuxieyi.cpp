#include "shuliangyuxieyi.h"
#include "ui_shuliangyuxieyi.h"
#include "index.h"
#include "dizhi.h"
Shuliangyuxieyi::Shuliangyuxieyi(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Shuliangyuxieyi)
{
    ui->setupUi(this);
    this->setWindowState(Qt::WindowFullScreen);

    //查传感器信息表并显示数据
    showSensorData();

    connect(ui->returnIndex,SIGNAL(clicked()),this,SLOT(returnIndex()));
    connect(ui->returnPage,SIGNAL(clicked()),this,SLOT(returnPage()));
}

Shuliangyuxieyi::~Shuliangyuxieyi()
{
    delete ui;
}

void Shuliangyuxieyi::returnIndex()
{
//    Index *menu=new Index();
//    menu->show();
    this->close();
}

void Shuliangyuxieyi::returnPage()
{
    Dizhi *returnPage=new Dizhi();
    returnPage->show();
    this->close();
}


void Shuliangyuxieyi::showSensorData()
{
    QList<SensorInfo> list=sensorInfoImpl.selectSensorinfo();;

   // 计算传感器数量
    ui->sensor_number->setText(QString::number(SensorCal(list)));

   //显示每个位置的协议
    ui->sensor_1->setText(confirmProtocol(list[0].getProtocol().toInt()));
    ui->sensor_2->setText(confirmProtocol(list[1].getProtocol().toInt()));
    ui->sensor_3->setText(confirmProtocol(list[2].getProtocol().toInt()));
    ui->sensor_4->setText(confirmProtocol(list[3].getProtocol().toInt()));
    ui->sensor_5->setText(confirmProtocol(list[4].getProtocol().toInt()));
    ui->sensor_6->setText(confirmProtocol(list[5].getProtocol().toInt()));
    ui->sensor_7->setText(confirmProtocol(list[6].getProtocol().toInt()));
    ui->sensor_8->setText(confirmProtocol(list[7].getProtocol().toInt()));
    ui->sensor_9->setText(confirmProtocol(list[8].getProtocol().toInt()));
    ui->sensor_10->setText(confirmProtocol(list[9].getProtocol().toInt()));
    ui->sensor_11->setText(confirmProtocol(list[10].getProtocol().toInt()));
    ui->sensor_12->setText(confirmProtocol(list[11].getProtocol().toInt()));
    ui->sensor_13->setText(confirmProtocol(list[12].getProtocol().toInt()));
    ui->sensor_14->setText(confirmProtocol(list[13].getProtocol().toInt()));
    ui->sensor_15->setText(confirmProtocol(list[14].getProtocol().toInt()));
    ui->sensor_16->setText(confirmProtocol(list[15].getProtocol().toInt()));
}


QString Shuliangyuxieyi::confirmProtocol(int type)
{
    switch(type){
        case 0:
            return "无";
        case 1:
            return "C型";
        case 2:
            return "E型";
        case 3:
            return "K型";
        case 4:
            return "CAN型";
        default:
            return "协议获取错误";
    }
}


int Shuliangyuxieyi::SensorCal(QList<SensorInfo> list)
{
    int number=0;//计算得到的传感器数量
    int SensorType;//传感器协议类型  在数据库中协议类型是 0，1，2，3，4 。。。

    for(int i=0;i<list.length();i++){
        SensorType=list[i].getProtocol().toInt();
        if(SensorType!=0){
            number+=1;
        }
    }

    return number;
}
