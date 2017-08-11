#ifndef SHOUHOU_H
#define SHOUHOU_H

#include <QWidget>
#include <impl/afterservice.h>
#include <impl/afterserviceimpl.h>

namespace Ui {
class Shouhou;
}

class Shouhou : public QWidget
{
    Q_OBJECT
    
public:
    explicit Shouhou(QWidget *parent = 0);
    ~Shouhou();
    
private:
    Ui::Shouhou *ui;

public slots:
    void returnIndex();//zhuye
    void returnPage();//fanhuicaidan

private:
    void showServiceData();//显示售后信息

private:
    AfterServiceImpl *afterServiceImpl;//售后服务数据接口
};

#endif // SHOUHOU_H
