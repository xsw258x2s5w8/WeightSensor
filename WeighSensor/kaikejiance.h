#ifndef KAIKEJIANCE_H
#define KAIKEJIANCE_H

#include <QWidget>

namespace Ui {
class Kaikejiance;
}

class Kaikejiance : public QWidget
{
    Q_OBJECT
    
public:
    explicit Kaikejiance(QWidget *parent = 0);
    ~Kaikejiance();
    
private:
    Ui::Kaikejiance *ui;

public slots:
    void returnIndex();//zhuye
    void returnPage();//fanhuicaidan
};

#endif // KAIKEJIANCE_H
