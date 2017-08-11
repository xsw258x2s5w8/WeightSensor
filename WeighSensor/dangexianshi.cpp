#include "dangexianshi.h"
#include "ui_dangexianshi.h"
#include "index.h"
#include "shezhi.h"


Dangexianshi::Dangexianshi(Group_Sensor_Info group_Sensor_Info,int address,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Dangexianshi)
{
    ui->setupUi(this);
    //this->setWindowState(Qt::WindowFullScreen);
    this->setAttribute(Qt::WA_DeleteOnClose);//为了关闭子窗口后能够调用析构函数

    //接收前一页穿过来的包括地址的协议信息   state[16]
    this->group_Sensor_Info=group_Sensor_Info;
    this->address=address;

    //启动常规采集  (几号地址的协议类型,密码)

    //读内码显示信息  线程
    sensorThread.SetSensorNumber(1);
    sensorThread.start();

    connect(ui->returnIndex,SIGNAL(clicked()),this,SLOT(returnIndex()));
    connect(ui->returnPage,SIGNAL(clicked()),this,SLOT(returnPage()));

    //接收线程信号的槽连接
    connect(&sensorThread,SIGNAL(SendISN(State_Inode)),this,SLOT(slotReceviedIsnThread(State_Inode)));

    qDebug()<<"线程之后";
}

Dangexianshi::~Dangexianshi()
{
    //关闭线程

    sensorThread.close();//这个是自定义的
//    sensorThread.quit();
//    sensorThread.wait();
    //sensorThread.deleteLater();

    delete ui;
}


void Dangexianshi::returnIndex()
{
    this->close();
}


void Dangexianshi::returnPage()
{
    //Shezhi *returnPage=new Shezhi();
   // returnPage->show();
    this->close();
}


void Dangexianshi::slotReceviedIsnThread(State_Inode state_Inode)
{
    //传感器数据解析类
    analysisSensor.Analysis(state_Inode);

    qDebug()<<"分析出的值："<<analysisSensor.state;
    for(int i=0;i<16;i++){
        for(int j=0;j<8;j++){
            qDebug()<<"分析出的值0："<<analysisSensor.state0[i].at(j)<<i;
        }
        for(int j=0;j<8;j++){
            qDebug()<<"分析出的值1："<<analysisSensor.state1[i].at(j)<<i;
        }
    }

    qDebug()<<"界面收到的值"<<state_Inode.CellState[0].state0;


    //在界面显示数据
    ui->lineEdit_protocol->setText(QString::number(group_Sensor_Info.State[address-1]));
    ui->lineEdit_address->setText(QString::number(address));
    ui->lineEdit_state->setText(analysisSensor.state0[address-1].at(7));
    ui->lineEdit_ISN->setText(QString::number(analysisSensor.state_Inode.CellState[0].isn));
}

