#ifndef TIAOJIAO_H
#define TIAOJIAO_H

#include <QWidget>

namespace Ui {
class Tiaojiao;
}

class Tiaojiao : public QWidget
{
    Q_OBJECT
    
public:
    explicit Tiaojiao(QWidget *parent = 0);
    ~Tiaojiao();
    
private:
    Ui::Tiaojiao *ui;

public slots:
    void returnIndex();//主页
    void returnPage();//返回上一页
};

#endif // TIAOJIAO_H
