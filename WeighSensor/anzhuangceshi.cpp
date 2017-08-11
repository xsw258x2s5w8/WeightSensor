#include "anzhuangceshi.h"
#include "ui_anzhuangceshi.h"
#include "index.h"
#include "tiaochen.h"
#include "anzhuangceshi1.h"

Anzhuangceshi::Anzhuangceshi(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Anzhuangceshi)
{
    ui->setupUi(this);
    this->setWindowState(Qt::WindowFullScreen);

    connect(ui->returnIndex,SIGNAL(clicked()),this,SLOT(returnIndex()));
    connect(ui->returnPage,SIGNAL(clicked()),this,SLOT(returnPage()));
    connect(ui->information,SIGNAL(clicked()),this,SLOT(showInformation()));
}

Anzhuangceshi::~Anzhuangceshi()
{
    delete ui;
}

void Anzhuangceshi::returnIndex()
{
//    Index *menu=new Index();
//    menu->show();
    this->close();
}

void Anzhuangceshi::returnPage()
{
    Tiaochen *returnPage=new Tiaochen();
    returnPage->show();
    this->close();
}

void Anzhuangceshi::showInformation()
{
    Anzhuangceshi1 *showInformation=new Anzhuangceshi1();
    showInformation->show();
    this->close();
}
