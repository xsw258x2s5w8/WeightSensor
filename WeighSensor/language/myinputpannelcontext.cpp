#include <QPointer>


#include "myinputpannelcontext.h"
#include "myinputpanel.h"
#include <QDebug>
#include <QMessageBox>
MyInputPannelContext::MyInputPannelContext(QObject *parent) :
    QInputContext(parent)
{
    inputpanel=new MyInputPanel(this);

}


QString MyInputPannelContext::identifierName()
{
    return "MyInputPannelContext";
}

void MyInputPannelContext::reset()
{
}

bool MyInputPannelContext::isComposing() const
{
    return false;
}

QString MyInputPannelContext::language()
{
    return "en_US";
}



bool MyInputPannelContext::filterEvent(const QEvent* event)
{
    if (event->type() == QEvent::RequestSoftwareInputPanel) {
        updatePosition();
        inputpanel->show();
        if(!inputpanel->db.open())
        {
            QMessageBox::information(0,tr("无法打开数据库"),tr("需要SQLITE数据库的支持"));
        }
        else
        {
            qDebug()<<"数据库打开成功";
        }

        return true;
    } else if (event->type() == QEvent::CloseSoftwareInputPanel) {
        inputpanel->close();
        inputpanel->db.close();
        inputpanel->chnpanel->chnLineEdit->clear();
        inputpanel->chnpanel->close();
        qDebug()<<"数据库关闭";
        return true;
    }
    return false;
}



void MyInputPannelContext::updatePosition()
{
    QPointer<QWidget> w = inputpanel->getFocusedWidget();
    if (!w)
        return;

    QRect widgetRect = w->rect();
    QPoint panelPos = QPoint(widgetRect.left(), widgetRect.bottom() + 2);
    panelPos = w->mapToGlobal(panelPos);
    inputpanel->move(panelPos);


}


void MyInputPannelContext::charSlot(QString character)
{


    qDebug()<<character;
    QPointer<QWidget> w = inputpanel->getFocusedWidget();

    if (!w)
        return;

    QKeyEvent keyPress(QEvent::KeyPress, (character.unicode())->unicode(), Qt::NoModifier, QString(character));
    QApplication::sendEvent(w, &keyPress);

    if (!w)
        return;

    QKeyEvent keyRelease(QEvent::KeyPress, (character.unicode())->unicode(), Qt::NoModifier, QString());
    QApplication::sendEvent(w, &keyRelease);

}

void MyInputPannelContext::intKey(int Key)
{
    QPointer<QWidget> w = inputpanel->getFocusedWidget();

    if (!w)
        return;

    QKeyEvent keyPress(QEvent::KeyPress, Key, Qt::NoModifier, QString());
    QApplication::sendEvent(w, &keyPress);
}

void MyInputPannelContext::intSlot(int key)
{
    QPointer<QWidget> w = inputpanel->getFocusedWidget();

    if (!w)
        return;
    switch(key)
    {
    case 35:
        break;
    case 36:
        //点击关闭时
        inputpanel->close();
        inputpanel->chnpanel->chnLineEdit->clear();
        inputpanel->chnpanel->close();
        inputpanel->db.close();
        qDebug()<<"数据库关闭！！！";

        break;
    case 50:
        intKey(Qt::Key_Up);
        break;
    case 51:
        intKey(Qt::Key_Left);
        break;
    case 52:
        intKey(Qt::Key_Right);
        break;
    case 53:
        intKey(Qt::Key_Down);
        break;
    case 54:
        intKey(Qt::Key_Backspace);//删除按键
        break;
    case 55:
        intKey(Qt::Key_Enter);
        break;
    case 56:
        inputpanel->capsPro();//"caps" key
        break;
    case 57:
        inputpanel->numPro();//"num" key
        break;
    case 58:
        charSlot(" ");//"space" key
        break;
    default:
        return;
    }
}






MyInputPannelContext::~MyInputPannelContext()
{
    delete inputpanel;
}




