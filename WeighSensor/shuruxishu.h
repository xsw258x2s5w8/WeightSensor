#ifndef SHURUXISHU_H
#define SHURUXISHU_H

#include <QWidget>

namespace Ui {
class Shuruxishu;
}

class Shuruxishu : public QWidget
{
    Q_OBJECT
    
public:
    explicit Shuruxishu(QWidget *parent = 0);
    ~Shuruxishu();
    
private:
    Ui::Shuruxishu *ui;

public slots:
    void returnIndex();//主页
    void returnPage();//返回上一页
};

#endif // SHURUXISHU_H
