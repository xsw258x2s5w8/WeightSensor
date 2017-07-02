#ifndef BUWANZHENG_CHAXUN_H
#define BUWANZHENG_CHAXUN_H

#include <QWidget>

namespace Ui {
class Buwanzheng_chaxun;
}

class Buwanzheng_chaxun : public QWidget
{
    Q_OBJECT
    
public:
    explicit Buwanzheng_chaxun(QWidget *parent = 0);
    ~Buwanzheng_chaxun();
    
private:
    Ui::Buwanzheng_chaxun *ui;

public slots:
    void returnIndex();//主页
    void returnPage();//返回上一页
};

#endif // BUWANZHENG_CHAXUN_H
