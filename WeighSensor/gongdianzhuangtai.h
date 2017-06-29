#ifndef GONGDIANZHUANGTAI_H
#define GONGDIANZHUANGTAI_H

#include <QWidget>

namespace Ui {
class Gongdianzhuangtai;
}

class Gongdianzhuangtai : public QWidget
{
    Q_OBJECT
    
public:
    explicit Gongdianzhuangtai(QWidget *parent = 0);
    ~Gongdianzhuangtai();
    
private:
    Ui::Gongdianzhuangtai *ui;

public slots:
    void returnIndex();//主页
    void returnPage();//返回上一页
};

#endif // GONGDIANZHUANGTAI_H
