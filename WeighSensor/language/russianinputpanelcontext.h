#ifndef RUSSIANINPUTPANELCONTEXT_H
#define RUSSIANINPUTPANELCONTEXT_H

#include <QInputContext>
class RussianInputPanel;

class RussianInputPanelContext: public QInputContext
{
    Q_OBJECT
public:
    explicit RussianInputPanelContext(QObject *parent = 0);
    ~RussianInputPanelContext();

    QString identifierName();
    QString language();

    bool isComposing() const;

    void reset();

    bool filterEvent(const QEvent* event);

signals:

public slots:
    void charSlot(QChar character);
    void intSlot(int key);
private:
        RussianInputPanel *inputpanel;
        void updatePosition();
        //void leftKey();
        void intKey(int Key);
};

#endif // RUSSIANINPUTPANELCONTEXT_H
