#include "tiaochen.h"
#include "ui_tiaochen.h"
#include "index.h"
#include "page2.h"
#include "dizhi.h"
#include "tiaojiao.h"
#include "chengtaizhuangtai.h"

Tiaochen::Tiaochen(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Tiaochen)
{
    ui->setupUi(this);
    connect(ui->returnIndex_2,SIGNAL(clicked()),this,SLOT(returnIndex()));
    connect(ui->returnPage_2,SIGNAL(clicked()),this,SLOT(returnPage()));
    connect(ui->address,SIGNAL(clicked()),this,SLOT(showAddress()));
    connect(ui->adjustAngle,SIGNAL(clicked()),this,SLOT(showAdjustAngle()));
    connect(ui->balanceState,SIGNAL(clicked()),this,SLOT(showBalanceState()));
}

Tiaochen::~Tiaochen()
{
    delete ui;
}

void Tiaochen::returnIndex()
{
    Index *menu=new Index();
    menu->show();
    this->close();
}

void Tiaochen::returnPage()
{
    page2 *returnPage=new page2();
    returnPage->show();
    this->close();
}

void Tiaochen::showAddress()
{
    Dizhi *showAddress=new Dizhi();
    showAddress->show();
    this->close();
}

void Tiaochen::showAdjustAngle()
{
    Tiaojiao *showAddress=new Tiaojiao();
    showAddress->show();
    this->close();
}

void Tiaochen::showBalanceState()
{
    Chengtaizhuangtai *showBalanceState=new Chengtaizhuangtai();
    showBalanceState->show();
    this->close();
}


