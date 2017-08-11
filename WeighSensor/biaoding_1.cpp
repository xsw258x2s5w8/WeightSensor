#include "biaoding_1.h"
#include "ui_biaoding_1.h"
#include "index.h"
#include "biaoding.h"
#include "biaoding_2.h"

Biaoding_1::Biaoding_1(WeightPlatform weightPlatform, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Biaoding_1)
{
    ui->setupUi(this);
    //this->setWindowState(Qt::WindowFullScreen);
    this->setAttribute(Qt::WA_DeleteOnClose);//为了关闭子窗口后能够调用析构函数

    //接收上个界面传过来的数据
    this->weightPlatform=weightPlatform;

    //开启读内码  的线程；
    //暂且
    int number=3;
    sensorIsnThread.SetSensorNumber(number);//为了配置启动常规采集命令的信息
    sensorIsnThread.start();
    steedyThread.start();

    //读取内码线程与 判断稳定线程的槽连接
    connect(&sensorIsnThread,SIGNAL(SendISN(State_Inode,int)),&steedyThread,SLOT(slotGetISN(State_Inode,int)));

    //判断稳定的线程与界面的槽连接
    connect(&steedyThread,SIGNAL(SendSteedyFlag(QString,float,State_Inode)),this,SLOT(slotRevceviedSteedyFlag(QString,float,State_Inode)));

    connect(ui->returnIndex,SIGNAL(clicked()),this,SLOT(returnIndex()));
    connect(ui->returnPage,SIGNAL(clicked()),this,SLOT(returnPage()));
    connect(ui->confirm,SIGNAL(clicked()),this,SLOT(showConfirmCalibration()));
    connect(ui->skip,SIGNAL(clicked()),this,SLOT(showSkipCalibration()));
}

Biaoding_1::~Biaoding_1()
{
    sensorIsnThread.close();
    steedyThread.close();
    delete ui;
}

void Biaoding_1::returnIndex()
{
//    Index *menu=new Index();
//    menu->show();
    this->close();
}

void Biaoding_1::returnPage()
{
    Biaoding *returnPage=new Biaoding();
    returnPage->show();
    this->close();
}

void Biaoding_1::showConfirmCalibration()
{
    if(ui->label_steedyFlag->text()=="不稳定"){
        QMessageBox::information(NULL,"温馨提示","称台不稳定",QMessageBox::Yes);
    }else if(ui->lineEdit_Weigh->text().toFloat()<(float)11){
        QMessageBox::information(NULL,"温馨提示","输入重量太轻了",QMessageBox::Yes);
    }else{//重量有效
        float CurrentWeight = currentAllISN;

        //第一段线性
        float F_temp0=ui->lineEdit_Weigh->text().toFloat()/(CurrentWeight-weightPlatform.getEmptyScale());

        if(F_temp0>(float)99.999){
            QMessageBox::information(NULL,"温馨提示","线性太大了，请重新标定",QMessageBox::Yes);
        }else if(F_temp0<(float)0.00101){
            QMessageBox::information(NULL,"温馨提示","线性太小了，请重新标定",QMessageBox::Yes);
        }else{
            if(CurrentWeight>(float)850000){
                QMessageBox::information(NULL,"温馨提示","太重了",QMessageBox::Yes);
            }else{
                weightPlatform.setLoadPoint(CurrentWeight);//更新第一个加载点的内码
                weightPlatform.setFirstThread(F_temp0);//更新第一段线性

                //取消第二个加载点
                weightPlatform.setLoadPoint2((float)999999.9);
                weightPlatform.setSecondThread((float)1.00000);

                //删除数据库
                weightPlatformImpl.deleteWeightPlatform();
                //插入数据库
                weightPlatformImpl.insertWeightPlatform(weightPlatform);

                Biaoding_2 *showConfirmCalibration=new Biaoding_2(weightPlatform);
                showConfirmCalibration->show();
                this->close();

            }
        }


    }


}

void Biaoding_1::showSkipCalibration()
{
    if(weightPlatform.getLoadPoint2()<(float)899999.9){
        Biaoding_2 *showSkipCalibration=new Biaoding_2(weightPlatform);
        showSkipCalibration->show();
        this->close();
    }else{
        QMessageBox::information(NULL,"温馨提示","无法直接标定第二个加载点，因为之前没有标定过第2个加载点");
    }

}


void Biaoding_1::slotRevceviedSteedyFlag(QString str, float currentAllISN, State_Inode state_Inode)
{
    //保存收到的数据
    ui->label_steedyFlag->setText(str);
    ui->lineEdit_AllISN->setText(QString::number(currentAllISN-weightPlatform.getEmptyScale()));//显示的总内码为 当前内码减去空秤时的内码
    this->currentAllISN=currentAllISN;
    //this->state_Inode=state_Inode;
}
