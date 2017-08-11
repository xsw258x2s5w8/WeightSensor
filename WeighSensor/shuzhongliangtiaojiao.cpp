#include "shuzhongliangtiaojiao.h"
#include "ui_shuzhongliangtiaojiao.h"
#include "index.h"
#include "tiaojiao.h"
#include "shuruzhongliang.h"

Shuzhongliangtiaojiao::Shuzhongliangtiaojiao(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Shuzhongliangtiaojiao)
{
    ui->setupUi(this);
    this->setWindowState(Qt::WindowFullScreen);

    connect(ui->returnIndex,SIGNAL(clicked()),this,SLOT(returnIndex()));
    connect(ui->returnPage,SIGNAL(clicked()),this,SLOT(returnPage()));
    connect(ui->confirm,SIGNAL(clicked()),this,SLOT(showSetWeight()));
}

Shuzhongliangtiaojiao::~Shuzhongliangtiaojiao()
{
    delete ui;
}

void Shuzhongliangtiaojiao::returnIndex()
{
//    Index *index=new Index();
//    index->show();
    this->close();
}

void Shuzhongliangtiaojiao::returnPage()
{
    Tiaojiao *returnPage=new Tiaojiao();
    returnPage->show();
    this->close();
}

void Shuzhongliangtiaojiao::showSetWeight()
{
    Shuruzhongliang *showSetWeight=new Shuruzhongliang();
    showSetWeight->show();
    this->close();
}
