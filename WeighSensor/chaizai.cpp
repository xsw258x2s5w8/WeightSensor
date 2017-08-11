#include "chaizai.h"
#include "ui_chaizai.h"
#include "index.h"
#include "tiaochen_2.h"

Chaizai::Chaizai(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Chaizai)
{
    ui->setupUi(this);
    this->setWindowState(Qt::WindowFullScreen);

    connect(ui->returnIndex,SIGNAL(clicked()),this,SLOT(returnIndex()));
    connect(ui->returnPage,SIGNAL(clicked()),this,SLOT(returnPage()));
}

Chaizai::~Chaizai()
{
    delete ui;
}

void Chaizai::returnIndex()
{
//    Index *menu=new Index();
//    menu->show();
    this->close();
}

void Chaizai::returnPage()
{
    Tiaochen_2 *returnPage=new Tiaochen_2();
    returnPage->show();
    this->close();
}
