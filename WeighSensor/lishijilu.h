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
};

#endif // LISHIJILU_H
