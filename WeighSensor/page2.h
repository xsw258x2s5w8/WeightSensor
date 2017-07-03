#ifndef PAGE2_H
#define PAGE2_H

#include <QWidget>

namespace Ui {
class page2;
}

class page2 : public QWidget
{
    Q_OBJECT
    
public:
    explicit page2(QWidget *parent = 0);
    ~page2();
    
private:
    Ui::page2 *ui;

public slots:
    void returnIndex();//主页
    void showPermission();//权限界面
    void returnPage();//上一页
    void showAdjustable();//调秤界面
    void showUnmanned();//无人值守
    void showCheck();//检测
    void showVideo();//视频设置
    void showQRcode();//二维码管理
    void showPrint();//打印设置界面
    void showNext();//下一页菜单
    void showEditIndex();//进入编辑主页面
};

#endif // PAGE2_H
