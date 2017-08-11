#include "mytableview.h"
#include <QDebug>
#include <QList>
MyTableView::MyTableView(QWidget * parent)
    :QTableView(parent)
{
    //delegate=new MyDelegate;
    model = new QStandardItemModel;
    //model->setRowCount(3);
    model->setColumnCount(5);

    this->setModel(model);
    setColumnHidden(4,true);
    setColumnHidden(5,true);

    this->setGeometry(100,100,800,400);

    this->resizeColumnsToContents();
    this->resizeRowsToContents();

    this->setColumnWidth(0,190);


    for(int i=0;i<model->rowCount();i++)
        this->setRowHeight(i,30);//设置全部行高
    //this->set


}

//把数据插入到tableView中来
int MyTableView::setModelData(MainInterface mainInterface)
{


    QString otherName = mainInterface.getOtherName();
    int isSelected = mainInterface.getIsSelected();
    int isMust = mainInterface.getIsMust();
    QString paraName = mainInterface.getParaName();
    QString para = mainInterface.getPara();

    QList<QStandardItem *> items;
    for(int i=0;i<5;i++)
    {

        QStandardItem *item;
       if(i==0)//第一列设值
       {
          item = new QStandardItem(otherName);

       }
       if(i==1)//第二列设值
       {
           if(isSelected!=0)
           {
            item = new QStandardItem("true");
           }
           else
            {
              item = new QStandardItem("");
           }

       }
       if(i==2)//第三列设值
       {
           if(isMust==1)
            item = new QStandardItem("1");
           else
            item = new QStandardItem("0");
       }
       if(i==3)//第四列设值
       {
          item = new QStandardItem(paraName);
       }
       if(i==4)//第五列设值
       {
          item = new QStandardItem(para);
       }
        items.append(item);

    }
    model->appendRow(items);
}

//得到tableView中的数据
QList<MainInterface> MyTableView::getModelData()
{
    QList<MainInterface> list;
    //上下交换
    int row = model->rowCount();//得到行数
    int column = model->columnCount();//得到列数

    for(int i=0;i<row;i++)
    {
        MainInterface interface;
        QVariant data[5];
        for(int j=0;j<column;j++)
        {
                QModelIndex index1 = model->index(i,j);//获得i行j列的单元格
                data[j] = index1.data();
                QString data1 = data[j].toString();
                if(j==0)//第一列
                {
                    interface.setOtherName(data1);
                }
                if(j==1)//第二列
                {
                    if(data1=="true")
                        interface.setIsSelected(1);
                    else
                        interface.setIsSelected(0);
                }
                if(j==2)//第三列
                {
                    if(data1=="1")
                        interface.setIsMust(1);
                    else
                        interface.setIsMust(0);
                }
                if(j==3)//第四列
                {
                    interface.setParaName(data1);
                }
                if(j==4)//第五列
                {
                    interface.setPara(data1);
                }

         }
        interface.setMainId(i);
        interface.setSite(i);
        list.append(interface);
    }

    return list;

}
