#ifndef JIANDINGSHIJIAN_H
#define JIANDINGSHIJIAN_H

#include <QWidget>

namespace Ui {
class Jiandingshijian;
}

class Jiandingshijian : public QWidget
{
    Q_OBJECT
    
public:
    explicit Jiandingshijian(QWidget *parent = 0);
    ~Jiandingshijian();
    
private:
    Ui::Jiandingshijian *ui;

public slots:
    void returnIndex();//zhuye
    void returnPage();//fanhuicaidan
};

#endif // JIANDINGSHIJIAN_H
