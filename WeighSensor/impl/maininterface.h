#ifndef MAININTERFACE_H
#define MAININTERFACE_H
#include <QString>
class MainInterface
{
public:
    MainInterface();
    int getMainId();
    void setMainId(int mainId);
    QString getParaName();
    void setParaName(QString paraName);
    int getIsSelected();
    void setIsSelected(int isSelected);
    int getIsMust();
    void setIsMust(int isMust);
    int getSite();
    void setSite(int site);
    QString getPara();
    void setPara(QString para);
    QString getOtherName();
    void setOtherName(QString otherName);


private:
    int mainId;//主界面id
    QString paraName;//参数名字
    int isSelected;//是否被选中
    int isMust;//是否必须
    int site;//次序
    QString para;//表中的字段名
    QString otherName;//可改名称

};

#endif // MAININTERFACE_H
