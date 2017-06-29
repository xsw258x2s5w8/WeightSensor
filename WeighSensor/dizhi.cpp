#include "dizhi.h"
#include "ui_dizhi.h"
#include "index.h"
#include "tiaochen.h"
#include "dangeshedizhi.h"
#include "andizhizucheng.h"
#include "zidongzuwang.h"

Dizhi::Dizhi(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Dizhi)
{
    ui->setupUi(this);
    connect(ui->returnIndex,SIGNAL(clicked()),this,SLOT(returnIndex()));
    connect(ui->returnPage,SIGNAL(clicked()),this,SLOT(returnPage()));
    connect(ui->setSingleAddress,SIGNAL(clicked()),this,SLOT(showSingleAddress()));
    connect(ui->addressWeigh,SIGNAL(clicked()),this,SLOT(showAddressW()));
    connect(ui->setSingleAddress,SIGNAL(clicked()),this,SLOT(showSingleAddress()));
    connect(ui->autoNetwork,SIGNAL(clicked()),this,SLOT(showautoNetwork()));
}

Dizhi::~Dizhi()
{
    delete ui;
}

void Dizhi::returnIndex()
{
    Index *menu=new Index();
    menu->show();
    this->close();
}

void Dizhi::returnPage()
{
    Tiaochen *returnPage=new Tiaochen();
    returnPage->show();
    this->close();
}

void Dizhi::showSingleAddress()
{
    Dangeshedizhi *showSingleAddress=new Dangeshedizhi();
    showSingleAddress->show();
    this->close();
}

void Dizhi::showAddressW()
{
    Andizhizucheng *showAddressW=new Andizhizucheng();
    showAddressW->show();
    this->close();
}

void Dizhi::showautoNetwork()
{
    Zidongzuwang *showautoNetwork=new Zidongzuwang();
    showautoNetwork->show();
    this->close();
}
