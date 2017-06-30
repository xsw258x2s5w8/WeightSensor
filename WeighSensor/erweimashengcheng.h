#ifndef ERWEIMASHENGCHENG_H
#define ERWEIMASHENGCHENG_H

#include <QWidget>

namespace Ui {
class Erweimashengcheng;
}

class Erweimashengcheng : public QWidget
{
    Q_OBJECT
    
public:
    explicit Erweimashengcheng(QWidget *parent = 0);
    ~Erweimashengcheng();
    
private:
    Ui::Erweimashengcheng *ui;

public slots:
    void returnIndex();//主页
    void returnPage();//返回上一页
};

#endif // ERWEIMASHENGCHENG_H
