#include "tiaochen.h"
#include "ui_tiaochen.h"
#include "index.h"
#include "page2.h"
#include "dizhi.h"
#include "tiaojiao.h"
#include "chengtaizhuangtai.h"
#include "chengtaicanshu.h"
#include "tiaochen_2.h"
#include "biaoding.h"
#include "anzhuangceshi.h"
#include "caishubeifen.h"
#include "canshuhuanyuan.h"

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
    connect(ui->balanceValue,SIGNAL(clicked()),this,SLOT(showBalanceValue()));
    connect(ui->next,SIGNAL(clicked()),this,SLOT(showtiaochen_2()));
    connect(ui->calibration,SIGNAL(clicked()),this,SLOT(showCalibration()));
    connect(ui->test,SIGNAL(clicked()),this,SLOT(showTest()));
    connect(ui->backUp,SIGNAL(clicked()),this,SLOT(showBackup()));
    connect(ui->restore,SIGNAL(clicked()),this,SLOT(showRestore()));
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

void Tiaochen::showBalanceValue()
{
    Chengtaicanshu *showBalanceValue=new Chengtaicanshu();
    showBalanceValue->show();
    this->close();
}

void Tiaochen::showtiaochen_2()
{
    Tiaochen_2 *showtiaochen_2=new Tiaochen_2();
    showtiaochen_2->show();
    this->close();
}

void Tiaochen::showCalibration()
{
    Biaoding *showCalibration=new Biaoding();
    showCalibration->show();
    this->close();
}

void Tiaochen::showTest()
{
    Anzhuangceshi *showTest=new Anzhuangceshi();
    showTest->show();
    this->close();
}

void Tiaochen::showBackup()
{
    Caishubeifen *showBackup=new Caishubeifen();
    showBackup->show();
    this->close();
}

void Tiaochen::showRestore()
{
    Canshuhuanyuan *showRestore=new Canshuhuanyuan();
    showRestore->show();
    this->close();
}



