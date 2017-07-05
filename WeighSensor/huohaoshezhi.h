#ifndef HUOHAOSHEZHI_H
#define HUOHAOSHEZHI_H

#include <QDialog>

namespace Ui {
class Huohaoshezhi;
}

class Huohaoshezhi : public QDialog
{
    Q_OBJECT
    
public:
    explicit Huohaoshezhi(QWidget *parent = 0);
    ~Huohaoshezhi();
    
private:
    Ui::Huohaoshezhi *ui;
};

#endif // HUOHAOSHEZHI_H
