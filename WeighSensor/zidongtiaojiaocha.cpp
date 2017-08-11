#include "zidongtiaojiaocha.h"
#include "ui_zidongtiaojiaocha.h"
#include "index.h"
#include "tiaojiao.h"
#include "yajiaoqueren.h"

Zidongtiaojiaocha::Zidongtiaojiaocha(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Zidongtiaojiaocha)
{
    ui->setupUi(this);
    //this->setWindowState(Qt::WindowFullScreen);
    this->setAttribute(Qt::WA_DeleteOnClose);//为了关闭子窗口后能够调用析构函数

    //查数据库 获取传感器数量
    sensorNumber=5;

    //开启读内码  的线程；
    sensorIsnThread.SetSensorNumber(sensorNumber);//为了配置启动常规采集命令的信息
    sensorIsnThread.start();
    steedyThread.start();

    //读取内码线程与 判断稳定线程的槽连接
    connect(&sensorIsnThread,SIGNAL(SendISN(State_Inode,int)),&steedyThread,SLOT(slotGetISN(State_Inode,int)));


    //判断稳定的线程与界面的槽连接
    connect(&steedyThread,SIGNAL(SendSteedyFlag(QString,float,State_Inode)),this,SLOT(slotRevceviedSteedyFlag(QString,float,State_Inode)));

    //
    connect(ui->returnIndex,SIGNAL(clicked()),this,SLOT(returnIndex()));
    connect(ui->returnPage,SIGNAL(clicked()),this,SLOT(returnPage()));
    connect(ui->confirm,SIGNAL(clicked()),this,SLOT(showconfirmWeigh()));
}

Zidongtiaojiaocha::~Zidongtiaojiaocha()
{
    sensorIsnThread.close();
    steedyThread.close();
    delete ui;
}

void Zidongtiaojiaocha::returnIndex()
{
//    Index *menu=new Index();
//    menu->show();
    this->close();
}

void Zidongtiaojiaocha::returnPage()
{
    Tiaojiao *returnPage=new Tiaojiao();
    returnPage->show();
    this->close();
}

void Zidongtiaojiaocha::showconfirmWeigh()
{
    if(ui->label_test->text()=="稳定"){
        Yajiaoqueren *showconfirmWeigh=new Yajiaoqueren(empty_State_Inode,emptyCurrentAllISN,sensorNumber);
        showconfirmWeigh->show();
        this->close();

    //未稳定
    }else{
        QMessageBox::information(NULL,"温馨提示","秤台不稳定，请稳定后再点击确认",QMessageBox::Yes);
    }

}

void Zidongtiaojiaocha::slotRevceviedSteedyFlag(QString str, float currentAllISN, State_Inode state_Inode)
{
    ui->label_test->setText(str);
    this->empty_State_Inode=state_Inode;
    this->emptyCurrentAllISN=currentAllISN;
}
