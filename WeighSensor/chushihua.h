#ifndef CHUSHIHUA_H
#define CHUSHIHUA_H

#include <QWidget>

namespace Ui {
class Chushihua;
}

class Chushihua : public QWidget
{
    Q_OBJECT
    
public:
    explicit Chushihua(QWidget *parent = 0);
    ~Chushihua();
    
private:
    Ui::Chushihua *ui;

public slots:
    void returnIndex();//主页
    void returnPage();//返回上一页
};

#endif // CHUSHIHUA_H
