#include "lishijilu.h"
#include "ui_lishijilu.h"
#include "index.h"
#include "wanzheng.h"
#include "buwanzheng.h"
#include "baobiaodayin.h"
#include "qingchujillu.h"

Lishijilu::Lishijilu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Lishijilu)
{
    ui->setupUi(this);
    this->setWindowState(Qt::WindowFullScreen);

    connect(ui->returnIndex,SIGNAL(clicked()),this,SLOT(returnIndex()));
    connect(ui->returnPage,SIGNAL(clicked()),this,SLOT(returnPage()));
    connect(ui->allRecord,SIGNAL(clicked()),this,SLOT(showAll()));
    connect(ui->incompleteQuery,SIGNAL(clicked()),this,SLOT(showIncomplete()));
    connect(ui->printTable,SIGNAL(clicked()),this,SLOT(showPrintTable()));
    connect(ui->clear,SIGNAL(clicked()),this,SLOT(showClear()));
}

Lishijilu::~Lishijilu()
{
    delete ui;
}

void Lishijilu::returnIndex()
{
//    Index *menu=new Index();
//    menu->show();
    this->close();
}

void Lishijilu::returnPage()
{
//    Index *returnPage=new Index();
//    returnPage->show();
    this->close();
}

void Lishijilu::showAll()
{
    Wanzheng *showAll=new Wanzheng();
    showAll->show();
    this->close();
}

void Lishijilu::showIncomplete()
{
    Buwanzheng *showIncomplete=new Buwanzheng();
    showIncomplete->show();
    this->close();
}

void Lishijilu::showPrintTable()
{
    Baobiaodayin *showPrintTable=new Baobiaodayin();
    showPrintTable->show();
    this->close();
}

void Lishijilu::showClear()
{
    Qingchujillu *showClear=new Qingchujillu();
    showClear->show();
    this->close();
}
