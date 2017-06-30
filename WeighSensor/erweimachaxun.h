#ifndef ERWEIMACHAXUN_H
#define ERWEIMACHAXUN_H

#include <QWidget>

namespace Ui {
class Erweimachaxun;
}

class Erweimachaxun : public QWidget
{
    Q_OBJECT
    
public:
    explicit Erweimachaxun(QWidget *parent = 0);
    ~Erweimachaxun();
    
private:
    Ui::Erweimachaxun *ui;

public slots:
    void returnIndex();//主页
    void returnPage();//返回上一页
};

#endif // ERWEIMACHAXUN_H
