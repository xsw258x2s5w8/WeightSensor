#include "zidongtiaojiaocha.h"
#include "ui_zidongtiaojiaocha.h"
#include "index.h"
#include "tiaojiao.h"
#include "yajiaoqueren.h"

Zidongtiaojiaocha::Zidongtiaojiaocha(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Zidongtiaojiaocha)
{
    ui->setupUi(this);
    connect(ui->returnIndex,SIGNAL(clicked()),this,SLOT(returnIndex()));
    connect(ui->returnPage,SIGNAL(clicked()),this,SLOT(returnPage()));
    connect(ui->confirm,SIGNAL(clicked()),this,SLOT(showconfirmWeigh()));
}

Zidongtiaojiaocha::~Zidongtiaojiaocha()
{
    delete ui;
}

void Zidongtiaojiaocha::returnIndex()
{
    Index *menu=new Index();
    menu->show();
    this->close();
}

void Zidongtiaojiaocha::returnPage()
{
    Tiaojiao *returnPage=new Tiaojiao();
    returnPage->show();
    this->close();
}

void Zidongtiaojiaocha::showconfirmWeigh()
{
    Yajiaoqueren *showconfirmWeigh=new Yajiaoqueren();
    showconfirmWeigh->show();
    this->close();
}
