#ifndef BUWANZHENG_H
#define BUWANZHENG_H

#include <QWidget>

namespace Ui {
class Buwanzheng;
}

class Buwanzheng : public QWidget
{
    Q_OBJECT
    
public:
    explicit Buwanzheng(QWidget *parent = 0);
    ~Buwanzheng();
    
private:
    Ui::Buwanzheng *ui;

public slots:
    void returnIndex();//主页
    void returnPage();//返回上一页
    void showQuery();//进入不完整查询页面
};

#endif // BUWANZHENG_H
