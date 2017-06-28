#ifndef TIAOCHEN_H
#define TIAOCHEN_H

#include <QWidget>

namespace Ui {
class Tiaochen;
}

class Tiaochen : public QWidget
{
    Q_OBJECT
    
public:
    explicit Tiaochen(QWidget *parent = 0);
    ~Tiaochen();
    
private:
    Ui::Tiaochen *ui;

public slots:
    void returnIndex();//zhuye
    void returnPage();//fanhuicaidan
    void showAddress();
};

#endif // TIAOCHEN_H
