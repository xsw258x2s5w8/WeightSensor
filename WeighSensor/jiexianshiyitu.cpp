#include "jiexianshiyitu.h"
#include "ui_jiexianshiyitu.h"
#include "index.h"
#include "page3.h"

Jiexianshiyitu::Jiexianshiyitu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Jiexianshiyitu)
{
    ui->setupUi(this);
    this->setWindowState(Qt::WindowFullScreen);

    connect(ui->returnIndex,SIGNAL(clicked()),this,SLOT(returnIndex()));
    connect(ui->returnPage,SIGNAL(clicked()),this,SLOT(returnPage()));
}

Jiexianshiyitu::~Jiexianshiyitu()
{
    delete ui;
}

void Jiexianshiyitu::returnIndex()
{
//    Index *menu=new Index();
//    menu->show();
    this->close();
}

void Jiexianshiyitu::returnPage()
{
    Page3 *returnPage=new Page3();
    returnPage->show();
    this->close();
}
