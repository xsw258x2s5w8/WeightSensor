#include "yazhouqueren.h"
#include "ui_yazhouqueren.h"
#include "zidongzhoujiaocha.h"
#include "index.h"

Yazhouqueren::Yazhouqueren(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Yazhouqueren)
{
    ui->setupUi(this);
    this->setWindowState(Qt::WindowFullScreen);

    connect(ui->returnIndex,SIGNAL(clicked()),this,SLOT(returnIndex()));
    connect(ui->returnPage,SIGNAL(clicked()),this,SLOT(returnPage()));
}

Yazhouqueren::~Yazhouqueren()
{
    delete ui;
}

void Yazhouqueren::returnIndex()
{
//    Index *menu=new Index();
//    menu->show();
    this->close();
}

void Yazhouqueren::returnPage()
{
    Zidongzhoujiaocha *returnPage=new Zidongzhoujiaocha();
    returnPage->show();
    this->close();
}
