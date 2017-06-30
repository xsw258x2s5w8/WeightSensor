#ifndef RUANJIANGENGXIN_H
#define RUANJIANGENGXIN_H

#include <QWidget>

namespace Ui {
class Ruanjiangengxin;
}

class Ruanjiangengxin : public QWidget
{
    Q_OBJECT
    
public:
    explicit Ruanjiangengxin(QWidget *parent = 0);
    ~Ruanjiangengxin();
    
private:
    Ui::Ruanjiangengxin *ui;

public slots:
    void returnIndex();//主页
    void returnPage();//返回上一页
};

#endif // RUANJIANGENGXIN_H
