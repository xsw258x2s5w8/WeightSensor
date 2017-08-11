#include "dangeshedizhi.h"
#include "ui_dangeshedizhi.h"
#include "dizhi.h"
#include "index.h"
#include "shezhi.h"

Dangeshedizhi::Dangeshedizhi(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Dangeshedizhi)
{
    ui->setupUi(this);
    this->setWindowState(Qt::WindowFullScreen);

    connect(ui->returnIndex,SIGNAL(clicked()),this,SLOT(returnIndex()));
    connect(ui->returnPage,SIGNAL(clicked()),this,SLOT(returnPage()));
    connect(ui->scanning,SIGNAL(clicked()),this,SLOT(showScan()));
}

Dangeshedizhi::~Dangeshedizhi()
{
    delete ui;
}

void Dangeshedizhi::returnIndex()
{
//    Index *menu=new Index();
//    menu->show();
    this->close();
}

void Dangeshedizhi::returnPage()
{
    Dizhi *returnPage=new Dizhi();
    returnPage->show();
    this->close();
}

void Dangeshedizhi::showScan()
{
    //目前自己暂时初始化结构体内的数据

    //这边1.需要发送按地址扫描传感器指令，2.计算传感器个数
    Group_Sensor_Info group_Sensor_Info;   //接口给我的结构体格式
    for(int i=0;i<16;i++){
        group_Sensor_Info.State[i]=0;
        group_Sensor_Info.IDData[i]=1;
    }
    group_Sensor_Info.State[5]=1;

    //计算并确定是几号地址
    int length=0;
    int address=-1;//用于确定几号地址
    for(int i=0;i<16;i++){
        if(group_Sensor_Info.State[i]!=0){
            length++;
            address=i+1;  //地址比在数据位大1位
        }
    }
    qDebug()<<length;

    //进入下个页面,并传递信息
    if(length==1){
        Shezhi *showScan=new Shezhi(group_Sensor_Info,address);
        showScan->show();
        this->close();
    }else{
        qDebug()<<"传感器个数不为1";
    }
}
