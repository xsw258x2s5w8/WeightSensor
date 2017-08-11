#include "videosettingstemp.h"

VideoSettingsTemp::VideoSettingsTemp()
{
    videoFormatId = 0;
    isOpenCamera = 0;
    compcRatio = 0;
}

int VideoSettingsTemp::getId()
{
    return id;
}

void VideoSettingsTemp::setId(int id)
{
    this->id = id;
}

int VideoSettingsTemp::getVideoFormatId()
{
    return videoFormatId;
}

void VideoSettingsTemp::setVideoFormatId(int videoFormatId)
{
    this->videoFormatId = videoFormatId;
}

int VideoSettingsTemp::getIsOpenCamera()
{
    return isOpenCamera;
}

void VideoSettingsTemp::setIsOpenCamera(int isOpenCamera)
{
    this->isOpenCamera = isOpenCamera;
}

int VideoSettingsTemp::getCompcRatio()
{
    return compcRatio;
}

void VideoSettingsTemp::setCompcRatio(int copmcRatio)
{
    this->compcRatio = copmcRatio;
}
