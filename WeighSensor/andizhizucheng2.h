#ifndef ANDIZHIZUCHENG2_H
#define ANDIZHIZUCHENG2_H

#include <QWidget>

namespace Ui {
class Andizhizucheng2;
}

class Andizhizucheng2 : public QWidget
{
    Q_OBJECT
    
public:
    explicit Andizhizucheng2(QWidget *parent = 0);
    ~Andizhizucheng2();
    
private:
    Ui::Andizhizucheng2 *ui;

public slots:
    void returnIndex();//主页
    void returnPage();//返回上一页
};

#endif // ANDIZHIZUCHENG2_H
