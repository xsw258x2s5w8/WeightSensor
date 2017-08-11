#include "liuchengshezhi.h"
#include "ui_liuchengshezhi.h"
#include "index.h"
#include "wurenzhishou.h"

Liuchengshezhi::Liuchengshezhi(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Liuchengshezhi)
{
    ui->setupUi(this);
    this->setWindowState(Qt::WindowFullScreen);

    connect(ui->returnIndex,SIGNAL(clicked()),this,SLOT(returnIndex()));
    connect(ui->returnPage,SIGNAL(clicked()),this,SLOT(returnPage()));
}

Liuchengshezhi::~Liuchengshezhi()
{
    delete ui;
}

void Liuchengshezhi::returnIndex()
{
//    Index *menu=new Index();
//    menu->show();
    this->close();
}

void Liuchengshezhi::returnPage()
{
    Wurenzhishou *returnPage=new Wurenzhishou();
    returnPage->show();
    this->close();
}
