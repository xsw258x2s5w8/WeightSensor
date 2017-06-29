#ifndef KONGCHENGQUEREN_H
#define KONGCHENGQUEREN_H

#include <QWidget>

namespace Ui {
class Kongchengqueren;
}

class Kongchengqueren : public QWidget
{
    Q_OBJECT
    
public:
    explicit Kongchengqueren(QWidget *parent = 0);
    ~Kongchengqueren();
    
private:
    Ui::Kongchengqueren *ui;

public slots:
    void returnIndex();//主页
    void returnPage();//返回上一页、
    void showAngleAddress();//进入压角确认地址
};

#endif // KONGCHENGQUEREN_H
