#ifndef SHOUHOU_PRODUCT_H
#define SHOUHOU_PRODUCT_H

#include <QWidget>
#include <impl/afterservice.h>
#include <impl/afterserviceimpl.h>

namespace Ui {
class Shouhou_product;
}

class Shouhou_product : public QWidget
{
    Q_OBJECT
    
public:
    explicit Shouhou_product(QWidget *parent = 0);
    ~Shouhou_product();
    
private:
    Ui::Shouhou_product *ui;

public slots:
    void returnIndex();//zhuye
    void returnPage();//fanhuicaidan
    void slotSave();//保存售后信息

private:
    void showServiceData();//显示售后信息

private:
    AfterServiceImpl *afterServiceImpl;//售后服务数据接口
};

#endif // SHOUHOU_PRODUCT_H
