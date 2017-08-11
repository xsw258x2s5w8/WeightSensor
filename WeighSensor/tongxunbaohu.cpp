#include "tongxunbaohu.h"
#include "ui_tongxunbaohu.h"
#include "index.h"
#include "tiaochen_2.h"

Tongxunbaohu::Tongxunbaohu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Tongxunbaohu)
{
    ui->setupUi(this);
    this->setWindowState(Qt::WindowFullScreen);

    connect(ui->returnIndex_2,SIGNAL(clicked()),this,SLOT(returnIndex()));
    connect(ui->returnPage_2,SIGNAL(clicked()),this,SLOT(returnPage()));
}

Tongxunbaohu::~Tongxunbaohu()
{
    delete ui;
}

void Tongxunbaohu::returnIndex()
{
//    Index *menu=new Index();
//    menu->show();
    this->close();
}

void Tongxunbaohu::returnPage()
{
    Tiaochen_2 *returnPage=new Tiaochen_2();
    returnPage->show();
    this->close();
}
