#ifndef WANGJIMIMA_H
#define WANGJIMIMA_H

#include <QWidget>

namespace Ui {
class Wangjimima;
}

class Wangjimima : public QWidget
{
    Q_OBJECT
    
public:
    explicit Wangjimima(QWidget *parent = 0);
    ~Wangjimima();
    
private:
    Ui::Wangjimima *ui;

public slots:
    void returnIndex();//主页
    void returnPage();//返回上一页
};

#endif // WANGJIMIMA_H
