#ifndef BIAODING_1_H
#define BIAODING_1_H

#include <QWidget>

namespace Ui {
class Biaoding_1;
}

class Biaoding_1 : public QWidget
{
    Q_OBJECT
    
public:
    explicit Biaoding_1(QWidget *parent = 0);
    ~Biaoding_1();
    
private:
    Ui::Biaoding_1 *ui;

public slots:
    void returnIndex();//主页
    void returnPage();//返回上一页
    void showConfirmCalibration();//点击确认进入第二个标定点界面
    void showSkipCalibration();//点击跳过 进入第二个标定界面。
};

#endif // BIAODING_1_H
