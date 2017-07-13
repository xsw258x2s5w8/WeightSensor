#include "testpreviewdialogsetup.h"
#include "ui_testpreviewdialogsetup.h"
#include "wanzheng_chaxun.h"

testPreviewDialogSetup::testPreviewDialogSetup(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::testPreviewDialogSetup)
{
    ui->setupUi(this);
    connect(ui->ok,SIGNAL(clicked()),this,SLOT(sendOK()));

}

testPreviewDialogSetup::~testPreviewDialogSetup()
{
    delete ui;
}

void testPreviewDialogSetup::sendOK()
{
    //获得数据
    QStringList strList;
    strList.append(ui->xiangshang->text());
    strList.append(ui->xiangxia->text());
    strList.append(ui->xiangzuo->text());
    strList.append(ui->xiangyou->text());
    strList.append(ui->jianju->text());
    strList.append(ui->width->text());
    strList.append(ui->height->text());
//    strList.append(ui->->text());

    //发射数据
    emit SignalsendString(strList);

    this->close();

    //发送接受信号
    //this->accept();
}
