#ifndef WIFI_H
#define WIFI_H

#include <QWidget>

namespace Ui {
class Wifi;
}

class Wifi : public QWidget
{
    Q_OBJECT
    
public:
    explicit Wifi(QWidget *parent = 0);
    ~Wifi();
    
private:
    Ui::Wifi *ui;

public slots:
    void returnIndex();//主页
    void returnPage();//返回上一页
};

#endif // WIFI_H
