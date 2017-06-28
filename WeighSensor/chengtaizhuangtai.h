#ifndef CHENGTAIZHUANGTAI_H
#define CHENGTAIZHUANGTAI_H

#include <QWidget>

namespace Ui {
class Chengtaizhuangtai;
}

class Chengtaizhuangtai : public QWidget
{
    Q_OBJECT
    
public:
    explicit Chengtaizhuangtai(QWidget *parent = 0);
    ~Chengtaizhuangtai();
    
private:
    Ui::Chengtaizhuangtai *ui;

public slots:
    void returnIndex();//主页
    void returnPage();//返回上一页
};

#endif // CHENGTAIZHUANGTAI_H
