#ifndef SHOUHOU_H
#define SHOUHOU_H

#include <QWidget>

namespace Ui {
class Shouhou;
}

class Shouhou : public QWidget
{
    Q_OBJECT
    
public:
    explicit Shouhou(QWidget *parent = 0);
    ~Shouhou();
    
private:
    Ui::Shouhou *ui;

public slots:
    void returnIndex();//zhuye
    void returnPage();//fanhuicaidan
};

#endif // SHOUHOU_H
