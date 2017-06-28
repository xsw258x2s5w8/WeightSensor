#ifndef YAJIAOQUEREN_H
#define YAJIAOQUEREN_H

#include <QWidget>

namespace Ui {
class Yajiaoqueren;
}

class Yajiaoqueren : public QWidget
{
    Q_OBJECT
    
public:
    explicit Yajiaoqueren(QWidget *parent = 0);
    ~Yajiaoqueren();
    
private:
    Ui::Yajiaoqueren *ui;

public slots:
    void returnIndex();//主页
    void returnPage();//返回上一页
};

#endif // YAJIAOQUEREN_H
