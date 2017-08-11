#ifndef MYDELEGATE_H
#define MYDELEGATE_H
#include <QItemDelegate>

class MyDelegate:public QItemDelegate
{
public:
    MyDelegate(QObject * parent=0);
    virtual ~ MyDelegate(){}

    QRect CheckBoxRect(const QStyleOptionViewItem &viewItemStyleOptions)const;
    QRect PushButtonRect(const QStyleOptionViewItem &viewItemStyleOptions)const;
    QRect PushButtonRect1(const QStyleOptionViewItem &viewItemStyleOptions)const;
    void paint(QPainter * painter,
            const QStyleOptionViewItem & option,
            const QModelIndex & index) const;

    bool editorEvent(QEvent * event,
           QAbstractItemModel * model,
           const QStyleOptionViewItem & option,
           const QModelIndex & index);

private:


};

#endif // MYDELEGATE_H
