#include "andizhizucheng.h"
#include "ui_andizhizucheng.h"
#include "index.h"
#include "dizhi.h"
#include "andizhizucheng2.h"

Andizhizucheng::Andizhizucheng(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Andizhizucheng)
{
    ui->setupUi(this);
   // this->setWindowState(Qt::WindowFullScreen);

    connect(ui->returnIndex,SIGNAL(clicked()),this,SLOT(returnIndex()));
    connect(ui->returnPage,SIGNAL(clicked()),this,SLOT(returnPage()));
    connect(ui->confirm,SIGNAL(clicked()),this,SLOT(showAddress()));
}

Andizhizucheng::~Andizhizucheng()
{
    delete ui;
}

void Andizhizucheng::returnIndex()
{
//    Index *menu=new Index();
//    menu->show();
    this->close();
}

void Andizhizucheng::returnPage()
{
    Dizhi *returnPage=new Dizhi();
    returnPage->show();
    this->close();
}

void Andizhizucheng::showAddress()
{

    //发送扫描地址传感器信息  计算传感器个数-----------------------------------------------------------------
    Group_Sensor_Info group_Sensor_Info;

    for(int i=0;i<16;i++){
        group_Sensor_Info.State[i]=0;
        group_Sensor_Info.IDData[i]=i;
    }
    group_Sensor_Info.State[2]=1;
    group_Sensor_Info.State[6]=2;

    int length=0;
    //int address=-1;//用于确定几号地址
    for(int i=0;i<16;i++){
        if(group_Sensor_Info.State[i]!=0){
            length++;
            //address=i;
        }
    }

    //-------------------------------------------------------------------

    Andizhizucheng2 *showAddress=new Andizhizucheng2(group_Sensor_Info,length);
    showAddress->show();
    this->close();
}
