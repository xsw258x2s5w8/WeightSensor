#include "buwanzheng_chaxun.h"
#include "ui_buwanzheng_chaxun.h"
#include "index.h"
#include "buwanzheng.h"

Buwanzheng_chaxun::Buwanzheng_chaxun(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Buwanzheng_chaxun)
{
    ui->setupUi(this);
    this->setWindowState(Qt::WindowFullScreen);

    connect(ui->returnIndex,SIGNAL(clicked()),this,SLOT(returnIndex()));
    connect(ui->returnPage,SIGNAL(clicked()),this,SLOT(returnPage()));
}

Buwanzheng_chaxun::~Buwanzheng_chaxun()
{
    delete ui;
}

void Buwanzheng_chaxun::returnIndex()
{
//    Index *menu=new Index();
//    menu->show();
    this->close();
}

void Buwanzheng_chaxun::returnPage()
{
    Buwanzheng *returnPage=new Buwanzheng();
    returnPage->show();
    this->close();
}
