#ifndef VIDEOSETTINGSIMPL_H
#define VIDEOSETTINGSIMPL_H
#include <QtSql>
#include <QString>
#include "videosettings.h"
class VideoSettingsImpl
{
public:
    VideoSettingsImpl();
    VideoSettings selectVideoSettingById(int videoFormatId);//根据视频格式id查询记录
    VideoSettings selectVideoSettingByFormat(QString videoFormat);//根据视频格式来查询记录
private:
    QSqlDatabase database;
};

#endif // VIDEOSETTINGSIMPL_H
