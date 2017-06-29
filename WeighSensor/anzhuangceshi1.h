#ifndef ANZHUANGCESHI1_H
#define ANZHUANGCESHI1_H

#include <QWidget>

namespace Ui {
class Anzhuangceshi1;
}

class Anzhuangceshi1 : public QWidget
{
    Q_OBJECT
    
public:
    explicit Anzhuangceshi1(QWidget *parent = 0);
    ~Anzhuangceshi1();
    
private:
    Ui::Anzhuangceshi1 *ui;


public slots:
    void returnIndex();//主页
    void returnPage();//返回上一页
};

#endif // ANZHUANGCESHI1_H
