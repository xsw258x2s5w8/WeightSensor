#include "shuliangyuxieyi.h"
#include "ui_shuliangyuxieyi.h"
#include "index.h"
#include "dizhi.h"
Shuliangyuxieyi::Shuliangyuxieyi(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Shuliangyuxieyi)
{
    ui->setupUi(this);
    connect(ui->returnIndex,SIGNAL(clicked()),this,SLOT(returnIndex()));
    connect(ui->returnPage,SIGNAL(clicked()),this,SLOT(returnPage()));
}

Shuliangyuxieyi::~Shuliangyuxieyi()
{
    delete ui;
}

void Shuliangyuxieyi::returnIndex()
{
    Index *menu=new Index();
    menu->show();
    this->close();
}

void Shuliangyuxieyi::returnPage()
{
    Dizhi *returnPage=new Dizhi();
    returnPage->show();
    this->close();
}
