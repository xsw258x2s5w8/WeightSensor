#ifndef LANYA_H
#define LANYA_H

#include <QWidget>

namespace Ui {
class Lanya;
}

class Lanya : public QWidget
{
    Q_OBJECT
    
public:
    explicit Lanya(QWidget *parent = 0);
    ~Lanya();
    
private:
    Ui::Lanya *ui;

public slots:
    void returnIndex();//主页
    void returnPage();//返回上一页
};

#endif // LANYA_H
