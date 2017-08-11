#include "biaoding_2.h"
#include "ui_biaoding_2.h"
#include "index.h"
#include "biaoding_1.h"

Biaoding_2::Biaoding_2(WeightPlatform weightPlatform, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Biaoding_2)
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
    connect(ui->confirm,SIGNAL(clicked()),this,SLOT(slotConfirm()));
}

Biaoding_2::~Biaoding_2()
{
    sensorIsnThread.close();
    steedyThread.close();
    delete ui;
}

void Biaoding_2::returnIndex()
{
//    Index *menu=new Index();
//    menu->show();
    this->close();
}

void Biaoding_2::returnPage()
{
    //Biaoding_1 *returnPage=new Biaoding_1();
   // returnPage->show();
    this->close();
}


void Biaoding_2::slotRevceviedSteedyFlag(QString str, float currentAllISN, State_Inode state_Inode)
{
    this->currentAllISN=currentAllISN;
    ui->label_steedyFlag->setText(str);
    ui->lineEdit_AllISN->setText(QString::number(currentAllISN));
}


void Biaoding_2::slotConfirm()
{
    //第一个加载点的重量
    float firstWeigh=(weightPlatform.getLoadPoint()-weightPlatform.getEmptyScale())*weightPlatform.getFirstThread();

    if(ui->label_steedyFlag->text()=="不稳定"){
        QMessageBox::information(NULL,"温馨提示","称台不稳定",QMessageBox::Yes);

    //第二个加载点如果小于上个加载点+30的重量 那么报错

    }else if(ui->lineEdit_Weigh->text().toFloat()<firstWeigh+(float)30){
        QMessageBox::information(NULL,"温馨提示","输入重量必须比第一个加载点的重量大30",QMessageBox::Yes);
    }else{//重量有效
        float CurrentWeight = currentAllISN;

        //第一段线性
        float F_temp0=(ui->lineEdit_Weigh->text().toFloat()-firstWeigh)/(CurrentWeight-weightPlatform.getLoadPoint());

        if(F_temp0>(float)99.999){
            QMessageBox::information(NULL,"温馨提示","线性太大了，请重新标定",QMessageBox::Yes);
        }else if(F_temp0<(float)0.00101){
            QMessageBox::information(NULL,"温馨提示","线性太小了，请重新标定",QMessageBox::Yes);
        }else if(qAbs((F_temp0-weightPlatform.getFirstThread())/weightPlatform.getFirstThread())>(float)0.1){
            QMessageBox::information(NULL,"温馨提示","第二段线性不得大于第一断线性10%以上",QMessageBox::Yes);
        }

        else{
            if(CurrentWeight>(float)850000){
                QMessageBox::information(NULL,"温馨提示","太重了",QMessageBox::Yes);
            }else{

                //第二
                weightPlatform.setLoadPoint2(CurrentWeight);//更新第二个加载点的内码
                weightPlatform.setSecondThread(F_temp0);//更新第二段线性

                //删除数据库
                weightPlatformImpl.deleteWeightPlatform();
                //插入数据库
                weightPlatformImpl.insertWeightPlatform(weightPlatform);

                this->close();

            }
        }


    }

}
