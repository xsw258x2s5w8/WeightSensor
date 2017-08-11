#include "clickedcam.h"

ClickedCam::ClickedCam(QWidget *parent) :
    QPushButton(parent)
{
    connect(this,SIGNAL(clicked()),this,SLOT(getname()));
}

void ClickedCam::getname()
{
   emit clicked(this->objectName());
}
