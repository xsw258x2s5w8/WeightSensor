#include "erciguobang.h"
#include "ui_erciguobang.h"
#include "index.h"
#include "index.h"

Erciguobang::Erciguobang(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Erciguobang)
{
    ui->setupUi(this);

    carid=new Erciguobang_car();
    connect(carid,SIGNAL(sendCarId(QString)),this,SLOT(getCarData(QString)));

    //按钮槽
    connect(ui->returnIndex,SIGNAL(clicked()),this,SLOT(returnIndex()));
    connect(ui->returnPage,SIGNAL(clicked()),this,SLOT(returnPage()));
    connect(ui->caridbtn,SIGNAL(clicked()),this,SLOT(showCarData()));
}

Erciguobang::~Erciguobang()
{
    delete ui;
}

void Erciguobang::getCarData(QString data)
{
    ui->lineEdit_car->setText(data);
}

void Erciguobang::getArtData(QString data)
{
    ui->lineEdit_art->setText(data);
}

void Erciguobang::getRemarkData(QString data)
{
    ui->lineEdit_remark->setText(data);
}

void Erciguobang::returnIndex()
{
    Index *menu=new Index();
    menu->show();
    this->close();
}

void Erciguobang::returnPage()
{
    Index *menu=new Index();
    menu->show();
    this->close();
}

void Erciguobang::showCarData()
{
    carid->show();
}
