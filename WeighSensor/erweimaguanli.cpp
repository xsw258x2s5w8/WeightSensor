#include "erweimaguanli.h"
#include "ui_erweimaguanli.h"
#include "page2.h"
#include "index.h"
#include "erweimashengcheng.h"
#include "erweimachaxun.h"

Erweimaguanli::Erweimaguanli(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Erweimaguanli)
{
    ui->setupUi(this);
    this->setWindowState(Qt::WindowFullScreen);

    connect(ui->returnIndex,SIGNAL(clicked()),this,SLOT(returnIndex()));
    connect(ui->returnPage_2,SIGNAL(clicked()),this,SLOT(returnPage()));
    connect(ui->generateQRcode,SIGNAL(clicked()),this,SLOT(showGenerateQR()));
    connect(ui->findQRcode,SIGNAL(clicked()),this,SLOT(showFindQR()));
}

Erweimaguanli::~Erweimaguanli()
{
    delete ui;
}

void Erweimaguanli::returnIndex()
{
//    Index *menu=new Index();
//    menu->show();
    this->close();
}

void Erweimaguanli::returnPage()
{
    page2 *returnPage=new page2();
    returnPage->show();
    this->close();
}

void Erweimaguanli::showGenerateQR()
{
    Erweimashengcheng *showGenerateQR=new Erweimashengcheng();
    showGenerateQR->show();
    this->close();
}

void Erweimaguanli::showFindQR()
{
    Erweimachaxun *showFindQR=new Erweimachaxun();
    showFindQR->show();
    this->close();
}
