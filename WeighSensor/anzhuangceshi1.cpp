#include "anzhuangceshi1.h"
#include "ui_anzhuangceshi1.h"
#include "anzhuangceshi.h"
#include "index.h"

Anzhuangceshi1::Anzhuangceshi1(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Anzhuangceshi1)
{
    ui->setupUi(this);
    this->setWindowState(Qt::WindowFullScreen);

    connect(ui->returnIndex,SIGNAL(clicked()),this,SLOT(returnIndex()));
    connect(ui->returnPage,SIGNAL(clicked()),this,SLOT(returnPage()));
}

Anzhuangceshi1::~Anzhuangceshi1()
{
    delete ui;
}

void Anzhuangceshi1::returnIndex()
{
//    Index *menu=new Index();
//    menu->show();
    this->close();
}

void Anzhuangceshi1::returnPage()
{
    Anzhuangceshi *returnPage=new Anzhuangceshi();
    returnPage->show();
    this->close();
}
