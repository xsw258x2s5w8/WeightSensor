#include "anzhuangceshi.h"
#include "ui_anzhuangceshi.h"

Anzhuangceshi::Anzhuangceshi(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Anzhuangceshi)
{
    ui->setupUi(this);
}

Anzhuangceshi::~Anzhuangceshi()
{
    delete ui;
}
