#ifndef MYLINEEDIT1_H
#define MYLINEEDIT1_H

#include <QLineEdit>

class mylineedit1 : public QLineEdit
{
    Q_OBJECT
public:
    explicit mylineedit1(QWidget *parent = 0);

private:
    //重写mousePressEvent事件
    virtual void mousePressEvent(QMouseEvent *event);
    void showHuohao();
public slots:

};


#endif // MYLINEEDIT1_H
