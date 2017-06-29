#ifndef YIBIAOXINXI_H
#define YIBIAOXINXI_H

#include <QWidget>

namespace Ui {
class Yibiaoxinxi;
}

class Yibiaoxinxi : public QWidget
{
    Q_OBJECT
    
public:
    explicit Yibiaoxinxi(QWidget *parent = 0);
    ~Yibiaoxinxi();
    
private:
    Ui::Yibiaoxinxi *ui;

public slots:
    void returnIndex();//主页
    void returnPage();//返回上一页
};

#endif // YIBIAOXINXI_H
