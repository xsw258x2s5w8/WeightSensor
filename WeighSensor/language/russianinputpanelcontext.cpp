#include <QPointer>
#include "russianinputpanelcontext.h"
#include "russianinputpanel.h"

RussianInputPanelContext::RussianInputPanelContext(QObject *parent) :
    QInputContext(parent)
{
    inputpanel=new RussianInputPanel(this);
}


QString RussianInputPanelContext::identifierName()
{
    return "RussianInputPannelContext";
}

void RussianInputPanelContext::reset()
{
}

bool RussianInputPanelContext::isComposing() const
{
    return false;
}

QString RussianInputPanelContext::language()
{
    return "en_US";
}



bool RussianInputPanelContext::filterEvent(const QEvent* event)
{
    if (event->type() == QEvent::RequestSoftwareInputPanel) {
        updatePosition();
        inputpanel->show();
        return true;
    } else if (event->type() == QEvent::CloseSoftwareInputPanel) {
        inputpanel->hide();
        return true;
    }
    return false;
}



void RussianInputPanelContext::updatePosition()
{
    QWidget *widget = focusWidget();
    if (!widget)
        return;

    QRect widgetRect = widget->rect();
    QPoint panelPos = QPoint(widgetRect.left(), widgetRect.bottom() + 2);
    panelPos = widget->mapToGlobal(panelPos);
    inputpanel->move(panelPos);


}


void RussianInputPanelContext::charSlot(QChar character)
{
    QPointer<QWidget> w = focusWidget();

    if (!w)
        return;

    QKeyEvent keyPress(QEvent::KeyPress, character.unicode(), Qt::NoModifier, QString(character));
    QApplication::sendEvent(w, &keyPress);

    if (!w)
        return;

    QKeyEvent keyRelease(QEvent::KeyPress, character.unicode(), Qt::NoModifier, QString());
    QApplication::sendEvent(w, &keyRelease);

}

void RussianInputPanelContext::intKey(int Key)
{
    QPointer<QWidget> w = focusWidget();

    if (!w)
        return;

    QKeyEvent keyPress(QEvent::KeyPress, Key, Qt::NoModifier, QString());
    QApplication::sendEvent(w, &keyPress);
}

void RussianInputPanelContext::intSlot(int key)
{
    QPointer<QWidget> w = focusWidget();

    if (!w)
        return;
    switch(key)
    {
    case 35:
        break;
    case 36:
        inputpanel->hide();
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
        intKey(Qt::Key_Backspace);
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
        charSlot(' ');//"space" key
        break;
    default:
        return;
    }
}






RussianInputPanelContext::~RussianInputPanelContext()
{
    delete inputpanel;
}

