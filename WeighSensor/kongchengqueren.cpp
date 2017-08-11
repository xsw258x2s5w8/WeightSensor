#include "kongchengqueren.h"
#include "ui_kongchengqueren.h"
#include "index.h"
#include "zidongzuwang.h"
#include "yajiaoquerendizhi.h"
#include <QMessageBox>
Kongchengqueren::Kongchengqueren(All_Link_Sensor_ID all_Link_Sensor_ID,Set_Address_Sensor Ori_set_Address_Sensor,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Kongchengqueren)
{
    ui->setupUi(this);
    //this->setWindowState(Qt::WindowFullScreen);
    this->setAttribute(Qt::WA_DeleteOnClose);//为了关闭子窗口后能够调用析构函数

    //扫描到的传感器个数
    this->all_Link_Sensor_ID=all_Link_Sensor_ID;
    this->Ori_set_Address_Sensor=Ori_set_Address_Sensor;//id与随机的地址绑定信息

    //开启读内码  的线程；
    sensorIsnThread.SetSensorNumber(all_Link_Sensor_ID.number);//为了配置启动常规采集命令的信息
    sensorIsnThread.start();
    steedyThread.start();

    //判断稳定的线程与界面的槽连接
    connect(&steedyThread,SIGNAL(SendSteedyFlag(QString,float,State_Inode)),this,SLOT(slotRevceviedSteedyFlag(QString,float,State_Inode)));

    //读取内码线程与 判断稳定线程的槽连接
    connect(&sensorIsnThread,SIGNAL(SendISN(State_Inode,int)),&steedyThread,SLOT(slotGetISN(State_Inode,int)));

    //按钮槽连接
    connect(ui->returnIndex,SIGNAL(clicked()),this,SLOT(returnIndex()));
    connect(ui->returnPage,SIGNAL(clicked()),this,SLOT(returnPage()));
    connect(ui->confirm,SIGNAL(clicked()),this,SLOT(showAngleAddress()));
}

Kongchengqueren::~Kongchengqueren()
{
    sensorIsnThread.close();
    steedyThread.close();
    delete ui;
}

void Kongchengqueren::returnIndex()
{
//    Index *menu=new Index();
//    menu->show();
    this->close();
}

void Kongchengqueren::returnPage()
{
    Zidongzuwang *returnPage=new Zidongzuwang();
    returnPage->show();
    this->close();
}

void Kongchengqueren::showAngleAddress()
{
    if(ui->label_test->text()=="稳定"){
        Yajiaoquerendizhi *showAngleAddress=new Yajiaoquerendizhi(all_Link_Sensor_ID,empty_State_Inode,Ori_set_Address_Sensor);
        qDebug()<<"22222222222222222222222222222222222222222222222222222222222222222222222222222222";
        showAngleAddress->show();
        this->close();

    }else{//不稳定
        QMessageBox::information(NULL,"温馨提示","当前秤台不稳定，请秤台稳定后再点确认。",QMessageBox::Yes);
    }


}


//void Kongchengqueren::slotReceviedIsnThread(State_Inode state_Inode)
//{
//    ui->label_test->setText(QString::number(state_Inode.CellState[0].isn));
//    qDebug()<<"界面收到的内码"<<state_Inode.CellState[0].isn;
//}


void Kongchengqueren::slotRevceviedSteedyFlag(QString str,float currentAllISN,State_Inode state_Inode)
{
    ui->label_test->setText(str);
    this->empty_State_Inode=state_Inode;
    //qDebug()<<"收到的稳定后的内码，用于保存空秤是的传感器内码："<<state_Inode.CellState[0].isn;
}
