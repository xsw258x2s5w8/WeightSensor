/*this class defines the panel used to input Chinese via Pingyin*/
#include "clicklabel.h"
#include <QWidget>
#include <QLineEdit>
#include <QToolButton>

class ChnPanel:public QWidget
{
    Q_OBJECT
public:
    ChnPanel();
    ~ChnPanel();
    QLineEdit *chnLineEdit;
    ClickLabel *chnLabel[5];
    QToolButton *btnLeft;
    QToolButton *btnRight;
private:

    bool should_move;
    QPoint  mouse_pos;
    QPoint  widget_pos;

    void mousePressEvent(QEvent *e);
    void mouseReleaseEvent(QEvent *e);
    void mouseMoveEvent(QEvent *e);

    void closeEvent(QCloseEvent *event);//关闭事件
};
