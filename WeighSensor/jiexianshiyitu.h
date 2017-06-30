#ifndef JIEXIANSHIYITU_H
#define JIEXIANSHIYITU_H

#include <QWidget>

namespace Ui {
class Jiexianshiyitu;
}

class Jiexianshiyitu : public QWidget
{
    Q_OBJECT
    
public:
    explicit Jiexianshiyitu(QWidget *parent = 0);
    ~Jiexianshiyitu();
    
private:
    Ui::Jiexianshiyitu *ui;

public slots:
    void returnIndex();//zhuye
    void returnPage();//fanhuicaidan
};

#endif // JIEXIANSHIYITU_H
