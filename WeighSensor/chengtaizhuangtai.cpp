#include "chengtaizhuangtai.h"
#include "ui_chengtaizhuangtai.h"
#include "index.h"
#include "tiaochen.h"

Chengtaizhuangtai::Chengtaizhuangtai(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Chengtaizhuangtai)
{
    ui->setupUi(this);
    connect(ui->returnIndex,SIGNAL(clicked()),this,SLOT(returnIndex()));
    connect(ui->returnPage,SIGNAL(clicked()),this,SLOT(returnPage()));
}

Chengtaizhuangtai::~Chengtaizhuangtai()
{
    delete ui;
}

void Chengtaizhuangtai::returnIndex()
{
    Index *menu=new Index();
    menu->show();
    this->close();
}

void Chengtaizhuangtai::returnPage()
{
    Tiaochen *returnPage=new Tiaochen();
    returnPage->show();
    this->close();
}
