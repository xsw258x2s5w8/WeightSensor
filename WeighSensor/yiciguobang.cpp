#include "yiciguobang.h"
#include "ui_yiciguobang.h"
#include "index.h"
#include "index.h"

Yiciguobang::Yiciguobang(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Yiciguobang)
{
    ui->setupUi(this);
    connect(ui->returnIndex,SIGNAL(clicked()),this,SLOT(returnIndex()));
    connect(ui->returnPage,SIGNAL(clicked()),this,SLOT(returnPage()));
}

Yiciguobang::~Yiciguobang()
{
    delete ui;
}

void Yiciguobang::returnIndex()
{
    Index *menu=new Index();
    menu->show();
    this->close();
}

void Yiciguobang::returnPage()
{
    Index *menu=new Index();
    menu->show();
    this->close();
}
