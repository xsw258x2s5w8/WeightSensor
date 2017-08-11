#ifndef INDEX_H
#define INDEX_H

#include <QMainWindow>
#include <QTimer>
#include <QPixmap>
#include <QImage>
#include <QPushButton>
#include <QLabel>
#include <iostream>
#include <opencv/cv.h>
#include <opencv2/highgui/highgui.hpp>
#include "impl/maininterfacetemp.h"
#include "impl/maininterfacetempimpl.h"
#include "impl/ipconfig.h"
#include "impl/ipconfigimpl.h"
#include "impl/rtsp.h"
#include "impl/rtspimpl.h"
#include "page2.h"
#include "erweimaguanli.h"
#include "lishijilu.h"
#include "yiciguobang.h"
#include "erciguobang.h"
#include "shipin.h"
#include "shipinshezhi.h"
#include "impl/videosettings.h"
#include "impl/videosettingsimpl.h"
#include "impl/videosettingstemp.h"
#include "impl/videosettingstempimpl.h"

using namespace std;
using namespace cv;

namespace Ui {
class Index;
}

class Index : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit Index(QWidget *parent = 0);
    ~Index();

public slots:
    void showMenuWidget();// 进入菜单界面
    void showQRcode();//进入二维码界面
    void showPrint();//进入打印界面。
    void showYiguobang();//进入一次过磅
    void showErciguobang();//进入二次过磅界面
    void showShipin();//进入视频界面

private:
    Ui::Index *ui;
    QTimer *timer;
    QImage image,realimage;
    VideoCapture vcap;
    Mat frame;

private slots:
    void showImage();
    void readframe();

private:
    MainInterfaceTempImpl *maininterfacetempimpl;//数据接口
    QList<QLineEdit *> listLedit;  //用于保存生成的字段编辑框

private:
    void showLineEdit();//根据maintemp表显示主界面的可选字段
    void generateEdit();//生成字段
    void InitEthernet();//以太网初始化
    void VideoInit();//视频设置初始化
    void IPvideoInit();//IP视频初始化

};

#endif // INDEX_H
