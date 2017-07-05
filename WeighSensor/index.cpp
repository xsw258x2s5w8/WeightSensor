#include "index.h"
#include "ui_index.h"
#include "page2.h"
#include "erweimaguanli.h"
#include "lishijilu.h"
#include "yiciguobang.h"
#include "erciguobang.h"
#include "shipin.h"

Index::Index(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Index)
{
    ui->setupUi(this);
    connect(ui->menu,SIGNAL(clicked()),this,SLOT(showMenuWidget()));
    connect(ui->QRcode,SIGNAL(clicked()),this,SLOT(showQRcode()));
    connect(ui->print,SIGNAL(clicked()),this,SLOT(showPrint()));
    connect(ui->yiciguobang,SIGNAL(clicked()),this,SLOT(showYiguobang()));
    connect(ui->erciguobang,SIGNAL(clicked()),this,SLOT(showErciguobang()));
    connect(ui->shipin,SIGNAL(clicked()),this,SLOT(showShipin()));
}

Index::~Index()
{
    delete ui;
}

void Index::showMenuWidget()
{
    page2 *menu=new page2();
    menu->show(); //open menu Widget
    this->close();  //close parent Widget
}

void Index::showQRcode()
{
    Erweimaguanli *showQRcode=new Erweimaguanli();
    showQRcode->show();
    this->close();
}

void Index::showPrint()
{
    Lishijilu *showPrint=new Lishijilu();
    showPrint->show();
    this->close();
}

void Index::showYiguobang()
{
    Yiciguobang *showYiguobang=new Yiciguobang();
    showYiguobang->show();
    this->close();
}

void Index::showErciguobang()
{
    Erciguobang *showErciguobang=new Erciguobang();
    showErciguobang->show();
    this->close();
}

void Index::showShipin()
{
    Shipin *showShipin = new Shipin();
    showShipin->show();
    this->close();
}
