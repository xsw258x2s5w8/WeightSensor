#include "chnpanel.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QMouseEvent>
#include <QDebug>
ChnPanel::ChnPanel():QWidget(0,Qt::Tool)

{
    chnLineEdit=new QLineEdit();
    chnLineEdit->setFocusPolicy(Qt::NoFocus);
    chnLineEdit->setFont(QFont("wenquanyi",10,QFont::Bold));
    chnLineEdit->setObjectName(QString::fromUtf8("CHN"));
    chnLineEdit->setReadOnly(true);
    //
    int i;
    for(i=0;i<5;i++)
    {
        chnLabel[i]=new ClickLabel("",0);
        chnLabel[i]->setFont(QFont("wenquanyi",10,QFont::Bold));
        chnLabel[i]->setObjectName(QString::fromUtf8("CHN"));
    }
    //
    btnLeft=new QToolButton();
    btnLeft->setFont(QFont("wenquanyi",10,QFont::Bold));
    btnLeft->setText(tr("<"));
    btnLeft->setObjectName(QString::fromUtf8("CHN"));
    //  btnLeft->setFixedSize(20,20);
    //
    btnRight=new QToolButton();
    btnRight->setFont(QFont("wenquanyi",10,QFont::Bold));
    btnRight->setText(tr(">"));
    btnRight->setObjectName(QString::fromUtf8("CHN"));
   // btnRight->setFixedSize(20,20);
    //
    QHBoxLayout *layoutLabel=new QHBoxLayout();
    layoutLabel->addWidget(btnLeft);
    for(i=0;i<5;i++)
    {
        layoutLabel->addWidget(chnLabel[i]);
    }
    layoutLabel->addWidget(btnRight);
    //
    QVBoxLayout *layout=new QVBoxLayout();
    layout->addWidget(chnLineEdit);
    layout->addLayout(layoutLabel);
    setLayout(layout);

    setWindowTitle("DQ输入法");//设置标题
    //
    //setFixedSize(800,60);
    //setStyleSheet(QString::fromUtf8("border:1px solid black"));
    //setWindowFlags(windowFlags()|Qt::WindowCloseButtonHint);
    setVisible(false);
}

ChnPanel::~ChnPanel()
{
}



//移动模块
void ChnPanel::mousePressEvent (QEvent *e)
{
    QMouseEvent *event=static_cast<QMouseEvent *>(e);
    if (event->button()!=Qt::LeftButton) return;
    this->should_move = true;
    this->widget_pos = this->pos();
    this->mouse_pos = event->globalPos();

}
void ChnPanel::mouseReleaseEvent(QEvent *e)
{
    QMouseEvent *event=static_cast<QMouseEvent *>(e);
    if (event->button()!=Qt::LeftButton) return;
    this->should_move = false;

}
void ChnPanel::mouseMoveEvent ( QEvent *e)
{
    QMouseEvent *event=static_cast<QMouseEvent *>(e);
    if (this->should_move)
    {
        QPoint pos = event->globalPos();
        int x = pos.x()-this->mouse_pos.x();
        QString x1 = QString::number(x, 10);
        int y = pos.y()-this->mouse_pos.y();
        QString y1 = QString::number(y, 10);
        qDebug()<<"x="<<x1;
        qDebug()<<"y="<<y1;

        QWidget::move(this->widget_pos.x()+x,this->widget_pos.y()+y);
    }

}

void ChnPanel::closeEvent(QCloseEvent *event)//此函数在QWidget关闭时执行
{

     event->ignore();

}
