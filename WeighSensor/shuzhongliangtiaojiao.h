#ifndef SHUZHONGLIANGTIAOJIAO_H
#define SHUZHONGLIANGTIAOJIAO_H

#include <QWidget>

namespace Ui {
class Shuzhongliangtiaojiao;
}

class Shuzhongliangtiaojiao : public QWidget
{
    Q_OBJECT
    
public:
    explicit Shuzhongliangtiaojiao(QWidget *parent = 0);
    ~Shuzhongliangtiaojiao();
    
private:
    Ui::Shuzhongliangtiaojiao *ui;

public slots:
    void returnIndex();//主页
    void returnPage();//返回上一页
    void showSetWeight();//输入重量调角界面
};

#endif // SHUZHONGLIANGTIAOJIAO_H
