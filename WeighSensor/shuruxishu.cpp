#include "shuruxishu.h"
#include "ui_shuruxishu.h"
#include "index.h"
#include "shuruxishutioajiao.h"

Shuruxishu::Shuruxishu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Shuruxishu)
{
    ui->setupUi(this);
    this->setWindowState(Qt::WindowFullScreen);

    connect(ui->returnIndex,SIGNAL(clicked()),this,SLOT(returnIndex()));
    connect(ui->returnPage,SIGNAL(clicked()),this,SLOT(returnPage()));
}

Shuruxishu::~Shuruxishu()
{
    delete ui;
}

void Shuruxishu::returnIndex()
{
//    Index *menu=new Index();
//    menu->show();
    this->close();
}

void Shuruxishu::returnPage()
{
    Shuruxishutioajiao *returnPage=new Shuruxishutioajiao();
    returnPage->show();
    this->close();
}
