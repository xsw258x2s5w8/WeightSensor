#include "rtsp.h"

RTSP::RTSP()
{
    id=-1;
    isUsed = -1;
}
int RTSP::getId()
{
    return id;
}
void RTSP::setId(int id)
{
    this->id = id;
}
QString RTSP::getRtsp()
{
    return rtsp;
}
void RTSP::setRtsp(QString rtsp)
{
    this->rtsp = rtsp;
}
int RTSP::getIsUsed()
{
    return isUsed;
}
void RTSP::setIsUsed(int isUsed)
{
    this->isUsed = isUsed;
}
