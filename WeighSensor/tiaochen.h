#ifndef TIAOCHEN_H
#define TIAOCHEN_H

#include <QWidget>

namespace Ui {
class Tiaochen;
}

class Tiaochen : public QWidget
{
    Q_OBJECT
    
public:
    explicit Tiaochen(QWidget *parent = 0);
    ~Tiaochen();
    
private:
    Ui::Tiaochen *ui;

public slots:
    void returnIndex();//zhuye
    void returnPage();//fanhuicaidan
    void showAddress();//设置地址界面
    void showAdjustAngle();//调角界面
    void showBalanceState();//显示秤台状态界面
    void showBalanceValue();//显示秤台参数界面
    void showtiaochen_2();//显示调秤下一页
};

#endif // TIAOCHEN_H
