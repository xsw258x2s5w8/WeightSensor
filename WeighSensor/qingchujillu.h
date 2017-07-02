#ifndef QINGCHUJILLU_H
#define QINGCHUJILLU_H

#include <QWidget>

namespace Ui {
class Qingchujillu;
}

class Qingchujillu : public QWidget
{
    Q_OBJECT
    
public:
    explicit Qingchujillu(QWidget *parent = 0);
    ~Qingchujillu();
    
private:
    Ui::Qingchujillu *ui;

public slots:
    void returnIndex();//主页
    void returnPage();//返回上一页
};

#endif // QINGCHUJILLU_H
