#ifndef WANGLUOSHEZHI_H
#define WANGLUOSHEZHI_H

#include <QWidget>

namespace Ui {
class Wangluoshezhi;
}

class Wangluoshezhi : public QWidget
{
    Q_OBJECT
    
public:
    explicit Wangluoshezhi(QWidget *parent = 0);
    ~Wangluoshezhi();
    
private:
    Ui::Wangluoshezhi *ui;

public slots:
    void returnIndex();//主页
    void returnPage();//返回上一页
    void showEthernet();//显示以太网设置界面
    void showWifi();//显示wifi连接界面
    void showBluetooth();//显示蓝牙设备连接界面
};

#endif // WANGLUOSHEZHI_H
