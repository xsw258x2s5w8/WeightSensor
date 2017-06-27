#include "tiaochen.h"
#include "ui_tiaochen.h"
#include "index.h"

Tiaochen::Tiaochen(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Tiaochen)
{
    ui->setupUi(this);
    connect(ui->returnIndex_2,SIGNAL(clicked()),this,SLOT(showMenuWidget()));
}

Tiaochen::~Tiaochen()
{
    delete ui;
}

void Tiaochen::showMenuWidget()
{
    Index *menu=new Index();
    menu->show();
    this->close();
}
