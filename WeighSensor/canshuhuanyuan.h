#ifndef CANSHUHUANYUAN_H
#define CANSHUHUANYUAN_H

#include <QWidget>

namespace Ui {
class Canshuhuanyuan;
}

class Canshuhuanyuan : public QWidget
{
    Q_OBJECT
    
public:
    explicit Canshuhuanyuan(QWidget *parent = 0);
    ~Canshuhuanyuan();
    
private:
    Ui::Canshuhuanyuan *ui;

public slots:
    void returnIndex();//主页
    void returnPage();//返回上一页
};

#endif // CANSHUHUANYUAN_H
