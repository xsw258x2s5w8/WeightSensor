#include "lishijilu.h"
#include "ui_lishijilu.h"
#include "index.h"
#include "index.h"

Lishijilu::Lishijilu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Lishijilu)
{
    ui->setupUi(this);
    connect(ui->returnIndex,SIGNAL(clicked()),this,SLOT(returnIndex()));
    connect(ui->returnPage,SIGNAL(clicked()),this,SLOT(returnPage()));
}

Lishijilu::~Lishijilu()
{
    delete ui;
}

void Lishijilu::returnIndex()
{
    Index *menu=new Index();
    menu->show();
    this->close();
}

void Lishijilu::returnPage()
{
    Index *returnPage=new Index();
    returnPage->show();
    this->close();
}
