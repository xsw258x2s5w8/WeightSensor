#include "wanzheng.h"
#include "ui_wanzheng.h"
#include "index.h"
#include "lishijilu.h"
#include "wanzheng_chaxun.h"

Wanzheng::Wanzheng(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Wanzheng)
{
    ui->setupUi(this);
    this->setWindowState(Qt::WindowFullScreen);

    //combox 属性条目
    QStringList strings;
    strings<<tr("use")<<tr("nouse");
    ui->datecombo->addItems(strings);
    ui->chehaocombo->addItems(strings);
    ui->huohaocombo->addItems(strings);

    connect(ui->returnIndex,SIGNAL(clicked()),this,SLOT(returnIndex()));
    connect(ui->returnPage,SIGNAL(clicked()),this,SLOT(returnPage()));
    connect(ui->query,SIGNAL(clicked()),this,SLOT(showQuery()));
}

Wanzheng::~Wanzheng()
{
    delete ui;
}

void Wanzheng::returnIndex()
{
//    Index *menu=new Index();
//    menu->show();
    this->close();
}

void Wanzheng::returnPage()
{
    Lishijilu *returnPage=new Lishijilu();
    returnPage->show();
    this->close();
}

void Wanzheng::showQuery()
{
    Wanzheng_chaxun *showQuery=new Wanzheng_chaxun();
    showQuery->show();
    this->close();
}
