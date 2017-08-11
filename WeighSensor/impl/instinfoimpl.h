#ifndef INSTINFOIMPL_H
#define INSTINFOIMPL_H
#include <QtSql>
#include "instinfo.h"
class InstInfoImpl
{
public:
    InstInfoImpl();
    int deleteInstInfo();//删除数据信息
    InstInfo selectInstInfo();//查询表内信息
    int insertInstInfo(InstInfo instInfo);//插入信息
private:
     QSqlDatabase database;
};

#endif // INSTINFOIMPL_H
