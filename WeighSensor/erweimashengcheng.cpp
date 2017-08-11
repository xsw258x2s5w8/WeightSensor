#include "erweimashengcheng.h"
#include "ui_erweimashengcheng.h"
#include "index.h"
#include "erweimaguanli.h"

Erweimashengcheng::Erweimashengcheng(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Erweimashengcheng)
{
    ui->setupUi(this);
    this->setWindowState(Qt::WindowFullScreen);

    connect(ui->returnIndex,SIGNAL(clicked()),this,SLOT(returnIndex()));
    connect(ui->returnPage,SIGNAL(clicked()),this,SLOT(returnPage()));
}

Erweimashengcheng::~Erweimashengcheng()
{
    delete ui;
}

void Erweimashengcheng::returnIndex()
{
//    Index *menu=new Index();
//    menu->show();
    this->close();
}

void Erweimashengcheng::returnPage()
{
    Erweimaguanli *returnPage=new Erweimaguanli();
    returnPage->show();
    this->close();
}
