#ifndef VIDEOSETTINGSTEMP_H
#define VIDEOSETTINGSTEMP_H
class VideoSettingsTemp
{
public:
    VideoSettingsTemp();
    int getId();
    void setId(int id);
    int getVideoFormatId();
    void setVideoFormatId(int videoFormatId);
    int getIsOpenCamera();
    void setIsOpenCamera(int isOpenCamera);
    int getCompcRatio();
    void setCompcRatio(int copmcRatio);
private:
    int id;//id
    int videoFormatId;//视频格式id
    int isOpenCamera;//是否开启拍照
    int compcRatio;//照片压缩比
};

#endif // VIDEOSETTINGSTEMP_H
