#include "jiance2.h"
#include "ui_jiance2.h"
#include "index.h"
#include "jiance.h"

Jiance2::Jiance2(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Jiance2)
{
    ui->setupUi(this);
    connect(ui->returnIndex,SIGNAL(clicked()),this,SLOT(returnIndex()));
    connect(ui->returnPage,SIGNAL(clicked()),this,SLOT(returnPage()));
    connect(ui->preview,SIGNAL(clicked()),this,SLOT(showPreview()));
}

Jiance2::~Jiance2()
{
    delete ui;
}

void Jiance2::returnIndex()
{
    Index *menu=new Index();
    menu->show();
    this->close();
}

void Jiance2::returnPage()
{
    Jiance *returnPage=new Jiance();
    returnPage->show();
    this->close();
}

void Jiance2::showPreview()
{
    Jiance *showPreview=new Jiance();
    showPreview->show();
    this->close();
}
