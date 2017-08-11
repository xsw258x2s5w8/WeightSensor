#include "pcders232.h"
#include "ui_pcders232.h"
#include "index.h"
#include "jiance.h"
#include <QDebug>

Pcders232::Pcders232(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Pcders232)
{
    ui->setupUi(this);
    this->setWindowState(Qt::WindowFullScreen);

    connect(ui->returnIndex,SIGNAL(clicked()),this,SLOT(returnIndex()));
    connect(ui->returnPage,SIGNAL(clicked()),this,SLOT(returnPage()));

    //com按钮槽
    connect(ui->com1,SIGNAL(clicked()),this,SLOT(slotChooseBtn()));
    connect(ui->com2,SIGNAL(clicked()),this,SLOT(slotChooseBtn()));
    connect(ui->com3,SIGNAL(clicked()),this,SLOT(slotChooseBtn()));
    connect(ui->com4,SIGNAL(clicked()),this,SLOT(slotChooseBtn()));
    connect(ui->com5,SIGNAL(clicked()),this,SLOT(slotChooseBtn()));
    connect(ui->com6,SIGNAL(clicked()),this,SLOT(slotChooseBtn()));
}

Pcders232::~Pcders232()
{
    delete ui;
}

void Pcders232::returnIndex()
{
//    Index *menu=new Index();
//    menu->show();
    this->close();
}

void Pcders232::returnPage()
{
    Jiance *returnPage=new Jiance();
    returnPage->show();
    this->close();
}


void Pcders232::slotChooseBtn()
{
    //获取发送信号的部件
    QPushButton* btn= qobject_cast<QPushButton*>(sender());

    //根据对象名决定触发事件
    if("com1"==btn->objectName()){
        ui->label_com->setText("com1:");
        QPixmap img1(":/image/images/RS232.png");
        ui->label_image->setPixmap(img1);
    }else if("com2"==btn->objectName()){
        ui->label_com->setText("com2:");
        QPixmap img1(":/image/images/locate.svg");
        ui->label_image->setPixmap(img1);
    }else if("com3"==btn->objectName()){
        ui->label_com->setText("com3:");
        QPixmap img1(":/image/images/phone.svg");
        ui->label_image->setPixmap(img1);
    }else if("com4"==btn->objectName()){
        ui->label_com->setText("com4:");
        QPixmap img1(":/image/images/warning.png");
        ui->label_image->setPixmap(img1);
    }else if("com5"==btn->objectName()){
        ui->label_com->setText("com5:");
        QPixmap img1(":/image/images/wireless.svg");
        ui->label_image->setPixmap(img1);
    }else if("com6"==btn->objectName()){
        ui->label_com->setText("com6:");
        QPixmap img1(":/image/images/gantan.svg");
        ui->label_image->setPixmap(img1);
    }
}
