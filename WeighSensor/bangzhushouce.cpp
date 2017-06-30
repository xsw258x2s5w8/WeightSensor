#include "bangzhushouce.h"
#include "ui_bangzhushouce.h"
#include "index.h"
#include "page3.h"
#include "bangzhushouce1.h"

Bangzhushouce::Bangzhushouce(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Bangzhushouce)
{
    ui->setupUi(this);
    connect(ui->returnIndex,SIGNAL(clicked()),this,SLOT(returnIndex()));
    connect(ui->returnPage,SIGNAL(clicked()),this,SLOT(returnPage()));
    connect(ui->next,SIGNAL(clicked()),this,SLOT(showNext()));
}

Bangzhushouce::~Bangzhushouce()
{
    delete ui;
}

void Bangzhushouce::returnIndex()
{
    Index *menu=new Index();
    menu->show();
    this->close();
}

void Bangzhushouce::returnPage()
{
    Page3 *returnPage=new Page3();
    returnPage->show();
    this->close();
}

void Bangzhushouce::showNext()
{
    Bangzhushouce1 *showNext=new Bangzhushouce1();
    showNext->show();
    this->close();
}
