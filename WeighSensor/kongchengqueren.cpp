#include "kongchengqueren.h"
#include "ui_kongchengqueren.h"
#include "index.h"
#include "zidongzuwang.h"
#include "yajiaoquerendizhi.h"
Kongchengqueren::Kongchengqueren(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Kongchengqueren)
{
    ui->setupUi(this);
    connect(ui->returnIndex,SIGNAL(clicked()),this,SLOT(returnIndex()));
    connect(ui->returnPage,SIGNAL(clicked()),this,SLOT(returnPage()));
    connect(ui->confirm,SIGNAL(clicked()),this,SLOT(showAngleAddress()));
}

Kongchengqueren::~Kongchengqueren()
{
    delete ui;
}

void Kongchengqueren::returnIndex()
{
    Index *menu=new Index();
    menu->show();
    this->close();
}

void Kongchengqueren::returnPage()
{
    Zidongzuwang *returnPage=new Zidongzuwang();
    returnPage->show();
    this->close();
}

void Kongchengqueren::showAngleAddress()
{
    Yajiaoquerendizhi *showAngleAddress=new Yajiaoquerendizhi();
    showAngleAddress->show();
    this->close();
}

