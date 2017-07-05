#ifndef HUOHAO_H
#define HUOHAO_H

#include <QWidget>

namespace Ui {
class Huohao;
}

class Huohao : public QWidget
{
    Q_OBJECT
    
public:
    explicit Huohao(QWidget *parent = 0);
    ~Huohao();
    
private:
    Ui::Huohao *ui;

public slots:
    void showhuohaoshezhi();
};

#endif // HUOHAO_H
