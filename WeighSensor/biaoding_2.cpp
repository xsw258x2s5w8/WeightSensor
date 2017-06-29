#include "biaoding_2.h"
#include "ui_biaoding_2.h"
#include "index.h"
#include "biaoding_1.h"

Biaoding_2::Biaoding_2(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Biaoding_2)
{
    ui->setupUi(this);
    connect(ui->returnIndex,SIGNAL(clicked()),this,SLOT(returnIndex()));
    connect(ui->returnPage,SIGNAL(clicked()),this,SLOT(returnPage()));
}

Biaoding_2::~Biaoding_2()
{
    delete ui;
}

void Biaoding_2::returnIndex()
{
    Index *menu=new Index();
    menu->show();
    this->close();
}

void Biaoding_2::returnPage()
{
    Biaoding_1 *returnPage=new Biaoding_1();
    returnPage->show();
    this->close();
}
