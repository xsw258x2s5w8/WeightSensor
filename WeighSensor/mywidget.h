#ifndef MYWIDGET_H
#define MYWIDGET_H
#include<QWidget>

class myWidget:public QWidget
{
    Q_OBJECT
public:
    explicit myWidget(QWidget *parent = 0);

private:
    virtual void mousePressEvent(QMouseEvent *ev);
    void paintEvent(QPaintEvent *);
signals:
    void clicked();
//public slots:
//    void showVideo();
};

#endif // MYWIDGET_H
