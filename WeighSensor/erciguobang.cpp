#include "erciguobang.h"
#include "ui_erciguobang.h"
#include "index.h"
#include "index.h"

Erciguobang::Erciguobang(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Erciguobang)
{
    ui->setupUi(this);
    connect(ui->returnIndex,SIGNAL(clicked()),this,SLOT(returnIndex()));
    connect(ui->returnPage,SIGNAL(clicked()),this,SLOT(returnPage()));
}

Erciguobang::~Erciguobang()
{
    delete ui;
}

void Erciguobang::returnIndex()
{
    Index *menu=new Index();
    menu->show();
    this->close();
}

void Erciguobang::returnPage()
{
    Index *menu=new Index();
    menu->show();
    this->close();
}
