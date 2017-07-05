#include "huohaoshezhi.h"
#include "ui_huohaoshezhi.h"

Huohaoshezhi::Huohaoshezhi(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Huohaoshezhi)
{
    ui->setupUi(this);
    connect(ui->store,SIGNAL(clicked()),this,SLOT(close()));
}

Huohaoshezhi::~Huohaoshezhi()
{
    delete ui;
}
