#include "zidongzhoujiaocha.h"
#include "ui_zidongzhoujiaocha.h"
#include "index.h"
#include "tiaojiao.h"
#include "yazhouqueren.h"

Zidongzhoujiaocha::Zidongzhoujiaocha(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Zidongzhoujiaocha)
{
    ui->setupUi(this);
    this->setWindowState(Qt::WindowFullScreen);

    connect(ui->returnIndex,SIGNAL(clicked()),this,SLOT(returnIndex()));
    connect(ui->returnPage,SIGNAL(clicked()),this,SLOT(returnPage()));
    connect(ui->confirm,SIGNAL(clicked()),this,SLOT(showconfirmAxis()));
}

Zidongzhoujiaocha::~Zidongzhoujiaocha()
{
    delete ui;
}

void Zidongzhoujiaocha::returnIndex()
{
//    Index *menu=new Index();
//    menu->show();
    this->close();
}

void Zidongzhoujiaocha::returnPage()
{
    Tiaojiao *returnPage=new Tiaojiao();
    returnPage->show();
    this->close();
}

void Zidongzhoujiaocha::showconfirmAxis()
{
    Yazhouqueren *showconfirmAxis=new Yazhouqueren();
    showconfirmAxis->show();
    this->close();
}
