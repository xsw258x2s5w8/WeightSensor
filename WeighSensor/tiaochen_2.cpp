#include "tiaochen_2.h"
#include "ui_tiaochen_2.h"
#include "index.h"
#include "tiaochen.h"

Tiaochen_2::Tiaochen_2(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Tiaochen_2)
{
    ui->setupUi(this);
    connect(ui->returnIndex_2,SIGNAL(clicked()),this,SLOT(returnIndex()));
    connect(ui->returnPage_2,SIGNAL(clicked()),this,SLOT(returnPage()));
    connect(ui->preview,SIGNAL(clicked()),this,SLOT(showtiaochen()));
}

Tiaochen_2::~Tiaochen_2()
{
    delete ui;
}

void Tiaochen_2::returnIndex()
{
    Index *menu=new Index();
    menu->show();
    this->close();
}

void Tiaochen_2::returnPage()
{
    Tiaochen *returnPage=new Tiaochen();
    returnPage->show();
    this->close();
}

void Tiaochen_2::showtiaochen()
{
    Tiaochen *showtiaochen=new Tiaochen();
    showtiaochen->show();
    this->close();
}
