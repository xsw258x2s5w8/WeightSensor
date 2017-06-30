#ifndef QUEDINGGENGXIN_H
#define QUEDINGGENGXIN_H

#include <QWidget>

namespace Ui {
class Quedinggengxin;
}

class Quedinggengxin : public QWidget
{
    Q_OBJECT
    
public:
    explicit Quedinggengxin(QWidget *parent = 0);
    ~Quedinggengxin();
    
private:
    Ui::Quedinggengxin *ui;

public slots:
    void Update();  //确定更新
    void Cancle();  //取消
};

#endif // QUEDINGGENGXIN_H
