#ifndef YAJIAOQUERENDIZHI_H
#define YAJIAOQUERENDIZHI_H

#include <QWidget>

namespace Ui {
class Yajiaoquerendizhi;
}

class Yajiaoquerendizhi : public QWidget
{
    Q_OBJECT
    
public:
    explicit Yajiaoquerendizhi(QWidget *parent = 0);
    ~Yajiaoquerendizhi();
    
private:
    Ui::Yajiaoquerendizhi *ui;

public slots:
    void returnIndex();//主页
    void returnPage();//返回上一页
};

#endif // YAJIAOQUERENDIZHI_H
