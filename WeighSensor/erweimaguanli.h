#ifndef ERWEIMAGUANLI_H
#define ERWEIMAGUANLI_H

#include <QWidget>

namespace Ui {
class Erweimaguanli;
}

class Erweimaguanli : public QWidget
{
    Q_OBJECT
    
public:
    explicit Erweimaguanli(QWidget *parent = 0);
    ~Erweimaguanli();
    
private:
    Ui::Erweimaguanli *ui;
public slots:
    void returnIndex();//主页
    void returnPage();//返回上一页
};

#endif // ERWEIMAGUANLI_H
