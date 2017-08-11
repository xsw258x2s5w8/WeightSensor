#ifndef MAININTERFACETEMP_H
#define MAININTERFACETEMP_H
#include <QString>
class MainInterfaceTemp
{
public:
    MainInterfaceTemp();
    int getId();
    void setId(int id);
    QString getPara();
    void setPara(QString para);
    int getSite();
    void setSite(int site);
    QString getParaName();
    void setParaName(QString paraName);
    QString getOtherName();
    void setOtherName(QString otherName);
private:
    int id;
    QString para;//字段名称(存在在数据库称重记录中的字段名称)
    int site;//顺序
    QString paraName;//名称(自定义名称)
    QString otherName;//可改名称

};

#endif // MAININTERFACETEMP_H
