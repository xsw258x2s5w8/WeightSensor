#include "page2.h"
#include "ui_page2.h"
#include "index.h"
#include "page1.h"
#include "tiaochen.h"

page2::page2(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::page2)
{
    ui->setupUi(this);
    connect(ui->returnIndex,SIGNAL(clicked()),this,SLOT(returnIndex()));
    connect(ui->permission,SIGNAL(clicked()),this,SLOT(showPermission()));
    connect(ui->returnPage,SIGNAL(clicked()),this,SLOT(returnPage()));
    connect(ui->adjustable,SIGNAL(clicked()),this,SLOT(showAdjustable()));
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
