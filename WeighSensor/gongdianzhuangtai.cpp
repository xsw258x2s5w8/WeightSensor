#include "gongdianzhuangtai.h"
#include "ui_gongdianzhuangtai.h"
#include "index.h"
#include "jiance.h"

Gongdianzhuangtai::Gongdianzhuangtai(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Gongdianzhuangtai)
{
    ui->setupUi(this);
    this->setWindowState(Qt::WindowFullScreen);

    connect(ui->returnIndex,SIGNAL(clicked()),this,SLOT(returnIndex()));
    connect(ui->returnPage,SIGNAL(clicked()),this,SLOT(returnPage()));
}

Gongdianzhuangtai::~Gongdianzhuangtai()
{
    delete ui;
}

void Gongdianzhuangtai::returnIndex()
{
//    Index *menu=new Index();
//    menu->show();
    this->close();
}

void Gongdianzhuangtai::returnPage()
{
    Jiance *returnPage=new Jiance();
    returnPage->show();
    this->close();
}
