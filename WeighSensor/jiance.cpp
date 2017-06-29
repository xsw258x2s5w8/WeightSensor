#include "jiance.h"
#include "ui_jiance.h"
#include "index.h"
#include "page2.h"
#include "yibiaoxinxi.h"
#include "jiance2.h"

Jiance::Jiance(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Jiance)
{
    ui->setupUi(this);
    connect(ui->returnIndex,SIGNAL(clicked()),this,SLOT(returnIndex()));
    connect(ui->returnPage,SIGNAL(clicked()),this,SLOT(returnPage()));
    connect(ui->meterInformation,SIGNAL(clicked()),this,SLOT(showMeterInformation()));
    connect(ui->next,SIGNAL(clicked()),this,SLOT(showNext()));
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
