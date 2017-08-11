#include "shouyecanshu.h"
#include "ui_shouyecanshu.h"
#include "index.h"
#include "page2.h"
#include "QMessageBox"

Shouyecanshu::Shouyecanshu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Shouyecanshu)
{
    ui->setupUi(this);
    this->setWindowState(Qt::WindowFullScreen);

    //maininterfaceimpl表格数据接口
    maininterfaceimpl=new MainInterfaceImpl();
    maininterfacetempimpl=new MainInterfaceTempImpl();

    //-------------------自定义table显示----------------------
    mytableview=new MyTableView();
    mytableview->setSelectionBehavior(QAbstractItemView::SelectRows);
    mytableview->setSelectionMode ( QAbstractItemView::SingleSelection);//选中单行
    //mytableview.setEditTriggers(QAbstractItemView::NoEditTriggers);//不可编辑

    //自定义委托
    MyDelegate *mydelegate = new MyDelegate;
    mytableview->setItemDelegate(mydelegate);

    //将自定义table添加到控件中
    ui->scrollArea->setWidget(mytableview);

    //显示table数据
    showTableData();


    connect(ui->returnIndex,SIGNAL(clicked()),this,SLOT(returnIndex()));
    connect(ui->returnPage,SIGNAL(clicked()),this,SLOT(returnPage()));
    connect(ui->saveBtn,SIGNAL(clicked()),this,SLOT(slotSave()));
}

Shouyecanshu::~Shouyecanshu()
{
    delete ui;
}

void Shouyecanshu::returnIndex()
{
//    Index *menu=new Index();
//    menu->show();
    this->close();
}

void Shouyecanshu::returnPage()
{
    page2 *returnPage=new page2();
    returnPage->show();
    this->close();
}


void Shouyecanshu::showTableData()
{
    //获得表格数据，并插入到tableview中
    QList<MainInterface> list = maininterfaceimpl->selectInterface();

    for(int i=0;i<list.length();i++)
    {
       MainInterface main;
       main = list.at(i);
       mytableview->setModelData(main);
    }
}


void Shouyecanshu::slotSave()
{
    //得到tableview里面的数据
     QList<MainInterface> list = mytableview->getModelData();

    //更新Maininterface数据库
     maininterfaceimpl->deleteInterface();//删除

     for(int i=0;i<list.length();i++){
         MainInterface main;
         main=list.at(i);
         maininterfaceimpl->insertInterface(main);//插入
     }


   //更新MaininterfaceTemp表格
   //得到tableview前面几条已勾选的记录
   QList<MainInterfaceTemp> tempList = maininterfaceimpl->selectInterfaceTemp();

   //先删除再插入temp表
   maininterfacetempimpl->deleteMainInterfaceTemp();
   for(int i=0;i<tempList.length();i++){
       MainInterfaceTemp temp;
       temp=tempList.at(i);
       maininterfacetempimpl->insertMainInterfaceTemp(temp);
   }

   //提示框
   QMessageBox::information(NULL, "提醒", "主界面编辑成功，请手动重启仪表完成界面修改", QMessageBox::Yes);

   this->close();
}
