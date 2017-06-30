#include "page3.h"
#include "ui_page3.h"
#include "index.h"
#include "page2.h"
#include "wangluoshezhi.h"

Page3::Page3(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Page3)
{
    ui->setupUi(this);
    connect(ui->returnIndex,SIGNAL(clicked()),this,SLOT(returnIndex()));
    connect(ui->returnPage,SIGNAL(clicked()),this,SLOT(returnPage()));
    connect(ui->preview,SIGNAL(clicked()),this,SLOT(showPreview()));
    connect(ui->setNetwork,SIGNAL(clicked()),this,SLOT(showSetNetwork()));
}

Page3::~Page3()
{
    delete ui;
}

void Page3::returnIndex()
{
    Index *menu=new Index();
    menu->show();
    this->close();
}

void Page3::returnPage()
{
    page2 *returnPage=new page2();
    returnPage->show();
    this->close();
}

void Page3::showPreview()
{
    page2 *returnPage=new page2();
    returnPage->show();
    this->close();
}

void Page3::showSetNetwork()
{
    Wangluoshezhi *showSetNetwork=new Wangluoshezhi();
    showSetNetwork->show();
    this->close();
}
