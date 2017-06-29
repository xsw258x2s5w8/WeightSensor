#include "yajiaoquerendizhi.h"
#include "ui_yajiaoquerendizhi.h"
#include "index.h"
#include "kongchengqueren.h"

Yajiaoquerendizhi::Yajiaoquerendizhi(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Yajiaoquerendizhi)
{
    ui->setupUi(this);
    connect(ui->returnIndex,SIGNAL(clicked()),this,SLOT(returnIndex()));
    connect(ui->returnPage,SIGNAL(clicked()),this,SLOT(returnPage()));
}

Yajiaoquerendizhi::~Yajiaoquerendizhi()
{
    delete ui;
}

void Yajiaoquerendizhi::returnIndex()
{
    Index *menu=new Index();
    menu->show();
    this->close();
}

void Yajiaoquerendizhi::returnPage()
{
    Kongchengqueren *returnPage=new Kongchengqueren();
    returnPage->show();
    this->close();
}
