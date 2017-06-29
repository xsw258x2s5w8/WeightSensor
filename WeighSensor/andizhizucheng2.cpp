#include "andizhizucheng2.h"
#include "ui_andizhizucheng2.h"
#include "index.h"
#include "andizhizucheng.h"

Andizhizucheng2::Andizhizucheng2(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Andizhizucheng2)
{
    ui->setupUi(this);
    connect(ui->returnIndex,SIGNAL(clicked()),this,SLOT(returnIndex()));
    connect(ui->returnPage,SIGNAL(clicked()),this,SLOT(returnPage()));
}

Andizhizucheng2::~Andizhizucheng2()
{
    delete ui;
}

void Andizhizucheng2::returnIndex()
{
    Index *menu=new Index();
    menu->show();
    this->close();
}

void Andizhizucheng2::returnPage()
{
    Andizhizucheng *returnPage=new Andizhizucheng();
    returnPage->show();
    this->close();
}
