#ifndef WANZHENG_CHAXUN_H
#define WANZHENG_CHAXUN_H

#include <QWidget>

namespace Ui {
class Wanzheng_chaxun;
}

class Wanzheng_chaxun : public QWidget
{
    Q_OBJECT
    
public:
    explicit Wanzheng_chaxun(QWidget *parent = 0);
    ~Wanzheng_chaxun();
    
private:
    Ui::Wanzheng_chaxun *ui;

public slots:
    void returnIndex();//主页
    void returnPage();//返回上一页
};

#endif // WANZHENG_CHAXUN_H
