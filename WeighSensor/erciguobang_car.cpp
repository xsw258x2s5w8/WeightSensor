#include "erciguobang_car.h"
#include "ui_erciguobang_car.h"


Erciguobang_car::Erciguobang_car(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Erciguobang_car)
{
    ui->setupUi(this);

    connect(ui->okbtn,SIGNAL(clicked()),this,SLOT(returnCarId()));
    connect(ui->returnPage,SIGNAL(clicked()),this,SLOT(returnPage()));
}

Erciguobang_car::~Erciguobang_car()
{
    delete ui;
}

void Erciguobang_car::returnCarId()
{
    sendCarId(ui->carName1->text()+ui->carName2->text());\

    this->close();
}

void Erciguobang_car::returnPage()
{
    this->close();
}
