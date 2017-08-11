#include "wangluoshezhi.h"
#include "ui_wangluoshezhi.h"
#include "page3.h"
#include "index.h"
#include "yitaiwangshezhi.h"
#include "wifi.h"
#include "lanya.h"

Wangluoshezhi::Wangluoshezhi(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Wangluoshezhi)
{
    ui->setupUi(this);
    this->setWindowState(Qt::WindowFullScreen);

    connect(ui->returnIndex,SIGNAL(clicked()),this,SLOT(returnIndex()));
    connect(ui->returnPage,SIGNAL(clicked()),this,SLOT(returnPage()));
    connect(ui->setEthernet,SIGNAL(clicked()),this,SLOT(showEthernet()));
    connect(ui->setWIFI,SIGNAL(clicked()),this,SLOT(showWifi()));
    connect(ui->setBluetooth,SIGNAL(clicked()),this,SLOT(showBluetooth()));
}

Wangluoshezhi::~Wangluoshezhi()
{
    delete ui;
}

void Wangluoshezhi::returnIndex()
{
//    Index *menu=new Index();
//    menu->show();
    this->close();
}

void Wangluoshezhi::returnPage()
{
    Page3 *returnPage=new Page3();
    returnPage->show();
    this->close();
}

void Wangluoshezhi::showEthernet()
{
    Yitaiwangshezhi *showEthernet=new Yitaiwangshezhi();
    showEthernet->show();
    this->close();
}

void Wangluoshezhi::showWifi()
{
    Wifi *showWifi=new Wifi();
    showWifi->show();
    this->close();
}

void Wangluoshezhi::showBluetooth()
{
    Lanya *showBluetooth=new Lanya();
    showBluetooth->show();
    this->close();
}
