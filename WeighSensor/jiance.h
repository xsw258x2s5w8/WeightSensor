#ifndef JIANCE_H
#define JIANCE_H

#include <QWidget>

namespace Ui {
class Jiance;
}

class Jiance : public QWidget
{
    Q_OBJECT
    
public:
    explicit Jiance(QWidget *parent = 0);
    ~Jiance();
    
private:
    Ui::Jiance *ui;

public slots:
    void returnIndex();//zhuye
    void returnPage();//fanhuicaidan
};

#endif // JIANCE_H
