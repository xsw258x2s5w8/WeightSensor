#ifndef YIBIAOXINXI_H
#define YIBIAOXINXI_H

#include <QWidget>
#include <impl/instinfo.h>
#include <impl/instinfoimpl.h>

namespace Ui {
class Yibiaoxinxi;
}

class Yibiaoxinxi : public QWidget
{
    Q_OBJECT
    
public:
    explicit Yibiaoxinxi(QWidget *parent = 0);
    ~Yibiaoxinxi();
    
private:
    Ui::Yibiaoxinxi *ui;

public slots:
    void returnIndex();//主页
    void returnPage();//返回上一页

private:
   void showInstData();//显示数据

private:
    InstInfoImpl *instinfoimpl;//仪表信息表的接口
};

#endif // YIBIAOXINXI_H
