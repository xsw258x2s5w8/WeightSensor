#include "shouhou.h"
#include "ui_shouhou.h"
#include "jiance.h"
#include "index.h"
Shouhou::Shouhou(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Shouhou)
{
    ui->setupUi(this);
    connect(ui->returnIndex,SIGNAL(clicked()),this,SLOT(returnIndex()));
    connect(ui->returnPage,SIGNAL(clicked()),this,SLOT(returnPage()));
}

Shouhou::~Shouhou()
{
    delete ui;
}

void Shouhou::returnIndex()
{
    Index *menu=new Index();
    menu->show();
    this->close();
}

void Shouhou::returnPage()
{
    Jiance *returnPage=new Jiance();
    returnPage->show();
    this->close();
}
