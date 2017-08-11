#include "shipin_twousb.h"
#include "ui_shipin_twousb.h"

Shipin_twousb::Shipin_twousb(QString name, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Shipin_twousb)
{
    ui->setupUi(this);
//   cam = new CvCapture();
//   cam2 = new CvCapture();

    cam=NULL;
    cam2=NULL;
    frame = NULL;
    imag=new QImage();
    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(readFarme()));
    connect(ui->usbFrame,SIGNAL(clicked()),this,SLOT(openCamera1()));
    connect(ui->moniFrame,SIGNAL(clicked()),this,SLOT(openCamera2()));
    connect(ui->fourFrame,SIGNAL(clicked()),this,SLOT(showfourFrame()));
    timer->start(40);
    //判断点击的是usb摄像头还是模拟摄像头
    if(name == "USBCamera")
        openCamera1();
    if(name == "moniCamera")
        openCamera2();
    qDebug()<<"open  "<<name;
}

Shipin_twousb::~Shipin_twousb()
{
//    if(cam!=NULL)
//        cvReleaseCapture(&cam);
//    if(cam2!=NULL)
//        cvReleaseCapture(&cam2);
//    qDebug()<<1;
    delete ui;
}

void Shipin_twousb::openCamera1()
{
    if(cam2 != NULL){
//        timer->stop();
//        cvReleaseImage(&frame);
        cvReleaseCapture(&cam2);//释放内存；
        qDebug()<<"close moniCamera";
    }
    ui->usbFrame->setEnabled(false);
    ui->moniFrame->setEnabled(true);
    sleep(1);
    cam=cvCreateCameraCapture(0);
    if(!cam){
        QMessageBox::warning(NULL, "USB摄像头识别", "摄像头未插入", QMessageBox::No, QMessageBox::No);
        cvReleaseCapture(&cam2);
//        cvReleaseImage(&frame);
            Shipin *shipin = new Shipin();
            shipin->show();
            qDebug()<<"close moniCamera";
            this->close();
    }else{
        qDebug()<<"opecv usbCamera";

        //数据库读取视频设置
        VideoSettingsTempImpl videotempmpl;
        VideoSettingsTemp videotemp;
        videotemp = videotempmpl.selectVideoSettings();
        VideoSettings video;

        VideoSettingsImpl videoImpl;
        video = videoImpl.selectVideoSettingById(videotemp.getVideoFormatId());

        cvSetCaptureProperty ( cam, CV_CAP_PROP_FRAME_WIDTH,  video.getWidth() );
        cvSetCaptureProperty ( cam, CV_CAP_PROP_FRAME_HEIGHT, video.getHeight() );
        connect(timer,SIGNAL(timeout()),this,SLOT(readFarme()));

        }
}
void Shipin_twousb::openCamera2()
{
    if(cam != NULL){
//        timer->stop();
        cvReleaseCapture(&cam);//释放内存；
        qDebug()<<"close usbCamera";
    }
    ui->moniFrame->setEnabled(false);
    ui->usbFrame->setEnabled(true);
    sleep(1);
    cam2=cvCreateCameraCapture(1);
    if(!cam2){
        QMessageBox::warning(NULL, "模拟摄像头识别", "摄像头未插入", QMessageBox::No, QMessageBox::No);
        cvReleaseCapture(&cam2);
//        cvReleaseImage(&frame);
            Shipin *shipin = new Shipin();
            shipin->show();
            qDebug()<<"close moniCamera";
            this->close();
    }else{
        qDebug()<<"opecv moniCamera";
            cvSetCaptureProperty ( cam2, CV_CAP_PROP_FRAME_WIDTH,  commonwidth );
            cvSetCaptureProperty ( cam2, CV_CAP_PROP_FRAME_HEIGHT, commonheight );

    }
}

void Shipin_twousb::readFarme()
{
    if(cam != NULL)
        frame=cvQueryFrame(cam);
    else
        frame=cvQueryFrame(cam2);        
    QImage image=QImage((const uchar*)frame->imageData,frame->width,frame->height,QImage::Format_RGB888).rgbSwapped();
//    QImage displayimage;
//    int Owidth = image.width(),Oheight = image.height();
//    int Fwidth,Fheight;       //缩放后的图片大小
//    int Mul;
//    if(Owidth / ui->label->width() >= Oheight / ui->label->height())
//        Mul=Owidth/ui->label->width();
//    else
//        Mul=Oheight/ui->label->height();
//    Fwidth=Owidth/Mul;
//    Fheight=Oheight/Mul;//记录图片与label大小的比例，用于缩放图片
//    displayimage = image.scaled(Fwidth,Fheight,Qt::KeepAspectRatio);
    ui->label->setPixmap(QPixmap::fromImage(image));
}


void Shipin_twousb::saveImage()
{
    const QPixmap *pixmap = ui->label->pixmap();
    QString format = "png";
    QDateTime dateTime = QDateTime::currentDateTime();
    QString fileName ="../WeighSensor/savePicture/" + dateTime.toString("yyyy-MM-dd hh-mm-ss-zzz")+ "." + format;
    if (!fileName.isEmpty())
        pixmap->save(fileName, format.toAscii());
}

void Shipin_twousb::showfourFrame()
{
    timer->stop();
    cvReleaseImage(&frame);
    Shipin *shipin = new Shipin();
    shipin->show();
    qDebug()<<"close usbCamera or moniCamera";
    this->close();
}

void Shipin_twousb::returnIndex()
{
    this->close();
}

void Shipin_twousb::returnPage()
{
    Shipin *shipin = new Shipin();
    shipin->show();
    this->close();
}
