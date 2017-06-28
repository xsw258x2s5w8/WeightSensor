#include "dayin.h"
#include "ui_dayin.h"
#include "index.h"
#include "page2.h"

Dayin::Dayin(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Dayin)
{
    ui->setupUi(this);
    connect(ui->returnIndex_2,SIGNAL(clicked()),this,SLOT(returnIndex()));
    connect(ui->returnPage_2,SIGNAL(clicked()),this,SLOT(returnPage()));
}

Dayin::~Dayin()
{
    delete ui;
}

void Dayin::returnIndex()
{
    Index *menu=new Index();
    menu->show();
    this->close();
}

void Dayin::returnPage()
{
    page2 *returnPage=new page2();
    returnPage->show();
    this->close();
}
