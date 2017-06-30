#ifndef DAYIN_H
#define DAYIN_H

#include <QWidget>

namespace Ui {
class Dayin;
}

class Dayin : public QWidget
{
    Q_OBJECT
    
public:
    explicit Dayin(QWidget *parent = 0);
    ~Dayin();
    
private:
    Ui::Dayin *ui;

public slots:
    void returnIndex();//主页
    void returnPage();//返回上一页
    void showPrintValue();//打印参数页面
};

#endif // DAYIN_H
