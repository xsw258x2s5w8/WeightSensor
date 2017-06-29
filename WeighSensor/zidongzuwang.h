#ifndef ZIDONGZUWANG_H
#define ZIDONGZUWANG_H

#include <QWidget>

namespace Ui {
class Zidongzuwang;
}

class Zidongzuwang : public QWidget
{
    Q_OBJECT
    
public:
    explicit Zidongzuwang(QWidget *parent = 0);
    ~Zidongzuwang();
    
private:
    Ui::Zidongzuwang *ui;


public slots:
    void returnIndex();//主页
    void returnPage();//返回上一页、
    void showKongcheng();//进入空秤确认界面
};

#endif // ZIDONGZUWANG_H
