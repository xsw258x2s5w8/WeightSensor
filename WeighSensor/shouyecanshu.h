#ifndef SHOUYECANSHU_H
#define SHOUYECANSHU_H

#include <QWidget>
#include "lib/mydelegate.h"
#include "lib/mytableview.h"
#include "impl/maininterfaceimpl.h"
#include "impl/maininterface.h"
#include "impl/maininterfacetemp.h"
#include "impl/maininterfacetempimpl.h"

namespace Ui {
class Shouyecanshu;
}

class Shouyecanshu : public QWidget
{
    Q_OBJECT
    
public:
    explicit Shouyecanshu(QWidget *parent = 0);
    ~Shouyecanshu();
    
private:
    Ui::Shouyecanshu *ui;
    MyTableView *mytableview;//用于显示自定义table的表格控件
    MainInterfaceImpl *maininterfaceimpl;//数据接口
    MainInterfaceTempImpl *maininterfacetempimpl; //数据接口

private:
    void showTableData();//显示表格数据

public slots:
    void returnIndex();//zhuye
    void returnPage();//fanhuicaidan
    void slotSave();//保存按钮
};

#endif // SHOUYECANSHU_H
