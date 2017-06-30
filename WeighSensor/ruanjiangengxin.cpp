#include "ruanjiangengxin.h"
#include "ui_ruanjiangengxin.h"
#include "index.h"
#include "page3.h"

Ruanjiangengxin::Ruanjiangengxin(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Ruanjiangengxin)
{
    ui->setupUi(this);
    connect(ui->returnIndex,SIGNAL(clicked()),this,SLOT(returnIndex()));
    connect(ui->returnPage,SIGNAL(clicked()),this,SLOT(returnPage()));
}

Ruanjiangengxin::~Ruanjiangengxin()
{
    delete ui;
}

void Ruanjiangengxin::returnIndex()
{
    Index *menu=new Index();
    menu->show();
    this->close();
}

void Ruanjiangengxin::returnPage()
{
    Page3 *returnPage=new Page3();
    returnPage->show();
    this->close();
}
