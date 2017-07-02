#include "wanzheng_chaxun.h"
#include "ui_wanzheng_chaxun.h"
#include "wanzheng.h"
#include "index.h"

Wanzheng_chaxun::Wanzheng_chaxun(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Wanzheng_chaxun)
{
    ui->setupUi(this);

    connect(ui->returnIndex,SIGNAL(clicked()),this,SLOT(returnIndex()));
    connect(ui->returnPage,SIGNAL(clicked()),this,SLOT(returnPage()));
}

Wanzheng_chaxun::~Wanzheng_chaxun()
{
    delete ui;
}

void Wanzheng_chaxun::returnIndex()
{
    Index *menu=new Index();
    menu->show();
    this->close();
}

void Wanzheng_chaxun::returnPage()
{
    Wanzheng *returnPage=new Wanzheng();
    returnPage->show();
    this->close();
}
