#include "caishubeifen.h"
#include "ui_caishubeifen.h"
#include "index.h"
#include "tiaochen.h"

Caishubeifen::Caishubeifen(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Caishubeifen)
{
    ui->setupUi(this);
    this->setWindowState(Qt::WindowFullScreen);

    connect(ui->returnIndex,SIGNAL(clicked()),this,SLOT(returnIndex()));
    connect(ui->returnPage,SIGNAL(clicked()),this,SLOT(returnPage()));
}

Caishubeifen::~Caishubeifen()
{
    delete ui;
}

void Caishubeifen::returnIndex()
{
//    Index *menu=new Index();
//    menu->show();
    this->close();
}

void Caishubeifen::returnPage()
{
    Tiaochen *returnPage=new Tiaochen();
    returnPage->show();
    this->close();
}
