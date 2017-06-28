#include "erweimaguanli.h"
#include "ui_erweimaguanli.h"
#include "page2.h"
#include "index.h"

Erweimaguanli::Erweimaguanli(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Erweimaguanli)
{
    ui->setupUi(this);
    connect(ui->returnIndex,SIGNAL(clicked()),this,SLOT(returnIndex()));
    connect(ui->returnPage_2,SIGNAL(clicked()),this,SLOT(returnPage()));
}

Erweimaguanli::~Erweimaguanli()
{
    delete ui;
}

void Erweimaguanli::returnIndex()
{
    Index *menu=new Index();
    menu->show();
    this->close();
}

void Erweimaguanli::returnPage()
{
    page2 *returnPage=new page2();
    returnPage->show();
    this->close();
}
