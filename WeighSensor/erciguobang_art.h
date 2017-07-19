#ifndef ERCIGUOBANG_ART_H
#define ERCIGUOBANG_ART_H

#include <QWidget>
#include <QSignalMapper>

class Erciguobang_art : public QWidget
{
    Q_OBJECT
public:
    explicit Erciguobang_art(QWidget *parent = 0);

    
    //槽函数
private slots:
        //处理最终信号的槽
    void doClicked(const QString & btnname);

signals:
    void sendArtid(QString data);

private:
    QSignalMapper *signalMapper;
    
};

#endif // ERCIGUOBANG_ART_H
