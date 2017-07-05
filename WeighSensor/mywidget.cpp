#include "mywidget.h"
#include <QStyleOption>
#include <QPainter>
#include <QStyle>
myWidget::myWidget(QWidget *parent) :
    QWidget(parent)
{

    //设置大小和位置
    this->setGeometry(1, 1, 298, 192);
    //设置背景色为白色
    this->setStyleSheet("background-color:rgb(255, 255, 255);");
}


void myWidget::mousePressEvent(QMouseEvent *ev)
{
    //把信号传给clicked()函数
    emit clicked();

}

void myWidget::paintEvent(QPaintEvent *)
{
    QStyleOption opt;
    opt.init(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}
