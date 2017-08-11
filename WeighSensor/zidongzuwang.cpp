#include "zidongzuwang.h"
#include "ui_zidongzuwang.h"
#include "index.h"
#include "dizhi.h"
#include "kongchengqueren.h"

Zidongzuwang::Zidongzuwang(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Zidongzuwang)
{
    ui->setupUi(this);
   // this->setWindowState(Qt::WindowFullScreen);

    //发送 组称获得所有传感器id  命令
    all_Link_Sensor_ID.state=0;
    all_Link_Sensor_ID.type=2;
    all_Link_Sensor_ID.number=4;
    for(int i;i<16;i++){
        all_Link_Sensor_ID.IDData[i]=i*111111;
    }

    //发命令获取id。。。

    //显示扫描到的总数
    ui->lineEdit_number->setText(QString::number(all_Link_Sensor_ID.number));

    //槽连接
    connect(ui->returnIndex,SIGNAL(clicked()),this,SLOT(returnIndex()));
    connect(ui->returnPage,SIGNAL(clicked()),this,SLOT(returnPage()));
    connect(ui->save,SIGNAL(clicked()),this,SLOT(showKongcheng()));
}

Zidongzuwang::~Zidongzuwang()
{
    delete ui;
}

void Zidongzuwang::returnIndex()
{
//    Index *menu=new Index();
//    menu->show();
    this->close();
}

void Zidongzuwang::returnPage()
{
    Dizhi *returnPage=new Dizhi();
    returnPage->show();
    this->close();
}

void Zidongzuwang::showKongcheng()
{
    //设置需要设置传感器的信息
    set_Address_Sensor.type=all_Link_Sensor_ID.type;
    set_Address_Sensor.number=all_Link_Sensor_ID.number;
    for(int i=0;i<all_Link_Sensor_ID.number;i++){
        set_Address_Sensor.ID[i]=all_Link_Sensor_ID.IDData[i];
        set_Address_Sensor.address[i]=i;
    }
    set_Address_Sensor.address[5]=7;
    set_Address_Sensor.address[7]=9;
    set_Address_Sensor.address[9]=5;

    //发送设置地址命令（）
    //group_Sensor_Address=命令(set_Address_Sensor)...............
      group_Sensor_Address.number=14;//是返回的
      for(int i=0;i<group_Sensor_Address.number;i++){
        group_Sensor_Address.state[i]=1;
      }
        //      group_Sensor_Address.state[2]=0;


    //判断是否设置失败，如果是不打开空秤界面 提醒设置失败
    int isFail=0;

    for(int i=0;i<group_Sensor_Address.number;i++){
        if(group_Sensor_Address.state[i]==0){//传感器设置失败
            isFail++;
        }
    }

    if(isFail==0){
        //设置成功
        Kongchengqueren *showKongcheng=new Kongchengqueren(all_Link_Sensor_ID,set_Address_Sensor);
        showKongcheng->show();
        this->close();
    }else{
        //设置失败
        qDebug()<<"随机设置传感器地址失败";
    }



}
