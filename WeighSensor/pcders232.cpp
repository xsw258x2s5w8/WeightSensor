#include "pcders232.h"
#include "ui_pcders232.h"
#include "index.h"
#include "jiance.h"

Pcders232::Pcders232(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Pcders232)
{
    ui->setupUi(this);
    connect(ui->returnIndex,SIGNAL(clicked()),this,SLOT(returnIndex()));
    connect(ui->returnPage,SIGNAL(clicked()),this,SLOT(returnPage()));
}

Pcders232::~Pcders232()
{
    delete ui;
}

void Pcders232::returnIndex()
{
    Index *menu=new Index();
    menu->show();
    this->close();
}

void Pcders232::returnPage()
{
    Jiance *returnPage=new Jiance();
    returnPage->show();
    this->close();
}
