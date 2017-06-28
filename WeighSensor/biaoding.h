#ifndef BIAODING_H
#define BIAODING_H

#include <QWidget>

namespace Ui {
class Biaoding;
}

class Biaoding : public QWidget
{
    Q_OBJECT
    
public:
    explicit Biaoding(QWidget *parent = 0);
    ~Biaoding();
    
private:
    Ui::Biaoding *ui;

public slots:
    void returnIndex();//主页
    void returnPage();//返回上一页
};

#endif // BIAODING_H
