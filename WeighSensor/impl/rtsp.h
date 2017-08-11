#ifndef RTSP_H
#define RTSP_H
#include <QString>
class RTSP
{
public:
    RTSP();
    int getId();
    void setId(int id);
    QString getRtsp();
    void setRtsp(QString rtsp);
    int getIsUsed();
    void setIsUsed(int isUsed);

private:
    int id;
    QString rtsp;
    int isUsed;

};

#endif // RTSP_H
