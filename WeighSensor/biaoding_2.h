#ifndef BIAODING_2_H
#define BIAODING_2_H

#include <QWidget>

namespace Ui {
class Biaoding_2;
}

class Biaoding_2 : public QWidget
{
    Q_OBJECT
    
public:
    explicit Biaoding_2(QWidget *parent = 0);
    ~Biaoding_2();
    
private:
    Ui::Biaoding_2 *ui;

public slots:
    void returnIndex();//主页
    void returnPage();//返回上一页
};

#endif // BIAODING_2_H
