#include "tiaojiao.h"
#include "ui_tiaojiao.h"
#include "index.h"
#include "tiaochen.h"
#include "shuruxishutioajiao.h"
#include "zidongtiaojiaocha.h"
#include "zidongzhoujiaocha.h"
#include "shuzhongliangtiaojiao.h"

Tiaojiao::Tiaojiao(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Tiaojiao)
{
    ui->setupUi(this);
    this->setWindowState(Qt::WindowFullScreen);

    connect(ui->returnIndex,SIGNAL(clicked()),this,SLOT(returnIndex()));
    connect(ui->returnPage,SIGNAL(clicked()),this,SLOT(returnPage()));
    connect(ui->setAngleValue,SIGNAL(clicked()),this,SLOT(showSetAngleValue()));
    connect(ui->autoSetAngleValue,SIGNAL(clicked()),this,SLOT(showautoSetAnglevalue()));
    connect(ui->autoSetAxisAngle,SIGNAL(clicked()),this,SLOT(showautoSetAxisAngle()));
    connect(ui->setWeight,SIGNAL(clicked()),this,SLOT(showautoSetWeight()));
}

Tiaojiao::~Tiaojiao()
{
    delete ui;
}

void Tiaojiao::returnIndex()
{
    Index *menu=new Index();
    menu->show();
    this->close();
}

void Tiaojiao::returnPage()
{
    Tiaochen *returnPage=new Tiaochen();
    returnPage->show();
    this->close();
}

void Tiaojiao::showSetAngleValue()
{
    Shuruxishutioajiao *showSetAngleValue=new Shuruxishutioajiao();
    showSetAngleValue->show();
    this->close();
}

void Tiaojiao::showautoSetAnglevalue()
{
    Zidongtiaojiaocha *showautoSetAnglevalue=new Zidongtiaojiaocha();
    showautoSetAnglevalue->show();
    this->close();
}

void Tiaojiao::showautoSetAxisAngle()
{
    Zidongzhoujiaocha *showautoSetAxisAngle=new Zidongzhoujiaocha();
    showautoSetAxisAngle->show();
    this->close();
}

void Tiaojiao::showautoSetWeight()
{
    Shuzhongliangtiaojiao *showautoSetWeight=new Shuzhongliangtiaojiao();
    showautoSetWeight->show();
    this->close();
}
