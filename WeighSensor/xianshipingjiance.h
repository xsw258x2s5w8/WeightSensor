#ifndef XIANSHIPINGJIANCE_H
#define XIANSHIPINGJIANCE_H

#include <QWidget>

namespace Ui {
class Xianshipingjiance;
}

class Xianshipingjiance : public QWidget
{
    Q_OBJECT
    
public:
    explicit Xianshipingjiance(QWidget *parent = 0);
    ~Xianshipingjiance();
    
private:
    Ui::Xianshipingjiance *ui;

public slots:
  void returnIndex();//zhuye
  void returnPage();//fanhuicaidan
};

#endif // XIANSHIPINGJIANCE_H
