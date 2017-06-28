#include "shezhi.h"
#include "ui_shezhi.h"
#include "index.h"
#include "dangeshedizhi.h"

Shezhi::Shezhi(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Shezhi)
{
    ui->setupUi(this);
    connect(ui->returnIndex,SIGNAL(clicked()),this,SLOT(returnIndex()));
    connect(ui->returnPage,SIGNAL(clicked()),this,SLOT(returnPage()));
}

Shezhi::~Shezhi()
{
    delete ui;
}

void Shezhi::returnIndex()
{
    Index *menu=new Index();
    menu->show();
    this->close();
}

void Shezhi::returnPage()
{
    Dangeshedizhi *returnPage=new Dangeshedizhi();
    returnPage->show();
    this->close();
}
