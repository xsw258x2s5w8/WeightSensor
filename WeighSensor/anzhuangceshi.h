#ifndef ANZHUANGCESHI_H
#define ANZHUANGCESHI_H

#include <QWidget>

namespace Ui {
class Anzhuangceshi;
}

class Anzhuangceshi : public QWidget
{
    Q_OBJECT
    
public:
    explicit Anzhuangceshi(QWidget *parent = 0);
    ~Anzhuangceshi();
    
private:
    Ui::Anzhuangceshi *ui;

public slots:
    void returnIndex();//主页
    void returnPage();//返回上一页
    void showInformation();//进入详情页面
};

#endif // ANZHUANGCESHI_H
