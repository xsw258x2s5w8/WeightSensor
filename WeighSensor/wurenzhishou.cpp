#include "wurenzhishou.h"
#include "ui_wurenzhishou.h"
#include "index.h"
#include "page2.h"

Wurenzhishou::Wurenzhishou(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Wurenzhishou)
{
    ui->setupUi(this);
    connect(ui->returnIndex,SIGNAL(clicked()),this,SLOT(returnIndex()));
    connect(ui->returnPage,SIGNAL(clicked()),this,SLOT(returnPage()));
}

Wurenzhishou::~Wurenzhishou()
{
    delete ui;
}

void Wurenzhishou::returnIndex()
{
    Index *index=new Index();
    index->show();
    this->close();
}

void Wurenzhishou::returnPage()
{
    page2 *returnPage=new page2();
    returnPage->show();
    this->close();
}
