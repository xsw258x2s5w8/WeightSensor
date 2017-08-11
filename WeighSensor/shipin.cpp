#include "shipin.h"
#include "ui_shipin.h"
#include "index.h"


Shipin::Shipin(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Shipin)
{
    ui->setupUi(this);
    //切换按钮隐藏
    ui->switchbtn->close();

    connect(ui->returnIndex,SIGNAL(clicked()),this,SLOT(returnIndex()));
    connect(ui->returnPage,SIGNAL(clicked()),this,SLOT(returnPage()));
    connect(ui->oneFrame,SIGNAL(clicked()),this,SLOT(showOneFrame()));
    connect(ui->fourFrame,SIGNAL(clicked()),this,SLOT(showFourFrame()));
    connect(ui->USBCamera,SIGNAL(clicked(QString)),this,SLOT(showtwoUSBFrame(QString)));
    connect(ui->moniCamera,SIGNAL(clicked(QString)),this,SLOT(showtwoUSBFrame(QString)));
}

Shipin::~Shipin()
{
    delete ui;
}

void Shipin::returnIndex()
{
//    Index *menu=new Index();
//    menu->show();
    this->close();
}

void Shipin::returnPage()
{
    Index *returnPage=new Index();
    returnPage->show();
    this->close();
}

void Shipin::showtwoUSBFrame(QString name)
{
    Shipin_twousb *twousb = new Shipin_twousb(name);
    twousb->show();
    this->close();
}

void Shipin::showOneFrame()
{   //btn显示
    ui->switchbtn->show();
    //画面隐藏
    ui->widget_two->close();
    ui->widget_three->close();
    ui->widget_four->close();
}

void Shipin::showFourFrame()
{
    //btn隐藏
    ui->switchbtn->close();
    //画面全显示
    ui->widget_two->show();
    ui->widget_three->show();
    ui->widget_four->show();
    ui->widget_one->show();
}

