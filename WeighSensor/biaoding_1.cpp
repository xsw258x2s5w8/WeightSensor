#include "biaoding_1.h"
#include "ui_biaoding_1.h"
#include "index.h"
#include "biaoding.h"
#include "biaoding_2.h"

Biaoding_1::Biaoding_1(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Biaoding_1)
{
    ui->setupUi(this);
    connect(ui->returnIndex,SIGNAL(clicked()),this,SLOT(returnIndex()));
    connect(ui->returnPage,SIGNAL(clicked()),this,SLOT(returnPage()));
    connect(ui->confirm,SIGNAL(clicked()),this,SLOT(showConfirmCalibration()));
    connect(ui->skip,SIGNAL(clicked()),this,SLOT(showSkipCalibration()));
}

Biaoding_1::~Biaoding_1()
{
    delete ui;
}

void Biaoding_1::returnIndex()
{
    Index *menu=new Index();
    menu->show();
    this->close();
}

void Biaoding_1::returnPage()
{
    Biaoding *returnPage=new Biaoding();
    returnPage->show();
    this->close();
}

void Biaoding_1::showConfirmCalibration()
{
    Biaoding_2 *showConfirmCalibration=new Biaoding_2();
    showConfirmCalibration->show();
    this->close();
}

void Biaoding_1::showSkipCalibration()
{
    Biaoding_2 *showSkipCalibration=new Biaoding_2();
    showSkipCalibration->show();
    this->close();
}
