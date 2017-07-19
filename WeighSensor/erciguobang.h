#ifndef ERCIGUOBANG_H
#define ERCIGUOBANG_H

#include <QWidget>
#include <erciguobang_car.h>

namespace Ui {
class Erciguobang;
}

class Erciguobang : public QWidget
{
    Q_OBJECT
    
public:
    explicit Erciguobang(QWidget *parent = 0);
    ~Erciguobang();

    
private:
    Ui::Erciguobang *ui;

    Erciguobang_car *carid;

public slots:
    void returnIndex();//主页
    void returnPage();//返回上一页
    void showCarData();//显示车牌设置界面

    void getCarData(QString data);//获得修改后的车牌号
    void getArtData(QString data);//获得修改后的货号
    void getRemarkData(QString data);//获得备注
};

#endif // ERCIGUOBANG_H
