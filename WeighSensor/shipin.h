#ifndef SHIPIN_H
#define SHIPIN_H

#include <QWidget>

namespace Ui {
class Shipin;
}

class Shipin : public QWidget
{
    Q_OBJECT
    
public:
    explicit Shipin(QWidget *parent = 0);
    ~Shipin();
    
private:
    Ui::Shipin *ui;

public slots:
    void returnIndex();//主页
    void returnPage();//返回上一页
    void showOneFrame();//显示一路画面
    void showFourFrame();//显示思路画面
};

#endif // SHIPIN_H
