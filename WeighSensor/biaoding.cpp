#include "biaoding.h"
#include "ui_biaoding.h"
#include "index.h"
#include "tiaochen.h"
#include "biaoding_1.h"

Biaoding::Biaoding(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Biaoding)
{
    ui->setupUi(this);
    connect(ui->returnIndex,SIGNAL(clicked()),this,SLOT(returnIndex()));
    connect(ui->returnPage,SIGNAL(clicked()),this,SLOT(returnPage()));
    connect(ui->confirm,SIGNAL(clicked()),this,SLOT(showCalibration()));
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

void Biaoding::showCalibration()
{
    Biaoding_1 *showCalibration=new Biaoding_1();
    showCalibration->show();
    this->close();
}
