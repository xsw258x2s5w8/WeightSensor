#include "chushihua.h"
#include "ui_chushihua.h"
#include "index.h"
#include "page3.h"

Chushihua::Chushihua(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Chushihua)
{
    ui->setupUi(this);
    this->setWindowState(Qt::WindowFullScreen);

    connect(ui->returnIndex,SIGNAL(clicked()),this,SLOT(returnIndex()));
    connect(ui->returnPage,SIGNAL(clicked()),this,SLOT(returnPage()));
}

Chushihua::~Chushihua()
{
    delete ui;
}

void Chushihua::returnIndex()
{
//    Index *menu=new Index();
//    menu->show();
    this->close();
}

void Chushihua::returnPage()
{
    Page3 *returnPage=new Page3();
    returnPage->show();
    this->close();
}
