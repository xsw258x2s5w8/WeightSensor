#ifndef WANZHENG_H
#define WANZHENG_H

#include <QWidget>

namespace Ui {
class Wanzheng;
}

class Wanzheng : public QWidget
{
    Q_OBJECT
    
public:
    explicit Wanzheng(QWidget *parent = 0);
    ~Wanzheng();
    
private:
    Ui::Wanzheng *ui;

public slots:
    void returnIndex();//主页
    void returnPage();//返回上一页
    void showQuery();//显示完整查询界面
};

#endif // WANZHENG_H
