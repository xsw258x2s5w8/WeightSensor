#ifndef PAGE2_H
#define PAGE2_H

#include <QWidget>

namespace Ui {
class page2;
}

class page2 : public QWidget
{
    Q_OBJECT
    
public:
    explicit page2(QWidget *parent = 0);
    ~page2();
    
private:
    Ui::page2 *ui;

public slots:
    void returnIndex();
    void showPermission();
};

#endif // PAGE2_H
