#include "tiaojiao.h"
#include "ui_tiaojiao.h"
#include "index.h"
#include "tiaochen.h"

Tiaojiao::Tiaojiao(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Tiaojiao)
{
    ui->setupUi(this);
    connect(ui->returnIndex,SIGNAL(clicked()),this,SLOT(returnIndex()));
    connect(ui->returnPage,SIGNAL(clicked()),this,SLOT(returnPage()));
}

Tiaojiao::~Tiaojiao()
{
    delete ui;
}

void Tiaojiao::returnIndex()
{
    Index *menu=new Index();
    menu->show();
    this->close();
}

void Tiaojiao::returnPage()
{
    Tiaochen *returnPage=new Tiaochen();
    returnPage->show();
    this->close();
}
