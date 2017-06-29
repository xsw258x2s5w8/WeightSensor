#ifndef CUNCHUQIJIANCE_H
#define CUNCHUQIJIANCE_H

#include <QWidget>

namespace Ui {
class Cunchuqijiance;
}

class Cunchuqijiance : public QWidget
{
    Q_OBJECT
    
public:
    explicit Cunchuqijiance(QWidget *parent = 0);
    ~Cunchuqijiance();
    
private:
    Ui::Cunchuqijiance *ui;


public slots:
    void returnIndex();//主页
    void returnPage();//返回上一页
};

#endif // CUNCHUQIJIANCE_H
