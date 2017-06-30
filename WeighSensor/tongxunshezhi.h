#ifndef TONGXUNSHEZHI_H
#define TONGXUNSHEZHI_H

#include <QWidget>

namespace Ui {
class Tongxunshezhi;
}

class Tongxunshezhi : public QWidget
{
    Q_OBJECT
    
public:
    explicit Tongxunshezhi(QWidget *parent = 0);
    ~Tongxunshezhi();
    
private:
    Ui::Tongxunshezhi *ui;

public slots:
    void returnIndex();//主页
    void returnPage();//返回上一页
};

#endif // TONGXUNSHEZHI_H
