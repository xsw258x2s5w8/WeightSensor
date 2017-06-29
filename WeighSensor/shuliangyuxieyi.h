#ifndef SHULIANGYUXIEYI_H
#define SHULIANGYUXIEYI_H

#include <QWidget>

namespace Ui {
class Shuliangyuxieyi;
}

class Shuliangyuxieyi : public QWidget
{
    Q_OBJECT
    
public:
    explicit Shuliangyuxieyi(QWidget *parent = 0);
    ~Shuliangyuxieyi();
    
private:
    Ui::Shuliangyuxieyi *ui;

public slots:
    void returnIndex();//zhuye
    void returnPage();//fanhuicaidan
};

#endif // SHULIANGYUXIEYI_H
