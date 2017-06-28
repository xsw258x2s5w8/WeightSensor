#ifndef SHEZHI_H
#define SHEZHI_H

#include <QWidget>

namespace Ui {
class Shezhi;
}

class Shezhi : public QWidget
{
    Q_OBJECT
    
public:
    explicit Shezhi(QWidget *parent = 0);
    ~Shezhi();
    
private:
    Ui::Shezhi *ui;

public slots:
    void returnIndex();//主页
    void returnPage();//返回上一页
};

#endif // SHEZHI_H
