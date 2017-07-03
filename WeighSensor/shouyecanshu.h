#ifndef SHOUYECANSHU_H
#define SHOUYECANSHU_H

#include <QWidget>

namespace Ui {
class Shouyecanshu;
}

class Shouyecanshu : public QWidget
{
    Q_OBJECT
    
public:
    explicit Shouyecanshu(QWidget *parent = 0);
    ~Shouyecanshu();
    
private:
    Ui::Shouyecanshu *ui;

public slots:
    void returnIndex();//zhuye
    void returnPage();//fanhuicaidan
};

#endif // SHOUYECANSHU_H
