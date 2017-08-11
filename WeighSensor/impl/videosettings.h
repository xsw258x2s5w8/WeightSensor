#ifndef VIDEOSETTINGS_H
#define VIDEOSETTINGS_H
#include <QString>
class VideoSettings
{
public:
    VideoSettings();
    int getVideoFormatId();
    void setVideoFormatId(int videoFormatId);
    QString getVideoFormat();
    void setVideoFormat(QString videoFormat);
    int getWidth();
    void setWidth(int width);
    int getHeight();
    void setHeight(int height);


private:
    int videoFormatId;//视频格式id
    QString videoFormat;//视频格式
    int width;//宽
    int height;//高
};

#endif // VIDEOSETTINGS_H
