#ifndef CHAIZAI_H
#define CHAIZAI_H

#include <QWidget>

namespace Ui {
class Chaizai;
}

class Chaizai : public QWidget
{
    Q_OBJECT
    
public:
    explicit Chaizai(QWidget *parent = 0);
    ~Chaizai();
    
private:
    Ui::Chaizai *ui;

public slots:
    void returnIndex();//主页
    void returnPage();//返回上一页
};

#endif // CHAIZAI_H
