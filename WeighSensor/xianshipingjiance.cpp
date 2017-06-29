#include "xianshipingjiance.h"
#include "ui_xianshipingjiance.h"
#include "index.h"
#include "jiance.h"

Xianshipingjiance::Xianshipingjiance(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Xianshipingjiance)
{
    ui->setupUi(this);
    connect(ui->returnIndex,SIGNAL(clicked()),this,SLOT(returnIndex()));
    connect(ui->returnPage,SIGNAL(clicked()),this,SLOT(returnPage()));
}

Xianshipingjiance::~Xianshipingjiance()
{
    delete ui;
}

void Xianshipingjiance::returnIndex()
{
    Index *index=new Index();
    index->show();
    this->close();
}

void Xianshipingjiance::returnPage()
{
    Jiance *returnPage=new Jiance();
    returnPage->show();
    this->close();
}
