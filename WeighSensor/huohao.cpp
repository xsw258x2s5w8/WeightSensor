#include "huohao.h"
#include "ui_huohao.h"
#include "huohaoshezhi.h"

Huohao::Huohao(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Huohao)
{
    ui->setupUi(this);
   // this->setWindowState(Qt::WindowFullScreen);

    connect(ui->store,SIGNAL(clicked()),this,SLOT(close()));
    connect(ui->cancel,SIGNAL(clicked()),this,SLOT(close()));
    connect(ui->artno1,SIGNAL(clicked()),this,SLOT(showhuohaoshezhi()));
}

Huohao::~Huohao()
{
    delete ui;
}

void Huohao::showhuohaoshezhi()
{
    Huohaoshezhi *showhuohaoshezhi = new Huohaoshezhi();
    showhuohaoshezhi->show();
}
