#include "wangjimima.h"
#include "ui_wangjimima.h"
#include "index.h"
#include "page1.h"

Wangjimima::Wangjimima(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Wangjimima)
{
    ui->setupUi(this);
    this->setWindowState(Qt::WindowFullScreen);

    //combox 属性条目
    QStringList strings;
    strings<<tr("user")<<tr("weigher")<<tr("producer");
    ui->permissionComboBox->addItems(strings);

    connect(ui->returnIndex,SIGNAL(clicked()),this,SLOT(returnIndex()));
    connect(ui->returnPage,SIGNAL(clicked()),this,SLOT(returnPage()));
}

Wangjimima::~Wangjimima()
{
    delete ui;
}

void Wangjimima::returnIndex()
{
//    Index *menu=new Index();
//    menu->show();
    this->close();
}

void Wangjimima::returnPage()
{
    page1 *returnPage=new page1();
    returnPage->show();
    this->close();
}
