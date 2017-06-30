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
    void showGenerateQR();//进入生成二维码界面
    void showFindQR();//进入查询二维码界面
};

#endif // ERWEIMAGUANLI_H
