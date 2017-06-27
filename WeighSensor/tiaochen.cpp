#include "tiaochen.h"
#include "ui_tiaochen.h"
#include "index.h"
#include "page2.h"

Tiaochen::Tiaochen(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Tiaochen)
{
    ui->setupUi(this);
    connect(ui->returnIndex_2,SIGNAL(clicked()),this,SLOT(returnIndex()));
    connect(ui->returnPage_2,SIGNAL(clicked()),this,SLOT(returnPage()));
}

Tiaochen::~Tiaochen()
{
    delete ui;
}

void Tiaochen::returnIndex()
{
    Index *menu=new Index();
    menu->show();
    this->close();
}

void Tiaochen::returnPage()
{
    page2 *returnPage=new page2();
    returnPage->show();
    this->close();
}


