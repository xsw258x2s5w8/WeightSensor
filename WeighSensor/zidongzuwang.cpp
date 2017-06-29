#include "zidongzuwang.h"
#include "ui_zidongzuwang.h"
#include "index.h"
#include "dizhi.h"
#include "kongchengqueren.h"

Zidongzuwang::Zidongzuwang(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Zidongzuwang)
{
    ui->setupUi(this);
    connect(ui->returnIndex,SIGNAL(clicked()),this,SLOT(returnIndex()));
    connect(ui->returnPage,SIGNAL(clicked()),this,SLOT(returnPage()));
    connect(ui->save,SIGNAL(clicked()),this,SLOT(showKongcheng()));
}

Zidongzuwang::~Zidongzuwang()
{
    delete ui;
}

void Zidongzuwang::returnIndex()
{
    Index *menu=new Index();
    menu->show();
    this->close();
}

void Zidongzuwang::returnPage()
{
    Dizhi *returnPage=new Dizhi();
    returnPage->show();
    this->close();
}

void Zidongzuwang::showKongcheng()
{
    Kongchengqueren *showKongcheng=new Kongchengqueren();
    showKongcheng->show();
    this->close();
}
