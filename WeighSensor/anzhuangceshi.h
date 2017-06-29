#ifndef ANZHUANGCESHI_H
#define ANZHUANGCESHI_H

#include <QWidget>

namespace Ui {
class Anzhuangceshi;
}

class Anzhuangceshi : public QWidget
{
    Q_OBJECT
    
public:
    explicit Anzhuangceshi(QWidget *parent = 0);
    ~Anzhuangceshi();
    
private:
    Ui::Anzhuangceshi *ui;
};

#endif // ANZHUANGCESHI_H
