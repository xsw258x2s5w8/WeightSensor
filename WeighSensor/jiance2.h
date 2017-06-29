#ifndef JIANCE2_H
#define JIANCE2_H

#include <QWidget>

namespace Ui {
class Jiance2;
}

class Jiance2 : public QWidget
{
    Q_OBJECT
    
public:
    explicit Jiance2(QWidget *parent = 0);
    ~Jiance2();
    
private:
    Ui::Jiance2 *ui;

public slots:
    void returnIndex();//zhuye
    void returnPage();//fanhuicaidan
    void showPreview();//显示检测的前面一页
    void showKaiCheck();//显示开壳检测页面
};

#endif // JIANCE2_H
