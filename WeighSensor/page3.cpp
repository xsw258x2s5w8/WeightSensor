#include "page3.h"
#include "ui_page3.h"
#include "index.h"
#include "page2.h"
#include "wangluoshezhi.h"
#include "tongxunshezhi.h"
#include "ruanjiangengxin.h"
#include "chushihua.h"
#include "jiexianshiyitu.h"
#include "bangzhushouce.h"
#include "window.h"

Page3::Page3(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Page3)
{
    ui->setupUi(this);
    this->setWindowState(Qt::WindowFullScreen);

    connect(ui->returnIndex,SIGNAL(clicked()),this,SLOT(returnIndex()));
    connect(ui->returnPage,SIGNAL(clicked()),this,SLOT(returnPage()));
    connect(ui->preview,SIGNAL(clicked()),this,SLOT(showPreview()));
    connect(ui->setNetwork,SIGNAL(clicked()),this,SLOT(showSetNetwork()));
    connect(ui->communication,SIGNAL(clicked()),this,SLOT(showCommunication()));
    connect(ui->update,SIGNAL(clicked()),this,SLOT(showUpdateSoftware()));
    connect(ui->initialize,SIGNAL(clicked()),this,SLOT(showInitlization()));
    connect(ui->exhibition,SIGNAL(clicked()),this,SLOT(showExhibition()));
    connect(ui->help,SIGNAL(clicked()),this,SLOT(showHelp()));

}

Page3::~Page3()
{
    delete ui;
}

void Page3::returnIndex()
{
//    Index *menu=new Index();
//    menu->show();
    this->close();
}

void Page3::returnPage()
{
    page2 *returnPage=new page2();
    returnPage->show();
    this->close();
}

void Page3::showPreview()
{
    page2 *returnPage=new page2();
    returnPage->show();
    this->close();
}

void Page3::showSetNetwork()
{
    Wangluoshezhi *showSetNetwork=new Wangluoshezhi();
    showSetNetwork->show();
    this->close();
}

void Page3::showCommunication()
{
    Tongxunshezhi *showCommunication=new Tongxunshezhi();
    showCommunication->show();
    this->close();
}

void Page3::showUpdateSoftware()
{
    Ruanjiangengxin *showUpdateSoftware=new Ruanjiangengxin();
    showUpdateSoftware->show();
    this->close();
}

void Page3::showInitlization()
{
    Chushihua *showInitlization=new Chushihua();
    showInitlization->show();
    this->close();
}

void Page3::showExhibition()
{
   Jiexianshiyitu *showExhibition=new Jiexianshiyitu();
   showExhibition->show();
   this->close();
}

void Page3::showHelp()
{
   Bangzhushouce *showHelp=new Bangzhushouce();
   showHelp->show();

//   Window *showWindow=new Window();
//   showWindow->show();
   this->close();
}

