#include "buwanzheng.h"
#include "ui_buwanzheng.h"
#include "index.h"
#include "lishijilu.h"
#include "buwanzheng_chaxun.h"

Buwanzheng::Buwanzheng(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Buwanzheng)
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

Buwanzheng::~Buwanzheng()
{
    delete ui;
}

void Buwanzheng::returnIndex()
{
//    Index *menu=new Index();
//    menu->show();
    this->close();
}

void Buwanzheng::returnPage()
{
    Lishijilu *returnPage=new Lishijilu();
    returnPage->show();
    this->close();
}

void Buwanzheng::showQuery()
{
    Buwanzheng_chaxun *showQuery=new Buwanzheng_chaxun();
    showQuery->show();
    this->close();
}
