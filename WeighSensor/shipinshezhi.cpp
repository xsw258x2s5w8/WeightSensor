#include "shipinshezhi.h"
#include "ui_shipinshezhi.h"
#include "index.h"
#include "page2.h"

Shipinshezhi::Shipinshezhi(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Shipinshezhi)
{
    ui->setupUi(this);

    //combox 属性条目
    QStringList strings;
    strings<<tr("Common")<<tr("Fluent")<<tr("HD");
    ui->comboBox->addItems(strings);

    connect(ui->returnIndex_2,SIGNAL(clicked()),this,SLOT(returnIndex()));
    connect(ui->returnPage_2,SIGNAL(clicked()),this,SLOT(returnPage()));
}

Shipinshezhi::~Shipinshezhi()
{
    delete ui;
}

void Shipinshezhi::returnIndex()
{
    Index *menu=new Index();
    menu->show();
    this->close();
}

void Shipinshezhi::returnPage()
{
    page2 *returnPage=new page2();
    returnPage->show();
    this->close();
}
