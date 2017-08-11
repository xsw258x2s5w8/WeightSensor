#include "bangzhushouce1.h"
#include "ui_bangzhushouce1.h"
#include "index.h"
#include "bangzhushouce.h"

Bangzhushouce1::Bangzhushouce1(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Bangzhushouce1)
{
    ui->setupUi(this);
    this->setWindowState(Qt::WindowFullScreen);

    connect(ui->returnIndex,SIGNAL(clicked()),this,SLOT(returnIndex()));
    connect(ui->returnPage,SIGNAL(clicked()),this,SLOT(returnPage()));
}

Bangzhushouce1::~Bangzhushouce1()
{
    delete ui;
}

void Bangzhushouce1::returnIndex()
{
//    Index *menu=new Index();
//    menu->show();
    this->close();
}

void Bangzhushouce1::returnPage()
{
    Bangzhushouce *returnPage=new Bangzhushouce();
    returnPage->show();
    this->close();
}
