#ifndef LIUCHENGSHEZHI_H
#define LIUCHENGSHEZHI_H

#include <QWidget>

namespace Ui {
class Liuchengshezhi;
}

class Liuchengshezhi : public QWidget
{
    Q_OBJECT
    
public:
    explicit Liuchengshezhi(QWidget *parent = 0);
    ~Liuchengshezhi();
    
private:
    Ui::Liuchengshezhi *ui;


public slots:
    void returnIndex();//zhuye
    void returnPage();//fanhuicaidan
};

#endif // LIUCHENGSHEZHI_H
