#include "afterservice.h"

AfterService::AfterService()
{

}
int AfterService::getId()
{
    return id;
}
void AfterService::setId(int id)
{
    this->id = id;
}
QString AfterService::getCompanyName()
{
    return companyName;
}
void AfterService::setCompanyName(QString companyName)
{
    this->companyName = companyName;
}
QString AfterService::getConPerson()
{
    return conPerson;
}
void AfterService::setConPerson(QString conPerson)
{
    this->conPerson = conPerson;
}
QString AfterService::getTel()
{
    return tel;
}
void AfterService::setTel(QString tel)
{
    this->tel = tel;
}
