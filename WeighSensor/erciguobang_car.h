#ifndef ERCIGUOBANG_CAR_H
#define ERCIGUOBANG_CAR_H

#include <QWidget>

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

    void returnPage();

signals:
    void sendCarId(QString data);

private:
    Ui::Erciguobang_car *ui;
};

#endif // ERCIGUOBANG_CAR_H
