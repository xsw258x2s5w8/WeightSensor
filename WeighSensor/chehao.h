#ifndef CHEHAO_H
#define CHEHAO_H

#include <QDialog>

namespace Ui {
class Chehao;
}

class Chehao : public QDialog
{
    Q_OBJECT
    
public:
    explicit Chehao(QWidget *parent = 0);
    ~Chehao();
    
private:
    Ui::Chehao *ui;
};

#endif // CHEHAO_H
