#ifndef SHIBOQI_H
#define SHIBOQI_H

#include <QWidget>

namespace Ui {
class Shiboqi;
}

class Shiboqi : public QWidget
{
    Q_OBJECT
    
public:
    explicit Shiboqi(QWidget *parent = 0);
    ~Shiboqi();
    
private:
    Ui::Shiboqi *ui;

public slots:
    void returnIndex();//主页
    void returnPage();//返回上一页
};

#endif // SHIBOQI_H
