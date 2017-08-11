#include "baobiaodayin.h"
#include "ui_baobiaodayin.h"
#include "index.h"
#include "lishijilu.h"

Baobiaodayin::Baobiaodayin(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Baobiaodayin)
{
    ui->setupUi(this);
    this->setWindowState(Qt::WindowFullScreen);

    //combox 属性条目
    QStringList strings;
    strings<<tr("use")<<tr("nouse");
    ui->datecombo->addItems(strings);
    ui->chehaocombo->addItems(strings);
    ui->huohaocombo->addItems(strings);

    connect(ui->returnIndex,SIGNAL(clicked()),this,SLOT(returnIndex()));
    connect(ui->returnPage,SIGNAL(clicked()),this,SLOT(returnPage()));
}

Baobiaodayin::~Baobiaodayin()
{
    delete ui;
}

void Baobiaodayin::returnIndex()
{
//    Index *menu=new Index();
//    menu->show();
    this->close();
}

void Baobiaodayin::returnPage()
{
    Lishijilu *returnPage=new Lishijilu();
    returnPage->show();
    this->close();
}
