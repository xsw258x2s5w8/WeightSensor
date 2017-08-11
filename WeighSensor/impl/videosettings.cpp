#include "videosettings.h"

VideoSettings::VideoSettings()
{

}

int VideoSettings::getVideoFormatId()
{
    return videoFormatId;
}

void VideoSettings::setVideoFormatId(int videoFormatId)
{
    this->videoFormatId = videoFormatId;
}

QString VideoSettings::getVideoFormat()
{
    return videoFormat;
}

void VideoSettings::setVideoFormat(QString videoFormat)
{
    this->videoFormat = videoFormat;
}

int VideoSettings::getWidth()
{
    return width;
}
void VideoSettings::setWidth(int width)
{
    this->width = width;
}
int VideoSettings::getHeight()
{
    return height;
}
void VideoSettings::setHeight(int height)
{
    this->height = height;
}
