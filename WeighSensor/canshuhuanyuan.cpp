#include "canshuhuanyuan.h"
#include "ui_canshuhuanyuan.h"
#include "index.h"
#include "tiaochen.h"

Canshuhuanyuan::Canshuhuanyuan(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Canshuhuanyuan)
{
    ui->setupUi(this);
    this->setWindowState(Qt::WindowFullScreen);

    connect(ui->returnIndex,SIGNAL(clicked()),this,SLOT(returnIndex()));
    connect(ui->returnPage,SIGNAL(clicked()),this,SLOT(returnPage()));
}

Canshuhuanyuan::~Canshuhuanyuan()
{
    delete ui;
}

void Canshuhuanyuan::returnIndex()
{
//    Index *menu=new Index();
//    menu->show();
    this->close();
}

void Canshuhuanyuan::returnPage()
{
    Tiaochen *returnPage=new Tiaochen();
    returnPage->show();
    this->close();
}
