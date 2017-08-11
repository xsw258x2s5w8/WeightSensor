#include "andizhizucheng2.h"
#include "ui_andizhizucheng2.h"
#include "index.h"
#include "andizhizucheng.h"
//#include "lib/DataStruct.h"

Andizhizucheng2::Andizhizucheng2(Group_Sensor_Info group_Sensor_Info,int length,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Andizhizucheng2)
{
    ui->setupUi(this);
    //this->setWindowState(Qt::WindowFullScreen);

    //生成界面，并且保存显示数据的label
    generateLayout();

    //数据库接口初始化
    sensorInfoImpl=new SensorInfoImpl();

    //赋值
    this->group_Sensor_Info=group_Sensor_Info;
    this->length=length;  

    //处理并显示扫描到的信息
    showProtocol();

    connect(ui->returnIndex,SIGNAL(clicked()),this,SLOT(returnIndex()));
    connect(ui->returnPage,SIGNAL(clicked()),this,SLOT(returnPage()));
    connect(ui->saveBtn,SIGNAL(clicked()),this,SLOT(slotSave()));



}

Andizhizucheng2::~Andizhizucheng2()
{
    delete ui;
}

void Andizhizucheng2::returnIndex()
{
//    Index *menu=new Index();
//    menu->show();
    this->close();
}

void Andizhizucheng2::returnPage()
{
    Andizhizucheng *returnPage=new Andizhizucheng();
    returnPage->show();
    this->close();
}


void Andizhizucheng2::showProtocol()
{
    //-------------------------------------------------------------

    ui->sensor_number->setText(QString::number(length));
    for(int i=0;i<16;i++){
        listAddressLabel[i]->setText(confirmProtocol(group_Sensor_Info.State[i]));
    }
    //---------------------------------------------------------------
}


QString Andizhizucheng2::confirmProtocol(int type)
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


void Andizhizucheng2::slotSave()
{
    //-------------------------------------------------------
    //这里保存传感器的信息到数据库
    QList<SensorInfo> list;

    for(int i=0;i<16;i++){
        SensorInfo sensorInfo;
        sensorInfo.setSensorId(group_Sensor_Info.IDData[i]);
        sensorInfo.setProtocol(QString::number(group_Sensor_Info.State[i])); //协议
        sensorInfo.setAddress(QString::number(i+1));
        sensorInfo.setZeroIsn(0);
        list.append(sensorInfo);
    }

    //先删除表格
    sensorInfoImpl->deleteSensorinfo();

    //插入信息
    for(int i=0;i<list.length();i++){
         sensorInfoImpl->insertSensorinfo(list.at(i));
    }

    this->close();


}


void Andizhizucheng2::generateLayout()
{
    //生成16个位置的label
   for(int i=0;i<4;i++){
       QLabel *label=new QLabel(QString::number(i+1));
       label->setStyleSheet("background-color: rgb(167, 167, 167);");
       QLabel *label2=new QLabel("无");
       QHBoxLayout *phLayout=new QHBoxLayout();
       phLayout->addWidget(label,1);
       phLayout->addWidget(label2,4);
       ui->gridLayout->addLayout(phLayout,0,i);

       listAddressLabel.append(label2);
   }

   for(int i=4;i<8;i++){
       QLabel *label=new QLabel(QString::number(i+1));
       label->setStyleSheet("background-color: rgb(167, 167, 167);");
       QLabel *label2=new QLabel("无");
       QHBoxLayout *phLayout=new QHBoxLayout();
       phLayout->addWidget(label,1);
       phLayout->addWidget(label2,4);
       ui->gridLayout->addLayout(phLayout,1,i-4);

       listAddressLabel.append(label2);
   }

   for(int i=8;i<12;i++){
       QLabel *label=new QLabel(QString::number(i+1));
       label->setStyleSheet("background-color: rgb(167, 167, 167);");
       QLabel *label2=new QLabel("无");
       QHBoxLayout *phLayout=new QHBoxLayout();
       phLayout->addWidget(label,1);
       phLayout->addWidget(label2,4);
       ui->gridLayout->addLayout(phLayout,2,i-8);

       listAddressLabel.append(label2);
   }

   for(int i=12;i<16;i++){
       QLabel *label=new QLabel(QString::number(i+1));
       label->setStyleSheet("background-color: rgb(167, 167, 167);");
       QLabel *label2=new QLabel("无");
       QHBoxLayout *phLayout=new QHBoxLayout();
       phLayout->addWidget(label,1);
       phLayout->addWidget(label2,4);
       ui->gridLayout->addLayout(phLayout,3,i-12);

       listAddressLabel.append(label2);
   }

}
