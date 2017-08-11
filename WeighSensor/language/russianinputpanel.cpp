#include <QtXml/QDomDocument>
#include <QtXml/QDomElement>//It's the case you have to pay attention
#include <QDebug>
#include <QSignalMapper>
#include <QFile>
#include <QMouseEvent>
#include "russianinputpanel.h"
#include "russianinputpanelcontext.h"
RussianInputPanel::RussianInputPanel(RussianInputPanelContext *ipc,QWidget *parent)
    :QWidget(parent, Qt::FramelessWindowHint|Qt::WindowStaysOnTopHint|Qt::Tool),
    //: QWidget(parent, Qt::Tool | Qt::WindowStaysOnTopHint),
      lastFocusedWidget(0)
{
        inputform=new Ui::RussianInputPanelForm;
        inputform->setupUi(this);
        btns=findChildren<QPushButton *>();
        btns_sz=btns.size();
        qDebug()<<btns_sz;
        xml_accu=0;
        loadDoc();
        num_caps();
        setKBcharacter();

        connect(qApp, SIGNAL(focusChanged(QWidget*,QWidget*)),
                this, SLOT(saveFocusWidget(QWidget*,QWidget*)));
        myMapping();
        connect(this,SIGNAL(sendChar(QChar)),ipc,SLOT(charSlot(QChar)));
        connect(this,SIGNAL(sendInt(int)),ipc,SLOT(intSlot(int)));

        should_move=false;
}

void RussianInputPanel::loadDoc()
{
    doc=new QDomDocument("keydoc");
    QFile file(":/russiankeyboard.xml");
    if(!file.open(QIODevice::ReadOnly))
    {
        qDebug()<<"xml file does not exist";
        return;
    }

    bool namespaceProcessing=false;
    QString *errorMsg = new QString();

    int errorLine=0;
    int errorColumn=0;

    QTextStream stream(&file);
    if(!doc->setContent(stream.readAll(),namespaceProcessing,errorMsg,&errorLine,&errorColumn))
    {
        qDebug()<<"can not set content";
        qDebug()<<"namespaceProcessing"<<namespaceProcessing;
        qDebug()<<"errormsg"<<errorMsg->toAscii();
        qDebug()<<"errorLine"<<errorLine;
        qDebug()<<"errorColomn"<<errorColumn;
        return;
    }
}

//--------------get num and caps keys' state--------------
void RussianInputPanel::num_caps()
{
    bool OK;
    int caps_tmp,num_tmp;

    //---------------get keys' nr in XML----------------------------
    for(QDomNode n=doc->documentElement().firstChild();(!n.isNull());n=n.nextSibling())
    {
        xml_accu+=1;
        if(n.toElement().attribute("text").contains("CAPS"))
        {
            caps_tmp=n.toElement().attribute("nr").toInt(&OK);
            continue;
        }

        if(n.toElement().attribute("text").contains("NUM"))
        {
            num_tmp=n.toElement().attribute("nr").toInt(&OK);
            continue;
        }

    }


    for(int i=0;i<btns_sz;i++)
    {
        if(btns[i]->objectName().remove("pushButton_").toInt(&OK)==caps_tmp)
        {
            btns[i]->setCheckable(true);
            btns[i]->setChecked(false);
            caps=i;
            continue;

        }

        if(btns[i]->objectName().remove("pushButton_").toInt(&OK)==num_tmp)
        {
            btns[i]->setCheckable(true);
            btns[i]->setChecked(false);
            num=i;
            continue;
        }

    }

}

QString RussianInputPanel::getKeyBoardAttr()
{
    QString str;
    if(btns[caps]->isChecked())
    {
        str="caps";
    }
    else if(btns[num]->isChecked())
    {
        str="num";
    }
    else
    {
        str="text";
    }
    return str;

}


void RussianInputPanel::setKBcharacter()
{
    QDomElement root;
    bool OK;
    QFont font("",5);
    QString str = getKeyBoardAttr();//得到当前键盘类型（小写、大写还是数字键盘）
    //qDebug()<<"getKeyBoardAttr:"<<getKeyBoardAttr().toAscii();//test
    root = doc->documentElement();
    for(int i=0;i<btns_sz;i++)
    {
         for(QDomNode n=root.firstChild();(!n.isNull());n=n.nextSibling())
        {
             int button=btns[i]->objectName().remove("pushButton_").toInt(&OK);//按钮编号
             //qDebug()<<"已经定义好的按键编号：";
             //qDebug()<<button;
             int xml = n.toElement().attribute("nr").toInt(&OK);//nr值
             if(button==xml)
             {
                 if(button==19)//'&'key display
                 {
                     if(str=="num")
                     {
                        btns[i]->setIconSize(btns[i]->size()*0.8);//--------------adjust
                        btns[i]->setIcon(QIcon(":/image/&.png"));
                        btns[i]->setText(n.toElement().attribute(str));
                        break;
                     }
                     else
                     {
                        btns[i]->setIcon(QIcon(""));
                        btns[i]->setText(n.toElement().attribute(str));
                        break;
                     }
                 }
                 else if(button<50)
                 {
                     btns[i]->setText(n.toElement().attribute(str));
                     //qDebug()<<"btns[i]->text()"<<btns[i]->text().toAscii();
                     //root.removeChild(n);
                     break;
                 }
                 else
                 {
                     switch(button)
                    {
                     case 50:
                         btns[i]->setIconSize(btns[i]->size());
                         //btns[i]->setIcon(QIcon(":/image/up.ico"));
                         btns[i]->setIcon(QIcon(":/img/up.png"));
                         btns[i]->setText("");
                         break;
                     case 51:
                         btns[i]->setIconSize(btns[i]->size());
                         //btns[i]->setIcon(QIcon(":/image/left.ico"));
                         btns[i]->setIcon(QIcon(":/img/left.png"));
                         btns[i]->setText("");
                         break;
                     case 52:
                         btns[i]->setIconSize(btns[i]->size());
                         //btns[i]->setIcon(QIcon(":/image/right.ico"));
                         btns[i]->setIcon(QIcon(":/img/right.png"));
                         btns[i]->setText("");
                         break;
                     case 53:
                         btns[i]->setIconSize(btns[i]->size());
                         //btns[i]->setIcon(QIcon(":/image/down.ico"));
                         btns[i]->setIcon(QIcon(":/img/down.png"));
                         btns[i]->setText("");
                         break;
                     case 54:
                     case 55:
                     case 56:
                     case 57:
                     case 58:
                         //QFont font("",5);
                         btns[i]->setFont(font);
                         btns[i]->setText(n.toElement().attribute("text"));
                         break;
                     default:
                         btns[i]->setText("test");

                     }

                 }

             }
        }
    }
}


void RussianInputPanel::saveFocusWidget(QWidget *oldFocus, QWidget *newFocus)
{
    if (newFocus != 0 && !this->isAncestorOf(newFocus)) {
        lastFocusedWidget = newFocus;
       // qDebug()<<"lastFocusedWidget->objectName()"<<lastFocusedWidget->objectName();
    }
}

bool RussianInputPanel::event(QEvent *e)
{
    switch (e->type()) {
    case QEvent::WindowActivate:
        if (lastFocusedWidget)
            lastFocusedWidget->activateWindow();
        break;
    case QEvent::MouseButtonPress:
        mousePressEvent(e);
        break;
    case QEvent::MouseButtonRelease:
        mouseReleaseEvent(e);
        break;
    case QEvent::MouseMove:
        mouseMoveEvent(e);
        break;
    default:
        break;
    }
    return QWidget::event(e);
}


void RussianInputPanel::myMapping()
{
    QSignalMapper *myMapper=new QSignalMapper(this);
    for(int i=0;i<btns.size();i++)
    {
        myMapper->setMapping(btns[i],btns[i]);
        connect(btns[i],SIGNAL(clicked()),myMapper,SLOT(map()));
    }
    connect(myMapper,SIGNAL(mapped(QWidget*)),this,SLOT(btnClicked(QWidget*)));

}

void RussianInputPanel::btnClicked(QWidget *w)
{
     QPushButton *btnp=static_cast<QPushButton *>(w);
     int btn;
     bool OK;
     btn=btnp->objectName().remove("pushButton_").toInt(&OK);
     if(btn<43&&btn!=36)
     {
         QChar ch=btnp->text().at(0);
         //qDebug()<<"ch"<<ch;
         emit sendChar(ch);
     }
     else
     {
            emit sendInt(btn);
     }
}

void RussianInputPanel::capsPro()
{
    if(btns[caps]->isChecked())
    {
        btns[num]->setChecked(false);
    }
    setKBcharacter();
    update();
}




void RussianInputPanel::numPro()
{
    if(btns[num]->isChecked())
    {
        btns[caps]->setChecked(false);
    }
    setKBcharacter();
    update();
}




void RussianInputPanel::mousePressEvent (QEvent *e)
{
    QMouseEvent *event=static_cast<QMouseEvent *>(e);
    if (event->button()!=Qt::LeftButton) return;
    this->should_move = true;
    this->widget_pos = this->pos();
    this->mouse_pos = event->globalPos();

}
void RussianInputPanel::mouseReleaseEvent(QEvent *e)
{
    QMouseEvent *event=static_cast<QMouseEvent *>(e);
    if (event->button()!=Qt::LeftButton) return;
    this->should_move = false;

}
void RussianInputPanel::mouseMoveEvent ( QEvent *e)
{
    QMouseEvent *event=static_cast<QMouseEvent *>(e);
    if (this->should_move)
    {
        QPoint pos = event->globalPos();
        int x = pos.x()-this->mouse_pos.x();
        int y = pos.y()-this->mouse_pos.y();
        QWidget::move(this->widget_pos.x()+x,this->widget_pos.y()+y);
    }

}
