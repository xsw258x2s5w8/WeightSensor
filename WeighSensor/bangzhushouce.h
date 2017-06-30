#ifndef BANGZHUSHOUCE_H
#define BANGZHUSHOUCE_H

#include <QWidget>

namespace Ui {
class Bangzhushouce;
}

class Bangzhushouce : public QWidget
{
    Q_OBJECT
    
public:
    explicit Bangzhushouce(QWidget *parent = 0);
    ~Bangzhushouce();
    
private:
    Ui::Bangzhushouce *ui;

public slots:
    void returnIndex();//主页
    void returnPage();//返回上一页
    void showNext();//显示next页面
    void showPreview();//显示preview页面
};

#endif // BANGZHUSHOUCE_H
