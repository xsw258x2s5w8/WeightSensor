#ifndef DANGESHEDIZHI_H
#define DANGESHEDIZHI_H

#include <QWidget>

namespace Ui {
class Dangeshedizhi;
}

class Dangeshedizhi : public QWidget
{
    Q_OBJECT
    
public:
    explicit Dangeshedizhi(QWidget *parent = 0);
    ~Dangeshedizhi();
    
private:
    Ui::Dangeshedizhi *ui;

public slots:
    void returnIndex();//主页
    void returnPage();//返回上一页
    void showScan();//扫描设置界面
};

#endif // DANGESHEDIZHI_H
