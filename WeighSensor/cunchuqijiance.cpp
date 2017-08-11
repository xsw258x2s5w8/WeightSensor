#include "cunchuqijiance.h"
#include "ui_cunchuqijiance.h"
#include "index.h"
#include "jiance.h"

Cunchuqijiance::Cunchuqijiance(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Cunchuqijiance)
{
    ui->setupUi(this);
    this->setWindowState(Qt::WindowFullScreen);

    connect(ui->returnIndex,SIGNAL(clicked()),this,SLOT(returnIndex()));
    connect(ui->returnPage,SIGNAL(clicked()),this,SLOT(returnPage()));
}

Cunchuqijiance::~Cunchuqijiance()
{
    delete ui;
}

void Cunchuqijiance::returnIndex()
{
//    Index *menu=new Index();
//    menu->show();
    this->close();
}

void Cunchuqijiance::returnPage()
{
    Jiance *returnPage=new Jiance();
    returnPage->show();
    this->close();
}
