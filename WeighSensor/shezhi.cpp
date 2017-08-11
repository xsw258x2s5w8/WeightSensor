#include "shezhi.h"
#include "ui_shezhi.h"
#include "index.h"
#include "dangeshedizhi.h"
#include "dangexianshi.h"

Shezhi::Shezhi(Group_Sensor_Info group_Sensor_Info,int address,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Shezhi)
{
    ui->setupUi(this);
   // this->setWindowState(Qt::WindowFullScreen);

    //保存数据
    this->group_Sensor_Info=group_Sensor_Info;
    this->address=address;
    qDebug()<<"设置界面,该地址位的协议:"<<group_Sensor_Info.State[address-1];

    //显示处理好协议等数据
    showProtocol();

    connect(ui->returnIndex,SIGNAL(clicked()),this,SLOT(returnIndex()));
    connect(ui->returnPage,SIGNAL(clicked()),this,SLOT(returnPage()));
    connect(ui->updatBtn,SIGNAL(clicked()),this,SLOT(showSingleData()));
}

Shezhi::~Shezhi()
{
    delete ui;
}

void Shezhi::returnIndex()
{
//    Index *menu=new Index();
//    menu->show();
    this->close();
}

void Shezhi::returnPage()
{
    Dangeshedizhi *returnPage=new Dangeshedizhi();
    returnPage->show();
    this->close();
}


void Shezhi::showSingleData()
{
    //这边需要发送设地址的命令
        Set_Address_Sensor set_Address_Sensor;
        set_Address_Sensor.type=group_Sensor_Info.State[address-1];
        set_Address_Sensor.number=1;
        set_Address_Sensor.ID[0]=group_Sensor_Info.IDData[address-1];
        set_Address_Sensor.address[0]=ui->lineEdit_newAddress->text().toUInt();
        qDebug()<<"设置界面,发送新命令地址号:"<<set_Address_Sensor.address[0];

        Group_Sensor_Address group_Sensor_Address; //这个是发设置地址 返回的信息
    //

    // if 设置成功 打开显示页面,并且传地址过去  [16],这里传 group_Sensor_Info.State[16]过去
    Dangexianshi *showSingleData=new Dangexianshi(group_Sensor_Info,address);
    showSingleData->show();
    this->close();
}


void Shezhi::showProtocol()
{
     //qDebug()<<"设置界面"<<group_Sensor_Info.State[address];
    ui->lineEdit_state->setText(QString::number(group_Sensor_Info.State[address-1]));
    ui->lineEdit_address->setText(QString::number(address));
    ui->lineEdit_newAddress->setText(QString::number(address));
}
