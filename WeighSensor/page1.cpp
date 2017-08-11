#include <QtGui/QApplication>
#include "page1.h"
#include "ui_page1.h"
#include "index.h"
#include "page2.h"
#include "wangjimima.h"
#include "impl/userimpl.h"
#include "impl/useraliveimpl.h"
#include "impl/useralive.h"
#include <QMessageBox>
page1::page1(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::page1)
{
    ui->setupUi(this);
    this->setWindowState(Qt::WindowFullScreen);

    //combox 属性条目
    QStringList strings;
    strings<<tr("生产方")<<tr("调秤方")<<tr("用户");
    ui->permissionComboBox->addItems(strings);

    connect(ui->returnIndex_3,SIGNAL(clicked()),this,SLOT(returnIndex()));
    connect(ui->returnPage,SIGNAL(clicked()),this,SLOT(returnPage()));
    connect(ui->forget,SIGNAL(clicked()),this,SLOT(showForget()));
    connect(ui->set,SIGNAL(clicked()),this,SLOT(showsetFinish()));

    UserAliveImpl useraliveimpl;
    UserAlive useralive = useraliveimpl.getAuthorityInfo();//返回在线用户信息
    QString userName = useralive.getUserName();
    ui->userName->setText(userName);
}

page1::~page1()
{
    delete ui;
}

void page1::returnIndex()
{
//    Index *index=new Index();
//    index->show();
    this->close();
}

void page1::returnPage()
{
    page2 *returnPage=new page2();
    returnPage->show();
    this->close();
}

void page1::showForget()
{
    Wangjimima *showForget=new Wangjimima();
    showForget->show();
    this->close();
}

void page1::showsetFinish()
{


    int userId;
    int authority;
    UserImpl userimpl;
    UserAliveImpl useraliveimpl;
    UserAlive useralive;
    //读取用户id和password
    QString userName = ui->permissionComboBox->currentText();
    QString password = ui->password->text();
    userId = userimpl.getUserId(userName);
    authority = userimpl.getAuthority(userId);


    //判断用户密码输入是否正确
    int result = userimpl.login(userId,password);
    if(result!=1)
    {
        QMessageBox::about(NULL, "失败", "密码有错误！");
    }
    else
    {
        //用户登录完毕，记录用户


        useralive.setAuthority(authority);
        useralive.setUserId(userId);
        useralive.setUserName(userName);

        useraliveimpl.deleteInfo();//先清空表内信息
        useraliveimpl.addInfo(useralive);//把在线信息加入到表中

        QMessageBox::about(NULL, "成功", "登录成功!");

        page2 *setFinish = new page2();
        setFinish->show();
        this->close();
    }



}
