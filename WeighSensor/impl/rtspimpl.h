#ifndef RTSPIMPL_H
#define RTSPIMPL_H
#include <QtSql>
#include "rtsp.h"
class RTSPimpl
{
public:
    RTSPimpl();

    RTSP selectRtspById(int id);//根据id查询数据
    int updateRtsp(RTSP rtsp);//更新数据
    int insertRtsp(RTSP rtsp);//插入数据
    int deleteRtspById(int id);//根据id删除数据

private:
    QSqlDatabase database;
};

#endif // RTSPIMPL_H
