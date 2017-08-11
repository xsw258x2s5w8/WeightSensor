#include "shuruzhongliang.h"
#include "ui_shuruzhongliang.h"
#include "index.h"
#include "shuzhongliangtiaojiao.h"

Shuruzhongliang::Shuruzhongliang(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Shuruzhongliang)
{
    ui->setupUi(this);
    this->setWindowState(Qt::WindowFullScreen);

    connect(ui->returnIndex,SIGNAL(clicked()),this,SLOT(returnIndex()));
    connect(ui->returnPage,SIGNAL(clicked()),this,SLOT(returnPage()));
}

Shuruzhongliang::~Shuruzhongliang()
{
    delete ui;
}

void Shuruzhongliang::returnIndex()
{
//    Index *index=new Index();
//    index->show();
    this->close();
}

void Shuruzhongliang::returnPage()
{
    Shuzhongliangtiaojiao *returnPage=new Shuzhongliangtiaojiao();
    returnPage->show();
    this->close();
}
