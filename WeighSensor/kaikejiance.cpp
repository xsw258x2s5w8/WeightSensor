#include "kaikejiance.h"
#include "ui_kaikejiance.h"
#include "index.h"
#include "jiance2.h"

Kaikejiance::Kaikejiance(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Kaikejiance)
{
    ui->setupUi(this);
    this->setWindowState(Qt::WindowFullScreen);

    connect(ui->returnIndex,SIGNAL(clicked()),this,SLOT(returnIndex()));
    connect(ui->returnPage,SIGNAL(clicked()),this,SLOT(returnPage()));
}

Kaikejiance::~Kaikejiance()
{
    delete ui;
}

void Kaikejiance::returnIndex()
{
//    Index *menu=new Index();
//    menu->show();
    this->close();
}

void Kaikejiance::returnPage()
{
    Jiance2 *returnPage=new Jiance2();
    returnPage->show();
    this->close();
}
