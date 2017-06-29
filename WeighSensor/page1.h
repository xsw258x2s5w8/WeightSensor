#ifndef PAGE1_H
#define PAGE1_H

#include <QWidget>

namespace Ui {
class page1;
}

class page1 : public QWidget
{
    Q_OBJECT
    
public:
    explicit page1(QWidget *parent = 0);
    ~page1();
    
private:
    Ui::page1 *ui;
public slots:
    void returnIndex();//zhuye
    void returnPage();//fanhuicaidan
    void showForget();//进入忘记密码界面
    void showsetFinish();//设置密码完成，返回菜单界面。
};

#endif // PAGE1_H
