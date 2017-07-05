#include "mylineedit1.h"
#include <qdebug.h>
#include "huohao.h"
mylineedit1::mylineedit1(QWidget *parent) :
    QLineEdit(parent)
{

}
//重写mousePressEvent事件,检测事件类型是不是点击了鼠标左键
void mylineedit1::mousePressEvent(QMouseEvent *event) {
    //如果单击了就触发clicked信号
    showHuohao();

    //if (event->button() == Qt::LeftButton) {
        //触发clicked信号
    //    emit clicked();
    //}
    //将该事件传给父类处理
    QLineEdit::mousePressEvent(event);
}

void mylineedit1::showHuohao()
{
    //qDebug()<<"11"<<endl;
    Huohao *showhuohao = new Huohao();
    showhuohao->show();
}
