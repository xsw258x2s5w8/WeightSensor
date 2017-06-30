#include "yitaiwangshezhi.h"
#include "ui_yitaiwangshezhi.h"
#include "wangluoshezhi.h"
#include "index.h"

Yitaiwangshezhi::Yitaiwangshezhi(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Yitaiwangshezhi)
{
    ui->setupUi(this);
    connect(ui->returnIndex,SIGNAL(clicked()),this,SLOT(returnIndex()));
    connect(ui->returnPage,SIGNAL(clicked()),this,SLOT(returnPage()));
}

Yitaiwangshezhi::~Yitaiwangshezhi()
{
    delete ui;
}

void Yitaiwangshezhi::returnIndex()
{
    Index *menu=new Index();
    menu->show();
    this->close();
}

void Yitaiwangshezhi::returnPage()
{
    Wangluoshezhi *returnPage=new Wangluoshezhi();
    returnPage->show();
    this->close();
}
