#ifndef YIBIAOXINXI_PRODUCT_H
#define YIBIAOXINXI_PRODUCT_H

#include <QWidget>
#include <impl/instinfo.h>
#include <impl/instinfoimpl.h>

namespace Ui {
class Yibiaoxinxi_product;
}

class Yibiaoxinxi_product : public QWidget
{
    Q_OBJECT
    
public:
    explicit Yibiaoxinxi_product(QWidget *parent = 0);
    ~Yibiaoxinxi_product();
    
private:
    Ui::Yibiaoxinxi_product *ui;

public slots:
    void returnIndex();//主页
    void returnPage();//返回上一页

    void slotSave();//保存修改后的信息

private:
   void showInstData();//显示数据

private:
    InstInfoImpl *instinfoimpl;//仪表信息表的接口
};

#endif // YIBIAOXINXI_PRODUCT_H
