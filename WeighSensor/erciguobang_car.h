#ifndef ERCIGUOBANG_CAR_H
#define ERCIGUOBANG_CAR_H

#include <QWidget>
#include<erciguobang_carname1.h>

namespace Ui {
class Erciguobang_car;
}

class Erciguobang_car : public QWidget
{
    Q_OBJECT
    
public:
    explicit Erciguobang_car(QWidget *parent = 0);
    ~Erciguobang_car();

private slots:
    void returnCarId();//返回二次过磅界面并传值
    void showCarName1();//打开设置车牌字界面

    void returnCarName1(QString data);//返回车牌字

    void returnPage();

signals:
    void sendCarId(QString data);

private:
    Ui::Erciguobang_car *ui;

    Erciguobang_carName1 *carName1;
};

#endif // ERCIGUOBANG_CAR_H
