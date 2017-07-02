#ifndef BAOBIAODAYIN_H
#define BAOBIAODAYIN_H

#include <QWidget>

namespace Ui {
class Baobiaodayin;
}

class Baobiaodayin : public QWidget
{
    Q_OBJECT
    
public:
    explicit Baobiaodayin(QWidget *parent = 0);
    ~Baobiaodayin();
    
private:
    Ui::Baobiaodayin *ui;

public slots:
    void returnIndex();//主页
    void returnPage();//返回上一页
};

#endif // BAOBIAODAYIN_H
