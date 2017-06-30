#ifndef INDEX_H
#define INDEX_H

#include <QMainWindow>

namespace Ui {
class Index;
}

class Index : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit Index(QWidget *parent = 0);
    ~Index();
    
private:
    Ui::Index *ui;

public slots:
    void showMenuWidget();// 进入菜单界面
    void showQRcode();//进入二维码界面
};

#endif // INDEX_H
