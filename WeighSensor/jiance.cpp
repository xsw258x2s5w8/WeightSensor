#include "jiance.h"
#include "ui_jiance.h"
#include "index.h"
#include "page2.h"

Jiance::Jiance(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Jiance)
{
    ui->setupUi(this);
    connect(ui->returnIndex,SIGNAL(clicked()),this,SLOT(returnIndex()));
    connect(ui->returnPage,SIGNAL(clicked()),this,SLOT(returnPage()));
}

Jiance::~Jiance()
{
    delete ui;
}

void Jiance::returnIndex()
{
    Index *menu=new Index();
    menu->show();
    this->close();
}

void Jiance::returnPage()
{
    page2 *returnPage=new page2();
    returnPage->show();
    this->close();
}
