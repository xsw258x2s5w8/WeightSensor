#ifndef DAYINCANSHU_H
#define DAYINCANSHU_H

#include <QWidget>

namespace Ui {
class Dayincanshu;
}

class Dayincanshu : public QWidget
{
    Q_OBJECT
    
public:
    explicit Dayincanshu(QWidget *parent = 0);
    void initialize();//初始化参数
    ~Dayincanshu();
    
private:
    Ui::Dayincanshu *ui;

public slots:
    void returnIndex();//主页
    void returnPage();//返回上一页
};

#endif // DAYINCANSHU_H
