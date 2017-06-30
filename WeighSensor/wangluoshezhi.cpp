#include "wangluoshezhi.h"
#include "ui_wangluoshezhi.h"
#include "page3.h"
#include "index.h"
#include "yitaiwangshezhi.h"

Wangluoshezhi::Wangluoshezhi(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Wangluoshezhi)
{
    ui->setupUi(this);
    connect(ui->returnIndex,SIGNAL(clicked()),this,SLOT(returnIndex()));
    connect(ui->returnPage,SIGNAL(clicked()),this,SLOT(returnPage()));
    connect(ui->setEthernet,SIGNAL(clicked()),this,SLOT(showEthernet()));
}

Wangluoshezhi::~Wangluoshezhi()
{
    delete ui;
}

void Wangluoshezhi::returnIndex()
{
    Index *menu=new Index();
    menu->show();
    this->close();
}

void Wangluoshezhi::returnPage()
{
    Page3 *returnPage=new Page3();
    returnPage->show();
    this->close();
}

void Wangluoshezhi::showEthernet()
{
    Yitaiwangshezhi *showEthernet=new Yitaiwangshezhi();
    showEthernet->show();
    this->close();
}
