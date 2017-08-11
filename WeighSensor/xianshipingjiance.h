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

private:
    int number;//用于检测点击的次数

public slots:
  void returnIndex();//zhuye
  void returnPage();//fanhuicaidan

  void slotTest();//还背景颜色
};

#endif // XIANSHIPINGJIANCE_H
