#ifndef MYLINEEDIT_H
#define MYLINEEDIT_H

#include <QLineEdit>

class mylineedit : public QLineEdit
{
    Q_OBJECT
public:
    explicit mylineedit(QWidget *parent = 0);

private:
    //重写mousePressEvent事件
    virtual void mousePressEvent(QMouseEvent *event);
    void showChehao();
public slots:

};

#endif // MYLINEEDIT_H
