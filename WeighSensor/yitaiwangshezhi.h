#ifndef YITAIWANGSHEZHI_H
#define YITAIWANGSHEZHI_H

#include <QWidget>

namespace Ui {
class Yitaiwangshezhi;
}

class Yitaiwangshezhi : public QWidget
{
    Q_OBJECT
    
public:
    explicit Yitaiwangshezhi(QWidget *parent = 0);
    ~Yitaiwangshezhi();
    
private:
    Ui::Yitaiwangshezhi *ui;

public slots:
    void returnIndex();//主页
    void returnPage();//返回上一页
};

#endif // YITAIWANGSHEZHI_H
