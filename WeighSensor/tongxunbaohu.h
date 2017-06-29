#ifndef TONGXUNBAOHU_H
#define TONGXUNBAOHU_H

#include <QWidget>

namespace Ui {
class Tongxunbaohu;
}

class Tongxunbaohu : public QWidget
{
    Q_OBJECT
    
public:
    explicit Tongxunbaohu(QWidget *parent = 0);
    ~Tongxunbaohu();
    
private:
    Ui::Tongxunbaohu *ui;

public slots:
    void returnIndex();//主页
    void returnPage();//返回上一页
};

#endif // TONGXUNBAOHU_H
