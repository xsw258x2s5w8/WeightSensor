#include "shouhou_product.h"
#include "ui_shouhou_product.h"
#include "jiance.h"
#include "index.h"

Shouhou_product::Shouhou_product(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Shouhou_product)
{
    ui->setupUi(this);
    //this->setWindowState(Qt::WindowFullScreen);

    //创建数据接口
    afterServiceImpl=new AfterServiceImpl();

    //显示数据
    showServiceData();

    connect(ui->returnIndex,SIGNAL(clicked()),this,SLOT(returnIndex()));
    connect(ui->returnPage,SIGNAL(clicked()),this,SLOT(returnPage()));
    connect(ui->save,SIGNAL(clicked()),this,SLOT(slotSave()));

}

Shouhou_product::~Shouhou_product()
{
    delete ui;
}


void Shouhou_product::returnIndex()
{
     this->close();
}


void Shouhou_product::returnPage()
{
    Jiance *returnPage=new Jiance();
    returnPage->show();
    this->close();
}


void Shouhou_product::showServiceData()
{
    AfterService afterService=afterServiceImpl->selectAfterService();

    ui->companyName->setText(afterService.getCompanyName());
    ui->conPerson->setText(afterService.getConPerson());
    ui->tel->setText(afterService.getTel());
}


void Shouhou_product::slotSave()
{
    AfterService afterService;
    afterService.setCompanyName(ui->companyName->text());
    afterService.setConPerson(ui->conPerson->text());
    afterService.setTel(ui->tel->text());

    //先删除再插入
    afterServiceImpl->deleteAfterService();
    afterServiceImpl->insertAfterService(afterService);
}
