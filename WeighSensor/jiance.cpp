#include "jiance.h"
#include "ui_jiance.h"
#include "index.h"
#include "page2.h"
#include "yibiaoxinxi.h"
#include "jiance2.h"
#include "pcders232.h"
#include "cunchuqijiance.h"
#include "xianshipingjiance.h"
#include "beiguangliangdu.h"
#include "shouhou.h"
#include "gongdianzhuangtai.h"

Jiance::Jiance(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Jiance)
{
    ui->setupUi(this);
    connect(ui->returnIndex,SIGNAL(clicked()),this,SLOT(returnIndex()));
    connect(ui->returnPage,SIGNAL(clicked()),this,SLOT(returnPage()));
    connect(ui->meterInformation,SIGNAL(clicked()),this,SLOT(showMeterInformation()));
    connect(ui->next,SIGNAL(clicked()),this,SLOT(showNext()));
    connect(ui->check,SIGNAL(clicked()),this,SLOT(showCheck()));
    connect(ui->storage,SIGNAL(clicked()),this,SLOT(showStorage()));
    connect(ui->videocheck,SIGNAL(clicked()),this,SLOT(showCheckVideo()));
    connect(ui->adjustlight,SIGNAL(clicked()),this,SLOT(showCheckLight()));
    connect(ui->service,SIGNAL(clicked()),this,SLOT(showService()));
    connect(ui->lighting,SIGNAL(clicked()),this,SLOT(showLight()));

}

Jiance::~Jiance()
{
    delete ui;
}

void Jiance::returnIndex()
{
    Index *menu=new Index();
    menu->show();
    this->close();
}

void Jiance::returnPage()
{
    page2 *returnPage=new page2();
    returnPage->show();
    this->close();
}

void Jiance::showMeterInformation()
{
    Yibiaoxinxi *showMeterInformation=new Yibiaoxinxi();
    showMeterInformation->show();
    this->close();
}

void Jiance::showNext()
{
    Jiance2 *showNext =new Jiance2();
    showNext->show();
    this->close();

}

void Jiance::showCheck()
{
    Pcders232 *showCheck=new Pcders232();
    showCheck->show();
    this->close();
}

void Jiance::showStorage()
{
    Cunchuqijiance *showStorage=new Cunchuqijiance();
    showStorage->show();
    this->close();
}

void Jiance::showCheckVideo()
{
    Xianshipingjiance *showCheckVideo=new Xianshipingjiance();
    showCheckVideo->show();
    this->close();
}

void Jiance::showCheckLight()
{
    Beiguangliangdu *showCheckLight=new Beiguangliangdu();
    showCheckLight->show();
    this->close();
}

void Jiance::showService()
{
    Shouhou *showService=new Shouhou();
    showService->show();
    this->close();
}

void Jiance::showLight()
{
    Gongdianzhuangtai *showLight=new Gongdianzhuangtai();
    showLight->show();
    this->close();
}
