#ifndef BANGZHUSHOUCE1_H
#define BANGZHUSHOUCE1_H

#include <QWidget>

namespace Ui {
class Bangzhushouce1;
}

class Bangzhushouce1 : public QWidget
{
    Q_OBJECT
    
public:
    explicit Bangzhushouce1(QWidget *parent = 0);
    ~Bangzhushouce1();
    
private:
    Ui::Bangzhushouce1 *ui;


public slots:
    void returnIndex();//主页
    void returnPage();//返回上一页
};

#endif // BANGZHUSHOUCE1_H
