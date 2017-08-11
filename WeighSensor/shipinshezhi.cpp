#include "shipinshezhi.h"
#include "ui_shipinshezhi.h"
#include "index.h"
#include "page2.h"

Shipinshezhi::Shipinshezhi(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Shipinshezhi)
{
    ui->setupUi(this);
    this->setWindowState(Qt::WindowFullScreen);
    //设置清晰度
    ui->comVideoshar->setCurrentIndex(1);

    //查询视频设置临时表设置
    VideoSettingsTempImpl videotempimpl;
    if(videotempimpl.isExistVideoSettings() > 0){
        VideoSettingsTemp videotemp = videotempimpl.selectVideoSettings();
        ui->comVideoshar->setCurrentIndex(videotemp.getVideoFormatId());
        ui->checktakePic->setChecked(videotemp.getIsOpenCamera());
        ui->pressratio->setText(QString::number(videotemp.getCompcRatio(),10));
    }
    connect(ui->returnIndex_2,SIGNAL(clicked()),this,SLOT(returnIndex()));
    connect(ui->returnPage_2,SIGNAL(clicked()),this,SLOT(returnPage()));
    connect(ui->emptyInfo,SIGNAL(clicked()),this,SLOT(emptyInfo()));
    connect(ui->savevideoInfo,SIGNAL(clicked()),this,SLOT(saveVideoInfo()));
}

Shipinshezhi::~Shipinshezhi()
{
    delete ui;
}

void Shipinshezhi::emptyInfo()//清空设置
{
    ui->comVideoshar->setCurrentIndex(1);
    ui->checktakePic->setChecked(false);
    ui->pressratio->setText("80");

    //清空数据库
    VideoSettingsTempImpl videotempimpl;
    videotempimpl.deleteSettingTemp();//清空视频临时表
    VideoSettingsTemp videotemp;
    VideoSettingsImpl videompl;
    VideoSettings video;
    video = videompl.selectVideoSettingByFormat(ui->comVideoshar->currentText());//根据视频格式查找格式id
    videotemp.setIsOpenCamera(ui->checktakePic->isChecked());//将视频设置信息存入临时表
    videotemp.setCompcRatio(ui->pressratio->text().toInt());
    videotemp.setVideoFormatId(video.getVideoFormatId());
    if(videotempimpl.insertVideoSettings(videotemp) > 0)
        QMessageBox::information(NULL,"视频设置","清空成功！",QMessageBox::Yes);
}

void Shipinshezhi::saveVideoInfo()
{
    VideoSettingsTempImpl videotempimpl;
    QString Videoshar = ui->comVideoshar->currentText();
    int istakePic = ui->checktakePic->isChecked();
    int ratio = ui->pressratio->text().toInt();
    //保存数据库
    if(videotempimpl.isExistVideoSettings() > 0)//判断视频设置临时表是否有数据，若有数据先删除
        videotempimpl.deleteSettingTemp();//删除临时表中的数据
    VideoSettingsTemp videotemp;
    VideoSettingsImpl videompl;
    VideoSettings video;
    video = videompl.selectVideoSettingByFormat(Videoshar);//根据视频格式查找格式id
    videotemp.setIsOpenCamera(istakePic);//将视频设置信息存入临时表
    videotemp.setCompcRatio(ratio);
    videotemp.setVideoFormatId(video.getVideoFormatId());
    if(videotempimpl.insertVideoSettings(videotemp) > 0)
        QMessageBox::information(NULL,"视频设置","保存成功！",QMessageBox::Yes);
}

void Shipinshezhi::returnIndex()
{
//    Index *menu=new Index();
//    menu->show();
    this->close();
}

void Shipinshezhi::returnPage()
{
    page2 *returnPage=new page2();
    returnPage->show();
    this->close();
}
