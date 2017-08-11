#ifndef SHIPIN_TWOUSB_H
#define SHIPIN_TWOUSB_H

#include <QWidget>

#include <QImage>
#include <QTimer> //设置采集数据的间隔时间
#include <QDateTime>
#include <opencv2/highgui/highgui.hpp>
#include <opencv/cv.h>
#include <iostream>
#include <unistd.h>
#include <QDebug>
#include <QMessageBox>
#include "shipin.h"
#include "index.h"
#include "impl/videosettings.h"
#include "impl/videosettingsimpl.h"
#include "impl/videosettingstemp.h"
#include "impl/videosettingstempimpl.h"

using namespace std;
using namespace cv;

//视频清晰度普通
#define commonwidth 153
#define commonheight 119
//视频清晰度流畅
#define fluentwidth 320
#define fluentheight 240
//视频清晰度标清
#define standardwidth 640
#define standardheight 480

namespace Ui {
class Shipin_twousb;
}

class Shipin_twousb : public QWidget
{
    Q_OBJECT
    
public:
    explicit Shipin_twousb(QString name, QWidget *parent = 0);
    ~Shipin_twousb();
    
private:
    Ui::Shipin_twousb *ui;
    QTimer *timer;
    QImage *imag;
    CvCapture *cam,*cam2;//视频获取结构，用来作为视频获取函数的一个参数
    IplImage *frame;//申请IplImage类型指针，就是申请内存空间来存放每一帧图像
    void saveImage();//保存照片

private slots:
    void readFarme();  //读取当前帧信息
    void openCamera1(); //打开USB摄像头
    void openCamera2();//
    void showfourFrame();
    void returnIndex();
    void returnPage();
};

#endif // SHIPIN_TWOUSB_H
