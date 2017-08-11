#include "biaoding.h"
#include "ui_biaoding.h"
#include "index.h"
#include "tiaochen.h"
#include "biaoding_1.h"

extern float OpenZeroIsn;
extern float ManualZeroIsn;
extern float ZeroIsn_init;

Biaoding::Biaoding(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Biaoding)
{
    ui->setupUi(this);
    //this->setWindowState(Qt::WindowFullScreen);
    this->setAttribute(Qt::WA_DeleteOnClose);//为了关闭子窗口后能够调用析构函数

    //读数据库
    PrepareData();

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
    connect(ui->confirm,SIGNAL(clicked()),this,SLOT(showCalibration()));
    connect(ui->skipBtn,SIGNAL(clicked()),this,SLOT(showCalibration_skip()));
}

Biaoding::~Biaoding()
{
    sensorIsnThread.close();
    steedyThread.close();
    delete ui;
}

void Biaoding::returnIndex()
{
   // Index *menu=new Index();
    //menu->show();
    this->close();
}

void Biaoding::returnPage()
{
    Tiaochen *returnPage=new Tiaochen();
    returnPage->show();
    this->close();
}

void Biaoding::showCalibration()
{
    if(ui->label_steedy->text()=="不稳定"){
        QMessageBox::information(NULL,"温馨提示","秤台不稳定",QMessageBox::Yes);
    }else{
        float CurrentWeight;
        float F_temp0;

        CurrentWeight=currentAllISN;
        if(CurrentWeight<(float)-100000){
            QMessageBox::information(NULL,"温馨提示","秤台内码过小",QMessageBox::Yes);
        }else if(CurrentWeight>(float)499999){
            QMessageBox::information(NULL,"温馨提示","称台内码过大",QMessageBox::Yes);
        }else{//内码正常
            OpenZeroIsn=0;
            ManualZeroIsn=0;
            ZeroIsn_init=CurrentWeight;

            F_temp0 = weightPlatform.getEmptyScale()-ZeroIsn_init ;//零位变化量
            weightPlatform.setEmptyScale(ZeroIsn_init);//设置空秤内码

            if(weightPlatform.getLoadPoint()<(float)999999.8){

                weightPlatform.setLoadPoint(weightPlatform.getLoadPoint()-F_temp0);

                if(weightPlatform.getLoadPoint()>(float)899999.9){
                    weightPlatform.setLoadPoint((float)999999.9);
                }
            }else{
                weightPlatform.setLoadPoint((float)999999.9);
            }

            //删除
            weightPlatformImpl.deleteWeightPlatform();
            //插入
            weightPlatformImpl.insertWeightPlatform(weightPlatform);
        }

        //保存零点内码
        saveZeroIsn();

        //跳到下一个页面
        Biaoding_1 *showCalibration=new Biaoding_1(weightPlatform);
        showCalibration->show();
        this->close();
    }

}


void Biaoding::PrepareData()
{
    float F_temp;

    //保存开机置零内码和手动置零内码
    F_temp=ManualZeroIsn+OpenZeroIsn;

    //读取数据库
    weightPlatform=weightPlatformImpl.selectWeightPlatform();

    //初始化零点内码

    float empytIsn=weightPlatform.getEmptyScale()+F_temp; //初始零点内码
    weightPlatform.setEmptyScale(empytIsn);

    if(weightPlatform.getLoadPoint()<(float)999999.8){//说明有使用第一个加载点
        float loadPoint=weightPlatform.getLoadPoint()+F_temp;
        weightPlatform.setLoadPoint(loadPoint);

    }
    if(weightPlatform.getLoadPoint()<(float)999999.8){//说明有使用第二个加载点
        float loadPoint2=weightPlatform.getLoadPoint()+F_temp;
        weightPlatform.setLoadPoint2(loadPoint2);
    }
}


void Biaoding::slotRevceviedSteedyFlag(QString str, float currentAllISN,State_Inode state_Inode)
{
    //保存收到的数据
    ui->label_steedy->setText(str);
    this->currentAllISN=currentAllISN;
    this->state_Inode=state_Inode;
    qDebug()<<OpenZeroIsn<<"ddddddddddddddddddddddddddddddddddddddddddddddddddddddddd";
}


void Biaoding::showCalibration_skip()
{
    //跳过按钮只负责传数据，weightlatform再prepareData中初始化过了。
        //跳到下一个页面
        Biaoding_1 *showCalibration=new Biaoding_1(weightPlatform);
        showCalibration->show();
        this->close();

}


void Biaoding::saveZeroIsn()
{
    //保存零点的内码到数据库中
    SensorInfoImpl sensorInfoImpl;//传感器信息表接口
    QList<SensorInfo> sensorInfoList=sensorInfoImpl.selectSensorinfo();//列表接口
     //赋值
    for(int i=0;i<sensorInfoList.length();i++){
        sensorInfoList[i].setZeroIsn(state_Inode.CellState[i].isn);
    }

    //先删除表格
    sensorInfoImpl.deleteSensorinfo();

     //插入到信息表中
    for(int i=0;i<sensorInfoList.length();i++){
        sensorInfoImpl.insertSensorinfo(sensorInfoList[i]);
    }
}
