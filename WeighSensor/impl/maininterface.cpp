#include "maininterface.h"

MainInterface::MainInterface()
{
}

int MainInterface::getMainId()
{
    return mainId;
}
void MainInterface::setMainId(int mainId)
{
    this->mainId = mainId;
}
QString MainInterface::getParaName()
{
    return paraName;
}
void MainInterface::setParaName(QString paraName)
{
    this->paraName=paraName;
}
int MainInterface::getIsSelected()
{
    return isSelected;
}
void MainInterface::setIsSelected(int isSelected)
{
    this->isSelected=isSelected;
}
int MainInterface::getIsMust()
{
    return isMust;
}
void MainInterface::setIsMust(int isMust)
{
    this->isMust=isMust;
}
int MainInterface::getSite()
{
    return site;
}
void MainInterface::setSite(int site)
{
    this->site=site;
}
QString MainInterface::getPara()
{
    return para;
}
void MainInterface::setPara(QString para)
{
    this->para=para;
}
QString MainInterface::getOtherName()
{
    return otherName;
}
void MainInterface::setOtherName(QString otherName)
{
    this->otherName=otherName;
}
