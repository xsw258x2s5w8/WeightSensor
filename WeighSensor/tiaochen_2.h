#ifndef TIAOCHEN_2_H
#define TIAOCHEN_2_H

#include <QWidget>
#include "impl/useraliveimpl.h"
namespace Ui {
class Tiaochen_2;
}

class Tiaochen_2 : public QWidget
{
    Q_OBJECT
    
public:
    explicit Tiaochen_2(QWidget *parent = 0);
    ~Tiaochen_2();
    
private:
    Ui::Tiaochen_2 *ui;
    UserAliveImpl useraliveimpl;
public slots:
    void returnIndex();//zhuye
    void returnPage();//fanhuicaidan
    void showtiaochen();//显示调秤上一页
    void showOverload();//进入超载查询页面
    void showCommunication();//进入通讯保护界面
    void showCheck();//进入检定界面
};

#endif // TIAOCHEN_2_H
