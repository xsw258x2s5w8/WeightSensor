#ifndef TIAOJIAO_H
#define TIAOJIAO_H

#include <QWidget>

namespace Ui {
class Tiaojiao;
}

class Tiaojiao : public QWidget
{
    Q_OBJECT
    
public:
    explicit Tiaojiao(QWidget *parent = 0);
    ~Tiaojiao();
    
private:
    Ui::Tiaojiao *ui;

public slots:
    void returnIndex();//主页
    void returnPage();//返回上一页
    void showSetAngleValue();//显示输入系数调角页面
    void showautoSetAnglevalue();//进入自动调角差的界面
    void showautoSetAxisAngle();//进入自动轴角差
    void showautoSetWeight();//进入输入调角界面
};

#endif // TIAOJIAO_H
