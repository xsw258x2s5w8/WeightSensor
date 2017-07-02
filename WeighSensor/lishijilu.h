#ifndef LISHIJILU_H
#define LISHIJILU_H

#include <QWidget>

namespace Ui {
class Lishijilu;
}

class Lishijilu : public QWidget
{
    Q_OBJECT
    
public:
    explicit Lishijilu(QWidget *parent = 0);
    ~Lishijilu();
    
private:
    Ui::Lishijilu *ui;

public slots:
    void returnIndex();//主页
    void returnPage();//返回上一页
    void showAll();//进入完整历史记录界面
    void showIncomplete();//进入不完整的记录界面
    void showPrintTable();//进入报表打印界面
    void showClear();//进入清除界面
};

#endif // LISHIJILU_H
