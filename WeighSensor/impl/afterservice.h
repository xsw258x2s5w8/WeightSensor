#ifndef AFTERSERVICE_H
#define AFTERSERVICE_H
#include <QString>
class AfterService
{
public:
    AfterService();
    int getId();
    void setId(int id);
    QString getCompanyName();
    void setCompanyName(QString companyName);
    QString getConPerson();
    void setConPerson(QString conPerson);
    QString getTel();
    void setTel(QString tel);
private:
    int id;//id
    QString companyName;//公司名字
    QString conPerson;//联系人
    QString tel;//联系电话
};

#endif // AFTERSERVICE_H
