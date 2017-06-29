#ifndef CAISHUBEIFEN_H
#define CAISHUBEIFEN_H

#include <QWidget>

namespace Ui {
class Caishubeifen;
}

class Caishubeifen : public QWidget
{
    Q_OBJECT
    
public:
    explicit Caishubeifen(QWidget *parent = 0);
    ~Caishubeifen();
    
private:
    Ui::Caishubeifen *ui;

public slots:
    void returnIndex();//主页
    void returnPage();//返回上一页
};

#endif // CAISHUBEIFEN_H
