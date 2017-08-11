#include "page2.h"
#include "ui_page2.h"
#include "index.h"
#include "page1.h"
#include "tiaochen.h"
#include "wurenzhishou.h"
#include "jiance.h"
#include "shipinshezhi.h"
#include "erweimaguanli.h"
#include "dayin.h"
#include "page3.h"
#include "shouyecanshu.h"

page2::page2(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::page2)
{
    ui->setupUi(this);
    this->setWindowState(Qt::WindowFullScreen);

    connect(ui->returnIndex,SIGNAL(clicked()),this,SLOT(returnIndex()));
    connect(ui->permission,SIGNAL(clicked()),this,SLOT(showPermission()));
    connect(ui->returnPage,SIGNAL(clicked()),this,SLOT(returnPage()));
    connect(ui->adjustable,SIGNAL(clicked()),this,SLOT(showAdjustable()));
    connect(ui->unmanned,SIGNAL(clicked()),this,SLOT(showUnmanned()));
    connect(ui->check,SIGNAL(clicked()),this,SLOT(showCheck()));
    connect(ui->video,SIGNAL(clicked()),this,SLOT(showVideo()));
    connect(ui->QRcode,SIGNAL(clicked()),this,SLOT(showQRcode()));
    connect(ui->print,SIGNAL(clicked()),this,SLOT(showPrint()));
    connect(ui->next,SIGNAL(clicked()),this,SLOT(showNext()));
    connect(ui->editBtn,SIGNAL(clicked()),this,SLOT(showEditIndex()));
}

page2::~page2()
{
    delete ui;
}

void page2::returnIndex()
{
//    Index *index=new Index();
//    index->show();
    this->close();
}

void page2::showPermission()
{
    page1 *permission=new page1();
    permission->show();
    this->close();
}

void page2::returnPage()
{
//    Index *index=new Index();
//    index->show();
    this->close();
}

void page2::showAdjustable()
{
    Tiaochen *showAdjustable=new Tiaochen();
    showAdjustable->show();
    this->close();
}

void page2::showUnmanned()
{
    Wurenzhishou *showUnmanned=new Wurenzhishou();
    showUnmanned->show();
    this->close();
}

void page2::showCheck()
{
    Jiance *showCheck=new Jiance();
    showCheck->show();
    this->close();
}

void page2::showVideo()
{
    Shipinshezhi *showVideo=new Shipinshezhi();
    showVideo->show();
    this->close();
}

void page2::showQRcode()
{
    Erweimaguanli *showQRcode=new Erweimaguanli();
    showQRcode->show();
    this->close();
}

void page2::showPrint()
{
    Dayin *showPrint=new Dayin();
    showPrint->show();
    this->close();
}

void page2::showNext()
{
    Page3 *showNext=new Page3();
    showNext->show();
    this->close();
}

void page2::showEditIndex()
{
    Shouyecanshu *showEditIndex=new Shouyecanshu();
    showEditIndex->show();
    this->close();
}
