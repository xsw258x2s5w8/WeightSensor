#include "erciguobang_car.h"
#include "ui_erciguobang_car.h"


Erciguobang_car::Erciguobang_car(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Erciguobang_car)
{
    ui->setupUi(this);

    carName1=new Erciguobang_carName1();
    connect(carName1,SIGNAL(sendCarName1(QString)),this,SLOT(returnCarName1(QString)));

    //按钮槽
    connect(ui->okbtn,SIGNAL(clicked()),this,SLOT(returnCarId()));
    connect(ui->returnPage,SIGNAL(clicked()),this,SLOT(returnPage()));
    connect(ui->carName1,SIGNAL(clicked()),this,SLOT(showCarName1()));
}

Erciguobang_car::~Erciguobang_car()
{
    delete ui;
}

void Erciguobang_car::returnCarId()
{
    emit sendCarId(ui->carName1->text()+ui->carName2->text());

    this->close();
}

void Erciguobang_car::showCarName1()
{
    carName1->show();
}

void Erciguobang_car::returnCarName1(QString data)
{
    ui->carName1->setText(data);
}

void Erciguobang_car::returnPage()
{
    this->close();
}
