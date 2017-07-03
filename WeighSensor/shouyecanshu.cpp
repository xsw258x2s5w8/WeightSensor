#include "shouyecanshu.h"
#include "ui_shouyecanshu.h"
#include "index.h"
#include "page2.h"

Shouyecanshu::Shouyecanshu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Shouyecanshu)
{
    ui->setupUi(this);
    connect(ui->returnIndex,SIGNAL(clicked()),this,SLOT(returnIndex()));
    connect(ui->returnPage,SIGNAL(clicked()),this,SLOT(returnPage()));
}

Shouyecanshu::~Shouyecanshu()
{
    delete ui;
}

void Shouyecanshu::returnIndex()
{
    Index *menu=new Index();
    menu->show();
    this->close();
}

void Shouyecanshu::returnPage()
{
    page2 *returnPage=new page2();
    returnPage->show();
    this->close();
}
