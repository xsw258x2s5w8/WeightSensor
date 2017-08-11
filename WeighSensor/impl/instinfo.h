#ifndef INSTINFO_H
#define INSTINFO_H
#include <QString>
class InstInfo
{
public:
    InstInfo();
    int getId();
    void setId(int id);
    QString getVersion();
    void setVersion(QString version);
    QString getMicrType();
    void setMicrType(QString micrType);
    QString getInsId();
    void setInsId(QString insId);
    QString getCustInfo();
    void setCustInfo(QString custInfo);


private:
    int id;//id
    QString version;//版本号
    QString micrType;//微打类型
    QString insId;//仪表ID
    QString custInfo;//定制信息

};

#endif // INSTINFO_H
