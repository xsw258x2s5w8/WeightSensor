#include "dayincanshu.h"
#include "ui_dayincanshu.h"
#include "dayin.h"
#include "index.h"

Dayincanshu::Dayincanshu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Dayincanshu)
{
    ui->setupUi(this);
    this->setWindowState(Qt::WindowFullScreen);
    initialize();

    connect(ui->returnIndex,SIGNAL(clicked()),this,SLOT(returnIndex()));
    connect(ui->returnPage,SIGNAL(clicked()),this,SLOT(returnPage()));


}

void Dayincanshu::initialize()
{
    //combox 属性条目
    QStringList strings;
    strings<<tr("buqidong")<<tr("jingbenciqidong")<<tr("qidong");
    ui->comboBox_zidongdaying->addItems(strings);

    QStringList strings1;
    strings1<<tr("yilian")<<tr("erlian")<<tr("sanlian")<<tr("silian");
    ui->comboBox_number->addItems(strings1);

    QStringList strings2;
    strings2<<tr("usbdayin")<<tr("24zhendayin");
    ui->comboBox_dayinleixing->addItems(strings2);

    QStringList strings3;
    strings3<<tr("weida shuliandan");
    ui->comboBox_bangdangeshi->addItems(strings3);

    QStringList strings4;
    strings4<<tr("shiyong")<<tr("bushiyong");
    ui->comboBox_chehao->addItems(strings4);

    QStringList strings5;
    strings5<<tr("shiyong")<<tr("bushiyong");
    ui->comboBox_huohao->addItems(strings5);

    QStringList strings6;
    strings6<<tr("wuweida")<<tr("reminweida")<<tr("zhenshiweida");
    ui->comboBox_weileixing->addItems(strings6);

    QStringList strings7;
    strings7<<tr("shiyong")<<tr("bushiyong");
    ui->comboBox_guobangdan->addItems(strings7);
}

Dayincanshu::~Dayincanshu()
{
    delete ui;
}

void Dayincanshu::returnIndex()
{
//    Index *menu=new Index();
//    menu->show();
    this->close();
}

void Dayincanshu::returnPage()
{
    Dayin *returnPage=new Dayin();
    returnPage->show();
    this->close();
}
