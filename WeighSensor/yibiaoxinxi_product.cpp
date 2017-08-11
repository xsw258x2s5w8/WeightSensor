#include "yibiaoxinxi_product.h"
#include "ui_yibiaoxinxi_product.h"
#include "index.h"
#include "jiance.h"

Yibiaoxinxi_product::Yibiaoxinxi_product(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Yibiaoxinxi_product)
{
    ui->setupUi(this);
    //this->setWindowState(Qt::WindowFullScreen);

    //创建数据接口对象
    instinfoimpl=new InstInfoImpl();

    //显示数据
    showInstData();

    connect(ui->returnIndex,SIGNAL(clicked()),this,SLOT(returnIndex()));
    connect(ui->returnPage,SIGNAL(clicked()),this,SLOT(returnPage()));
    connect(ui->save,SIGNAL(clicked()),this,SLOT(slotSave()));
}

Yibiaoxinxi_product::~Yibiaoxinxi_product()
{
    delete ui;
}


void Yibiaoxinxi_product::returnIndex()
{
    this->close();
}


void Yibiaoxinxi_product::returnPage()
{
    Jiance *returnPage=new Jiance();
    returnPage->show();
    this->close();
}


void Yibiaoxinxi_product::showInstData()
{
    InstInfo instinfo=instinfoimpl->selectInstInfo();

    ui->version->setText(instinfo.getVersion());
    ui->microType->setText(instinfo.getMicrType());
    ui->insId->setText(instinfo.getInsId());
    ui->custInfo->setText(instinfo.getCustInfo());
}


void Yibiaoxinxi_product::slotSave()
{
    InstInfo instinfo;
    instinfo.setVersion(ui->version->text());
    instinfo.setMicrType(ui->microType->text());
    instinfo.setInsId(ui->insId->text());
    instinfo.setCustInfo(ui->custInfo->toPlainText());

    //先删除后增加
    instinfoimpl->deleteInstInfo();
    instinfoimpl->insertInstInfo(instinfo);
}
