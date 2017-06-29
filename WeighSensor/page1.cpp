#include <QtGui/QApplication>
#include "page1.h"
#include "ui_page1.h"
#include "index.h"
#include "page2.h"
#include "wangjimima.h"

page1::page1(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::page1)
{
    ui->setupUi(this);
    //combox 属性条目
    QStringList strings;
    strings<<tr("user")<<tr("weigher")<<tr("producer");
    ui->permissionComboBox->addItems(strings);

    connect(ui->returnIndex_3,SIGNAL(clicked()),this,SLOT(returnIndex()));
    connect(ui->returnPage,SIGNAL(clicked()),this,SLOT(returnPage()));
    connect(ui->forget,SIGNAL(clicked()),this,SLOT(showForget()));
    connect(ui->set,SIGNAL(clicked()),this,SLOT(showsetFinish()));
}

page1::~page1()
{
    delete ui;
}

void page1::returnIndex()
{
    Index *index=new Index();
    index->show();
    this->close();
}

void page1::returnPage()
{
    page2 *returnPage=new page2();
    returnPage->show();
    this->close();
}

void page1::showForget()
{
    Wangjimima *showForget=new Wangjimima();
    showForget->show();
    this->close();
}

void page1::showsetFinish()
{
    page2 *setFinish=new page2();
    setFinish->show();
    this->close();
}
