#include "page2.h"
#include "ui_page2.h"
#include "index.h"

page2::page2(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::page2)
{
    ui->setupUi(this);
    connect(ui->returnIndex,SIGNAL(clicked()),this,SLOT(returnIndex()));
}

page2::~page2()
{
    delete ui;
}

void page2::returnIndex()
{   Index *index=new Index();
    index->show();
    this->close();
}
