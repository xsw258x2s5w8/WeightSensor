#ifndef PCDERS232_H
#define PCDERS232_H

#include <QWidget>

namespace Ui {
class Pcders232;
}

class Pcders232 : public QWidget
{
    Q_OBJECT
    
public:
    explicit Pcders232(QWidget *parent = 0);
    ~Pcders232();
    
private:
    Ui::Pcders232 *ui;

public slots:
    void returnIndex();//主页
    void returnPage();//返回上一页

    void slotChooseBtn();//该槽判断 点击的按钮是哪个
};

#endif // PCDERS232_H
