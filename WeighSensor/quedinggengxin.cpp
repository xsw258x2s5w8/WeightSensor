#include "quedinggengxin.h"
#include "ui_quedinggengxin.h"

Quedinggengxin::Quedinggengxin(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Quedinggengxin)
{
    ui->setupUi(this);
    connect(ui->update,SIGNAL(clicked()),this,SLOT(Update()));
    connect(ui->cancle,SIGNAL(clicked()),this,SLOT(Cancle()));
}

Quedinggengxin::~Quedinggengxin()
{
    delete ui;
}

void Quedinggengxin::Update()
{
    this->close();
}

void Quedinggengxin::Cancle()
{
    this->close();
}
