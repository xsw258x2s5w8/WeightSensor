#ifndef CHENGTAICANSHU_H
#define CHENGTAICANSHU_H

#include <QWidget>

namespace Ui {
class Chengtaicanshu;
}

class Chengtaicanshu : public QWidget
{
    Q_OBJECT
    
public:
    explicit Chengtaicanshu(QWidget *parent = 0);
    ~Chengtaicanshu();
    
private:
    Ui::Chengtaicanshu *ui;

public slots:
    void returnIndex();//主页
    void returnPage();//返回上一页
};

#endif // CHENGTAICANSHU_H
