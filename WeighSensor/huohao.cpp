#include "huohao.h"
#include "ui_huohao.h"

Huohao::Huohao(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Huohao)
{
    ui->setupUi(this);
}

Huohao::~Huohao()
{
    delete ui;
}
