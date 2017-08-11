#include "shuruxishutioajiao.h"
#include "ui_shuruxishutioajiao.h"
#include "index.h"
#include "tiaojiao.h"
#include "shuruxishu.h"

Shuruxishutioajiao::Shuruxishutioajiao(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Shuruxishutioajiao)
{
    ui->setupUi(this);
    this->setWindowState(Qt::WindowFullScreen);

    connect(ui->returnIndex,SIGNAL(clicked()),this,SLOT(returnIndex()));
    connect(ui->returnPage,SIGNAL(clicked()),this,SLOT(returnPage()));
    connect(ui->confirm,SIGNAL(clicked()),this,SLOT(showValue()));
}

Shuruxishutioajiao::~Shuruxishutioajiao()
{
    delete ui;
}

void Shuruxishutioajiao::returnIndex()
{
//    Index *index=new Index();
//    index->show();
    this->close();
}

void Shuruxishutioajiao::returnPage()
{
    Tiaojiao *returnPage=new Tiaojiao();
    returnPage->show();
    this->close();
}

void Shuruxishutioajiao::showValue()
{
    Shuruxishu *showValue=new Shuruxishu();
    showValue->show();
    this->close();
}
