#include "erciguobang.h"
#include "ui_erciguobang.h"
#include "index.h"
#include "index.h"

Erciguobang::Erciguobang(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Erciguobang)
{
    ui->setupUi(this);

    carid=new Erciguobang_car();
    connect(carid,SIGNAL(sendCarId(QString)),this,SLOT(getCarData(QString)));

    artid=new Erciguobang_art();
    connect(artid,SIGNAL(sendArtid(QString)),this,SLOT(getArtData(QString)));
//    connect();

    //按钮槽
    connect(ui->returnIndex,SIGNAL(clicked()),this,SLOT(returnIndex()));
    connect(ui->returnPage,SIGNAL(clicked()),this,SLOT(returnPage()));
    connect(ui->caridbtn,SIGNAL(clicked()),this,SLOT(showCarData()));
    connect(ui->artidbtn,SIGNAL(clicked()),this,SLOT(showArtData()));
    connect(ui->okbtn,SIGNAL(clicked()),this,SLOT(checkOkbtn()));
    connect(ui->replaceBtn,SIGNAL(clicked()),this,SLOT(replaceBTN()));
}

Erciguobang::~Erciguobang()
{
    delete ui;
}

void Erciguobang::getWeight(QString data)
{
   carWeight=data.toFloat();
   ui->currentTime->setText(data);
}

void Erciguobang::showData(QStringList strList)
{
//    if()判断是否是第一次过磅
    //如果是一次过磅‘’‘ 直接显示
    //如果是二次过磅’‘’ 读数据库 再显示
    QDateTime time = QDateTime::currentDateTime();//获取系统现在的时间
    QString str = time.toString("yyyy-MM-dd hh:mm"); //设置显示格式
    ui->currentTime->setText(str);
    ui->lineEdit_car->setText(strList[0]);
    ui->lineEdit_art->setText(strList[1]);
    ui->lineEdit_remark->setText(strList[2]);
}

void Erciguobang::getCarData(QString data)
{
    ui->lineEdit_car->setText(data);
}

void Erciguobang::getArtData(QString data)
{
    ui->lineEdit_art->setText(data);
}

void Erciguobang::getRemarkData(QString data)
{
    ui->lineEdit_remark->setText(data);
}

void Erciguobang::checkOkbtn()
{
//    if(){ //判断是否是一次过磅
            //如果第一次过磅'''直接插入数据库
            //如果是第二次过磅 ‘’‘ 更新数据库

    //    }
}

void Erciguobang::replaceBTN()
{
    //判断是否是第二次
    //如果是就允许替换'''
}

void Erciguobang::returnIndex()
{
    Index *menu=new Index();
    menu->show();
    this->close();
}

void Erciguobang::returnPage()
{
    Index *menu=new Index();
    menu->show();
    this->close();
}

void Erciguobang::showCarData()
{
    carid->show();
}

void Erciguobang::showArtData()
{
    artid->show();
}
