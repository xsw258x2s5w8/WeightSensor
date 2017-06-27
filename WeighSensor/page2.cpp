#include "page2.h"
#include "ui_page2.h"
#include "index.h"
#include "page1.h"
#include "tiaochen.h"
#include "wurenzhishou.h"
#include "jiance.h"
#include"shipinshezhi.h"

page2::page2(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::page2)
{
    ui->setupUi(this);
    connect(ui->returnIndex,SIGNAL(clicked()),this,SLOT(returnIndex()));
    connect(ui->permission,SIGNAL(clicked()),this,SLOT(showPermission()));
    connect(ui->returnPage,SIGNAL(clicked()),this,SLOT(returnPage()));
    connect(ui->adjustable,SIGNAL(clicked()),this,SLOT(showAdjustable()));
    connect(ui->unmanned,SIGNAL(clicked()),this,SLOT(showUnmanned()));
    connect(ui->check,SIGNAL(clicked()),this,SLOT(showCheck()));
    connect(ui->video,SIGNAL(clicked()),this,SLOT(showVideo()));
}

page2::~page2()
{
    delete ui;
}

void page2::returnIndex()
{
    Index *index=new Index();
    index->show();
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
    Index *index=new Index();
    index->show();
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
