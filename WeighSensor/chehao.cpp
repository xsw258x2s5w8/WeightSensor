#include "chehao.h"
#include "ui_chehao.h"

Chehao::Chehao(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Chehao)
{
    ui->setupUi(this);
    //this->setWindowState(Qt::WindowFullScreen);
}

Chehao::~Chehao()
{
    delete ui;
}
