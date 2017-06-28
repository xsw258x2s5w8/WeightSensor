#include "biaoding.h"
#include "ui_biaoding.h"
#include "index.h"
#include "tiaochen.h"

Biaoding::Biaoding(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Biaoding)
{
    ui->setupUi(this);
    connect(ui->returnIndex,SIGNAL(clicked()),this,SLOT(returnIndex()));
    connect(ui->returnPage,SIGNAL(clicked()),this,SLOT(returnPage()));
}

Biaoding::~Biaoding()
{
    delete ui;
}

void Biaoding::returnIndex()
{
    Index *menu=new Index();
    menu->show();
    this->close();
}

void Biaoding::returnPage()
{
    Tiaochen *returnPage=new Tiaochen();
    returnPage->show();
    this->close();
}
