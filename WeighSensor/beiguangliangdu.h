#ifndef BEIGUANGLIANGDU_H
#define BEIGUANGLIANGDU_H

#include <QWidget>

namespace Ui {
class Beiguangliangdu;
}

class Beiguangliangdu : public QWidget
{
    Q_OBJECT
    
public:
    explicit Beiguangliangdu(QWidget *parent = 0);
    ~Beiguangliangdu();
    
private:
    Ui::Beiguangliangdu *ui;

public slots:
    void returnIndex();//主页
    void returnPage();//返回上一页
};

#endif // BEIGUANGLIANGDU_H
