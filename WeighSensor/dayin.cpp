#include "dayin.h"
#include "ui_dayin.h"
#include "index.h"
#include "page2.h"
#include "dayincanshu.h"

Dayin::Dayin(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Dayin)
{
    ui->setupUi(this);
    this->setWindowState(Qt::WindowFullScreen);

    connect(ui->returnIndex_2,SIGNAL(clicked()),this,SLOT(returnIndex()));
    connect(ui->returnPage_2,SIGNAL(clicked()),this,SLOT(returnPage()));
    connect(ui->setValue,SIGNAL(clicked()),this,SLOT(showPrintValue()));

}


Dayin::~Dayin()
{
    delete ui;
}

void Dayin::returnIndex()
{
//    Index *menu=new Index();
//    menu->show();
    this->close();
}

void Dayin::returnPage()
{
    page2 *returnPage=new page2();
    returnPage->show();
    this->close();
}

void Dayin::showPrintValue()
{
    Dayincanshu *showPrintValue=new Dayincanshu();
    showPrintValue->show();
    this->close();
}
