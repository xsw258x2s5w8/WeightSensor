#ifndef YAZHOUQUEREN_H
#define YAZHOUQUEREN_H

#include <QWidget>

namespace Ui {
class Yazhouqueren;
}

class Yazhouqueren : public QWidget
{
    Q_OBJECT
    
public:
    explicit Yazhouqueren(QWidget *parent = 0);
    ~Yazhouqueren();
    
private:
    Ui::Yazhouqueren *ui;

public slots:
    void returnIndex();//主页
    void returnPage();//返回上一页
};

#endif // YAZHOUQUEREN_H
