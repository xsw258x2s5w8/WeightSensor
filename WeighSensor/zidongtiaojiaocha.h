#ifndef ZIDONGTIAOJIAOCHA_H
#define ZIDONGTIAOJIAOCHA_H

#include <QWidget>

namespace Ui {
class Zidongtiaojiaocha;
}

class Zidongtiaojiaocha : public QWidget
{
    Q_OBJECT
    
public:
    explicit Zidongtiaojiaocha(QWidget *parent = 0);
    ~Zidongtiaojiaocha();
    
private:
    Ui::Zidongtiaojiaocha *ui;

public slots:
    void returnIndex();//主页
    void returnPage();//返回上一页
    void showconfirmWeigh();//进入压角确认界面
};

#endif // ZIDONGTIAOJIAOCHA_H
