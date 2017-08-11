#include "jiandingshijian.h"
#include "ui_jiandingshijian.h"
#include "index.h"
#include "tiaochen_2.h"

Jiandingshijian::Jiandingshijian(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Jiandingshijian)
{
    ui->setupUi(this);
    this->setWindowState(Qt::WindowFullScreen);

    connect(ui->returnIndex,SIGNAL(clicked()),this,SLOT(returnIndex()));
    connect(ui->returnPage,SIGNAL(clicked()),this,SLOT(returnPage()));
}

Jiandingshijian::~Jiandingshijian()
{
    delete ui;
}

void Jiandingshijian::returnIndex()
{
//    Index *menu=new Index();
//    menu->show();
    this->close();
}

void Jiandingshijian::returnPage()
{
    Tiaochen_2 *returnPage=new Tiaochen_2();
    returnPage->show();
    this->close();
}
