#include "chengtaicanshu.h"
#include "ui_chengtaicanshu.h"
#include "index.h"
#include "tiaochen.h"

Chengtaicanshu::Chengtaicanshu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Chengtaicanshu)
{
    ui->setupUi(this);
    connect(ui->returnIndex,SIGNAL(clicked()),this,SLOT(returnIndex()));
    connect(ui->returnPage,SIGNAL(clicked()),this,SLOT(returnPage()));
}

Chengtaicanshu::~Chengtaicanshu()
{
    delete ui;
}

void Chengtaicanshu::returnIndex()
{
    Index *menu=new Index();
    menu->show();
    this->close();
}

void Chengtaicanshu::returnPage()
{
    Tiaochen *returnPage=new Tiaochen();
    returnPage->show();
    this->close();
}
