#ifndef ERCIGUOBANG_H
#define ERCIGUOBANG_H

#include <QWidget>

namespace Ui {
class Erciguobang;
}

class Erciguobang : public QWidget
{
    Q_OBJECT
    
public:
    explicit Erciguobang(QWidget *parent = 0);
    ~Erciguobang();
    
private:
    Ui::Erciguobang *ui;

public slots:
    void returnIndex();//主页
    void returnPage();//返回上一页
};

#endif // ERCIGUOBANG_H
