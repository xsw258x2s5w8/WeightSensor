#ifndef SHURUXISHUTIOAJIAO_H
#define SHURUXISHUTIOAJIAO_H

#include <QWidget>

namespace Ui {
class Shuruxishutioajiao;
}

class Shuruxishutioajiao : public QWidget
{
    Q_OBJECT
    
public:
    explicit Shuruxishutioajiao(QWidget *parent = 0);
    ~Shuruxishutioajiao();
    
private:
    Ui::Shuruxishutioajiao *ui;

public slots:
    void returnIndex();//主页
    void returnPage();//返回上一页
    void showValue();//设置输入系数界面
};

#endif // SHURUXISHUTIOAJIAO_H
