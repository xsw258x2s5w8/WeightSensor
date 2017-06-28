#ifndef SHURUZHONGLIANG_H
#define SHURUZHONGLIANG_H

#include <QWidget>

namespace Ui {
class Shuruzhongliang;
}

class Shuruzhongliang : public QWidget
{
    Q_OBJECT
    
public:
    explicit Shuruzhongliang(QWidget *parent = 0);
    ~Shuruzhongliang();
    
private:
    Ui::Shuruzhongliang *ui;

public slots:
    void returnIndex();//主页
    void returnPage();//返回上一页
};

#endif // SHURUZHONGLIANG_H
