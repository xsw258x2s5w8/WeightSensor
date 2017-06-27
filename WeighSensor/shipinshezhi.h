#ifndef SHIPINSHEZHI_H
#define SHIPINSHEZHI_H

#include <QWidget>

namespace Ui {
class Shipinshezhi;
}

class Shipinshezhi : public QWidget
{
    Q_OBJECT
    
public:
    explicit Shipinshezhi(QWidget *parent = 0);
    ~Shipinshezhi();
    
private:
    Ui::Shipinshezhi *ui;
public slots:
    void returnIndex();//zhuye
    void returnPage();//fanhuicaidan
};

#endif // SHIPINSHEZHI_H
