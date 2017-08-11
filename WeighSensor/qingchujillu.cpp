#include "qingchujillu.h"
#include "ui_qingchujillu.h"
#include "index.h"
#include "lishijilu.h"

Qingchujillu::Qingchujillu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Qingchujillu)
{
    ui->setupUi(this);
    this->setWindowState(Qt::WindowFullScreen);

    connect(ui->returnIndex,SIGNAL(clicked()),this,SLOT(returnIndex()));
    connect(ui->returnPage,SIGNAL(clicked()),this,SLOT(returnPage()));
}

Qingchujillu::~Qingchujillu()
{
    delete ui;
}

void Qingchujillu::returnIndex()
{
//    Index *menu=new Index();
//    menu->show();
    this->close();
}

void Qingchujillu::returnPage()
{
    Lishijilu *returnPage=new Lishijilu();
    returnPage->show();
    this->close();
}
