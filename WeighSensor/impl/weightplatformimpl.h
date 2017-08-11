#ifndef WEIGHTPLATFORMIMPL_H
#define WEIGHTPLATFORMIMPL_H
#include <QtSql>
#include "weightplatform.h"
class WeightPlatformImpl
{
public:
    WeightPlatformImpl();
    WeightPlatform selectWeightPlatform();//读取秤台参数设置表内数据
    int insertWeightPlatform(WeightPlatform weightPlatform);//往秤台参数设置表内插入数据
    int deleteWeightPlatform();//删除秤台参数设置表内的全部数据

private:
    QSqlDatabase database;
};

#endif // WEIGHTPLATFORMIMPL_H
