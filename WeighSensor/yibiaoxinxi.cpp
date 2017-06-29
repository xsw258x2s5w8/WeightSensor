#include "yibiaoxinxi.h"
#include "ui_yibiaoxinxi.h"
#include "index.h"
#include "jiance.h"

Yibiaoxinxi::Yibiaoxinxi(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Yibiaoxinxi)
{
    ui->setupUi(this);
    connect(ui->returnIndex,SIGNAL(clicked()),this,SLOT(returnIndex()));
    connect(ui->returnPage,SIGNAL(clicked()),this,SLOT(returnPage()));
}

Yibiaoxinxi::~Yibiaoxinxi()
{
    delete ui;
}

void Yibiaoxinxi::returnIndex()
{
    Index *menu=new Index();
    menu->show();
    this->close();
}

void Yibiaoxinxi::returnPage()
{
    Jiance *returnPage=new Jiance();
    returnPage->show();
    this->close();
}
