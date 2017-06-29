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
    void showCheck();//进入Rs232检测页面
    void showStorage();//进入存储器检测
    void showCheckVideo();//进入显示屏检测页面
    void showCheckLight();//进入背光检测界面
    void showService();//进入售后检测界面
    void showLight();//进入供电检测界面
};

#endif // JIANCE_H
