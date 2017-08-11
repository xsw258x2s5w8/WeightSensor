#ifndef RUSSIANINPUTPANEL_H
#define RUSSIANINPUTPANEL_H


#include <QWidget>
#include <QList>
#include <QChar>
#include <QString>
#include <QPoint>
#include "ui_russianinputpanelform.h"

class RussianInputPanelContext;
class QDomDocument;
namespace Ui {
    class RussianInputPanelForm;
}

class RussianInputPanel : public QWidget
{
    Q_OBJECT
public:
    explicit RussianInputPanel(RussianInputPanelContext *ipc,QWidget *parent=0 );
    void numPro();
    void capsPro();
signals:
    void sendChar(QChar ch);
    void sendInt(int key);

protected:
    bool event(QEvent *e);

private slots:
    void saveFocusWidget(QWidget *oldFocus, QWidget *newFocus);
    void btnClicked(QWidget *w);
private:
    Ui::RussianInputPanelForm *inputform;
    QList<QPushButton *> btns;
    int btns_sz;
    QDomDocument *doc;
    int caps;
    int num;
    int xml_accu;
    QWidget *lastFocusedWidget;

    bool should_move;
    QPoint  mouse_pos;
    QPoint  widget_pos;

    void loadDoc();
    void num_caps();
    QString getKeyBoardAttr();
    void setKBcharacter();
    void myMapping();
    void mousePressEvent(QEvent *e);
    void mouseReleaseEvent(QEvent *e);
    void mouseMoveEvent(QEvent *e);

};

#endif // RUSSIANINPUTPANEL_H
