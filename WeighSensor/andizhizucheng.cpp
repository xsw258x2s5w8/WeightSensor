#include "andizhizucheng.h"
#include "ui_andizhizucheng.h"
#include "index.h"
#include "dizhi.h"
#include "andizhizucheng2.h"

Andizhizucheng::Andizhizucheng(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Andizhizucheng)
{
    ui->setupUi(this);
    connect(ui->returnIndex,SIGNAL(clicked()),this,SLOT(returnIndex()));
    connect(ui->returnPage,SIGNAL(clicked()),this,SLOT(returnPage()));
    connect(ui->confirm,SIGNAL(clicked()),this,SLOT(showAddress()));
}

Andizhizucheng::~Andizhizucheng()
{
    delete ui;
}

void Andizhizucheng::returnIndex()
{
    Index *menu=new Index();
    menu->show();
    this->close();
}

void Andizhizucheng::returnPage()
{
    Dizhi *returnPage=new Dizhi();
    returnPage->show();
    this->close();
}

void Andizhizucheng::showAddress()
{
    Andizhizucheng2 *showAddress=new Andizhizucheng2();
    showAddress->show();
    this->close();
}
