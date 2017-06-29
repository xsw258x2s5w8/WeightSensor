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
    void showMeterInformation();//进入仪表信息界面
    void showNext();//进入检测下一页面
};

#endif // JIANCE_H
