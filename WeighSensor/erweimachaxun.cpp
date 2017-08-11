#include "erweimachaxun.h"
#include "ui_erweimachaxun.h"
#include "index.h"
#include "erweimaguanli.h"

Erweimachaxun::Erweimachaxun(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Erweimachaxun)
{
    ui->setupUi(this);
    this->setWindowState(Qt::WindowFullScreen);

    connect(ui->returnIndex,SIGNAL(clicked()),this,SLOT(returnIndex()));
    connect(ui->returnPage,SIGNAL(clicked()),this,SLOT(returnPage()));
}

Erweimachaxun::~Erweimachaxun()
{
    delete ui;
}

void Erweimachaxun::returnIndex()
{
//    Index *menu=new Index();
//    menu->show();
    this->close();
}

void Erweimachaxun::returnPage()
{
    Erweimaguanli *returnPage=new Erweimaguanli();
    returnPage->show();
    this->close();
}
