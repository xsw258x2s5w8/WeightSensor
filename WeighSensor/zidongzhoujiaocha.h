#ifndef ZIDONGZHOUJIAOCHA_H
#define ZIDONGZHOUJIAOCHA_H

#include <QWidget>

namespace Ui {
class Zidongzhoujiaocha;
}

class Zidongzhoujiaocha : public QWidget
{
    Q_OBJECT
    
public:
    explicit Zidongzhoujiaocha(QWidget *parent = 0);
    ~Zidongzhoujiaocha();
    
private:
    Ui::Zidongzhoujiaocha *ui;

public slots:
    void returnIndex();//主页
    void returnPage();//返回上一页
    void showconfirmAxis();//进入压轴确认界面
};

#endif // ZIDONGZHOUJIAOCHA_H
