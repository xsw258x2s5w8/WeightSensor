#ifndef PAGE3_H
#define PAGE3_H

#include <QWidget>

namespace Ui {
class Page3;
}

class Page3 : public QWidget
{
    Q_OBJECT
    
public:
    explicit Page3(QWidget *parent = 0);
    ~Page3();
    
private:
    Ui::Page3 *ui;

public slots:
    void returnIndex();//主页
    void returnPage();//返回上一页
    void showPreview();//返回菜单上一页
};

#endif // PAGE3_H
