#ifndef YICIGUOBANG_H
#define YICIGUOBANG_H

#include <QWidget>

namespace Ui {
class Yiciguobang;
}

class Yiciguobang : public QWidget
{
    Q_OBJECT
    
public:
    explicit Yiciguobang(QWidget *parent = 0);
    ~Yiciguobang();
    
private:
    Ui::Yiciguobang *ui;

public slots:
    void returnIndex();//主页
    void returnPage();//返回上一页
};

#endif // YICIGUOBANG_H
