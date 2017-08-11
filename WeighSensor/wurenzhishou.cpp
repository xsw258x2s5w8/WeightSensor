#include "wurenzhishou.h"
#include "ui_wurenzhishou.h"
#include "index.h"
#include "page2.h"
#include "shipinshezhi.h"
#include "liuchengshezhi.h"

Wurenzhishou::Wurenzhishou(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Wurenzhishou)
{
    ui->setupUi(this);
    this->setWindowState(Qt::WindowFullScreen);

    connect(ui->returnIndex,SIGNAL(clicked()),this,SLOT(returnIndex()));
    connect(ui->returnPage,SIGNAL(clicked()),this,SLOT(returnPage()));
    connect(ui->videoBtn,SIGNAL(clicked()),this,SLOT(showSetVideo()));
    connect(ui->videoprocess,SIGNAL(clicked()),this,SLOT(showVideoProgress()));
}

Wurenzhishou::~Wurenzhishou()
{
    delete ui;
}

void Wurenzhishou::returnIndex()
{
//    Index *index=new Index();
//    index->show();
    this->close();
}

void Wurenzhishou::returnPage()
{
    page2 *returnPage=new page2();
    returnPage->show();
    this->close();
}

void Wurenzhishou::showSetVideo()
{
    Shipinshezhi *showSetVideo=new Shipinshezhi();
    showSetVideo->show();
    this->close();
}

void Wurenzhishou::showVideoProgress()
{
    Liuchengshezhi *showVideoProgress=new Liuchengshezhi();
    showVideoProgress->show();
    this->close();
}
