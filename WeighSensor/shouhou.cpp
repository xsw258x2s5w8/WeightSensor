#include "shouhou.h"
#include "ui_shouhou.h"
#include "jiance.h"
#include "index.h"
Shouhou::Shouhou(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Shouhou)
{
    ui->setupUi(this);
    //this->setWindowState(Qt::WindowFullScreen);

    //创建数据接口
    afterServiceImpl=new AfterServiceImpl();

    //显示数据
    showServiceData();

    connect(ui->returnIndex,SIGNAL(clicked()),this,SLOT(returnIndex()));
    connect(ui->returnPage,SIGNAL(clicked()),this,SLOT(returnPage()));
}

Shouhou::~Shouhou()
{
    delete ui;
}

void Shouhou::returnIndex()
{
//    Index *menu=new Index();
//    menu->show();
    this->close();
}

void Shouhou::returnPage()
{
    Jiance *returnPage=new Jiance();
    returnPage->show();
    this->close();
}


void Shouhou::showServiceData()
{
    AfterService afterService=afterServiceImpl->selectAfterService();

    ui->companyName->setText(afterService.getCompanyName());
    ui->conPerson->setText(afterService.getConPerson());
    ui->tel->setText(afterService.getTel());
}
