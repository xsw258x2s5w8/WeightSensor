#ifndef IPCONFIGIMPL_H
#define IPCONFIGIMPL_H
#include <QtSql>
#include "ipconfig.h"
class IpConfigImpl
{
public:
    IpConfigImpl();
    int isExistIp();//判断表中是否存有ip数据
    int insertIpConfig(IpConfig ipconfig);//把数据插入ip设置表中
    IpConfig selectIpConfig();//查找表中的数据
    int deleteIpConfig();//删除表中的数据
private:
    QSqlDatabase database;

};

#endif // IPCONFIGIMPL_H
