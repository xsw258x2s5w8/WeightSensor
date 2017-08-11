#include "maininterfacetemp.h"

MainInterfaceTemp::MainInterfaceTemp()
{
}
int MainInterfaceTemp::getId()
{
    return id;
}
void MainInterfaceTemp::setId(int id)
{
    this->id = id;
}
QString MainInterfaceTemp::getPara()
{
    return para;
}
void MainInterfaceTemp::setPara(QString para)
{
    this->para = para;
}
int MainInterfaceTemp::getSite()
{
    return site;
}
void MainInterfaceTemp::setSite(int site)
{
    this->site = site;
}
QString MainInterfaceTemp::getParaName()
{
    return paraName;
}
void MainInterfaceTemp::setParaName(QString paraName)
{
    this->paraName = paraName;
}
QString MainInterfaceTemp::getOtherName()
{
    return otherName;
}
void MainInterfaceTemp::setOtherName(QString otherName)
{
    this->otherName = otherName;
}
