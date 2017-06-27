#include "page1.h"
#include "ui_page1.h"
#include "index.h"
#include "page2.h"

page1::page1(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::page1)
{
    ui->setupUi(this);
    connect(ui->returnIndex_3,SIGNAL(clicked()),this,SLOT(returnIndex()));
    connect(ui->returnPage,SIGNAL(clicked()),this,SLOT(returnPage()));
}

page1::~page1()
{
    delete ui;
}

void page1::returnIndex()
{
    Index *index=new Index();
    index->show();
    this->close();
}

void page1::returnPage()
{
    page2 *returnPage=new page2();
    returnPage->show();
    this->close();
}
