#include "beiguangliangdu.h"
#include "ui_beiguangliangdu.h"
#include "index.h"
#include "jiance.h"

Beiguangliangdu::Beiguangliangdu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Beiguangliangdu)
{
    ui->setupUi(this);
    this->setWindowState(Qt::WindowFullScreen);

    connect(ui->returnIndex,SIGNAL(clicked()),this,SLOT(returnIndex()));
    connect(ui->returnPage,SIGNAL(clicked()),this,SLOT(returnPage()));
}

Beiguangliangdu::~Beiguangliangdu()
{
    delete ui;
}

void Beiguangliangdu::returnIndex()
{
//    Index *menu=new Index();
//    menu->show();
    this->close();
}

void Beiguangliangdu::returnPage()
{
    Jiance *returnPage=new Jiance();
    returnPage->show();
    this->close();
}
