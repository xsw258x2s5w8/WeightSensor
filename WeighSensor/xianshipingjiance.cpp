#include "xianshipingjiance.h"
#include "ui_xianshipingjiance.h"
#include "index.h"
#include "jiance.h"
#include <QDebug>

Xianshipingjiance::Xianshipingjiance(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Xianshipingjiance)
{
    ui->setupUi(this);
    this->setWindowState(Qt::WindowFullScreen);

    //参数初始化
    number=0;

    connect(ui->returnIndex,SIGNAL(clicked()),this,SLOT(returnIndex()));
    connect(ui->returnPage,SIGNAL(clicked()),this,SLOT(returnPage()));

    connect(ui->widget,SIGNAL(clicked()),this,SLOT(slotTest()));
}

Xianshipingjiance::~Xianshipingjiance()
{
    delete ui;
}

void Xianshipingjiance::returnIndex()
{
//    Index *index=new Index();
//    index->show();
    this->close();
}

void Xianshipingjiance::returnPage()
{
    Jiance *returnPage=new Jiance();
    returnPage->show();
    this->close();
}


void Xianshipingjiance::slotTest()
{
    //number=4 时关闭显示屏检测页面
    number+=1;

    if(number==1){
        ui->widget->setStyleSheet("background-color: rgb(0, 0, 0)");
    }else if(number==2){
        ui->widget->setStyleSheet("background-color: rgb(85, 255, 0)");
    }else if(number==3){
         ui->widget->setStyleSheet(" background-color: rgb(85, 170, 255)");
    }else if(number==4){
        this->close();
    }



    qDebug()<<"2jiace";
}
