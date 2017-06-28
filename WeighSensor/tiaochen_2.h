#ifndef TIAOCHEN_2_H
#define TIAOCHEN_2_H

#include <QWidget>

namespace Ui {
class Tiaochen_2;
}

class Tiaochen_2 : public QWidget
{
    Q_OBJECT
    
public:
    explicit Tiaochen_2(QWidget *parent = 0);
    ~Tiaochen_2();
    
private:
    Ui::Tiaochen_2 *ui;

public slots:
    void returnIndex();//zhuye
    void returnPage();//fanhuicaidan
    void showtiaochen();//显示调秤上一页
};

#endif // TIAOCHEN_2_H
