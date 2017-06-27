#include "page1.h"
#include "ui_page1.h"
#include "index.h"

page1::page1(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::page1)
{
    ui->setupUi(this);
    connect(ui->returnIndex_3,SIGNAL(clicked()),this,SLOT(returnIndex()));
}

page1::~page1()
{
    delete ui;
}

void page1::returnIndex()
{
    Index *index=new Index();
    index->show();
    this->close();
}
