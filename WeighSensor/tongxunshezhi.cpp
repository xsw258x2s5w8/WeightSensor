#include "tongxunshezhi.h"
#include "ui_tongxunshezhi.h"
#include "index.h"
#include "page3.h"

Tongxunshezhi::Tongxunshezhi(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Tongxunshezhi)
{
    ui->setupUi(this);
    this->setWindowState(Qt::WindowFullScreen);

    //combox 属性条目
    QStringList strings;
    strings<<tr("com1")<<tr("com2")<<tr("com3")<<tr("com4");
    ui->comBox->addItems(strings);


    connect(ui->returnIndex,SIGNAL(clicked()),this,SLOT(returnIndex()));
    connect(ui->returnPage,SIGNAL(clicked()),this,SLOT(returnPage()));
}

Tongxunshezhi::~Tongxunshezhi()
{
    delete ui;
}

void Tongxunshezhi::returnIndex()
{
//    Index *menu=new Index();
//    menu->show();
    this->close();
}

void Tongxunshezhi::returnPage()
{
    Page3 *returnPage=new Page3();
    returnPage->show();
    this->close();
}
