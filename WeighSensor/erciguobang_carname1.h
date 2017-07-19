#ifndef ERCIGUOBANG_CARNAME1_H
#define ERCIGUOBANG_CARNAME1_H

#include <QWidget>
#include <QSignalMapper>

class Erciguobang_carName1 : public QWidget
{
    Q_OBJECT
public:
    explicit Erciguobang_carName1(QWidget *parent = 0);
    
    //槽函数
private slots:
        //处理最终信号的槽
    void doClicked(const QString & btnname);

signals:
    void sendCarName1(QString data);

private:
    QSignalMapper *signalMapper;
    
};

#endif // ERCIGUOBANG_CARNAME1_H
