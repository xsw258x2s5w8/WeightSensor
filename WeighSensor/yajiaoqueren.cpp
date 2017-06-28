#include "yajiaoqueren.h"
#include "ui_yajiaoqueren.h"
#include "index.h"
#include "zidongtiaojiaocha.h"

Yajiaoqueren::Yajiaoqueren(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Yajiaoqueren)
{
    ui->setupUi(this);
    connect(ui->returnIndex,SIGNAL(clicked()),this,SLOT(returnIndex()));
    connect(ui->returnPage,SIGNAL(clicked()),this,SLOT(returnPage()));
}

Yajiaoqueren::~Yajiaoqueren()
{
    delete ui;
}

void Yajiaoqueren::returnIndex()
{
    Index *menu=new Index();
    menu->show();
    this->close();
}

void Yajiaoqueren::returnPage()
{
    Zidongtiaojiaocha *returnPage=new Zidongtiaojiaocha();
    returnPage->show();
    this->close();
}
