#include "shiboqi.h"
#include "ui_shiboqi.h"
#include "index.h"

Shiboqi::Shiboqi(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Shiboqi)
{
    ui->setupUi(this);
    this->setWindowState(Qt::WindowFullScreen);

    connect(ui->returnIndex,SIGNAL(clicked()),this,SLOT(returnIndex()));
    connect(ui->returnPage,SIGNAL(clicked()),this,SLOT(returnPage()));
}

Shiboqi::~Shiboqi()
{
    delete ui;
}

void Shiboqi::returnIndex()
{
//    Index *menu=new Index();
//    menu->show();
    this->close();
}

void Shiboqi::returnPage()
{
    Index *returnPage=new Index();
    returnPage->show();
    this->close();
}
