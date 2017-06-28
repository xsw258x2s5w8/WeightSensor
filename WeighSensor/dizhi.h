#ifndef DIZHI_H
#define DIZHI_H

#include <QWidget>

namespace Ui {
class Dizhi;
}

class Dizhi : public QWidget
{
    Q_OBJECT
    
public:
    explicit Dizhi(QWidget *parent = 0);
    ~Dizhi();
    
private:
    Ui::Dizhi *ui;

public slots:
    void returnIndex();//主页
    void returnPage();//返回上一页
    void showSingleAddress();//单个设置界面
};

#endif // DIZHI_H