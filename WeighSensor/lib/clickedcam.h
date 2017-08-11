#ifndef CLICKEDCAM_H
#define CLICKEDCAM_H

#include <QPushButton>

class ClickedCam : public QPushButton
{
    Q_OBJECT
public:
    explicit ClickedCam(QWidget *parent = 0);
    
public:signals:
    void clicked(QString name);

private slots:
    void getname();
};

#endif // CLICKEDCAM_H
