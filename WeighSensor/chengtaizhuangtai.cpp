#include "chengtaizhuangtai.h"
#include "ui_chengtaizhuangtai.h"
#include "index.h"
#include "tiaochen.h"


Chengtaizhuangtai::Chengtaizhuangtai(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Chengtaizhuangtai)
{
    ui->setupUi(this);
    //this->setWindowState(Qt::WindowFullScreen);
    this->setAttribute(Qt::WA_DeleteOnClose);//为了关闭子窗口后能够调用析构函数

    //初始化
    btnFlag=0;
    btnSwitchFlag=0;

    //生成布局
    generateLayout();

    //查表获取零点的内码
    sensorList=sensorInfoImpl.selectSensorinfo();
    qDebug()<<"sensorList11111111111111111111111111:"<<sensorList.length();
    //开启读内码  的线程；
    //暂且
    int number=sensorList.length();
    sensorIsnThread.SetSensorNumber(number);//为了配置启动常规采集命令的信息
    sensorIsnThread.start();

    //建立界面和线程的槽
    connect(&sensorIsnThread,SIGNAL(SendISN(State_Inode,int)),this,SLOT(slotReceviedIsnThread(State_Inode,int)));

    //按钮槽
    connect(ui->returnIndex,SIGNAL(clicked()),this,SLOT(returnIndex()));
    connect(ui->returnPage,SIGNAL(clicked()),this,SLOT(returnPage()));
    connect(ui->btn_ISN,SIGNAL(clicked()),this,SLOT(slotBtnIsn()));
    connect(ui->btn_zeroIsn,SIGNAL(clicked()),this,SLOT(slotBtnZeroIsn()));
    connect(ui->btn_switch,SIGNAL(clicked()),this,SLOT(slotBtnSwitch()));

}

Chengtaizhuangtai::~Chengtaizhuangtai()
{
    sensorIsnThread.close();
    delete ui;
}

void Chengtaizhuangtai::returnIndex()
{
//    Index *menu=new Index();
//    menu->show();
    this->close();
}

void Chengtaizhuangtai::returnPage()
{
    Tiaochen *returnPage=new Tiaochen();
    returnPage->show();
    this->close();
}


void Chengtaizhuangtai::generateLayout()
{
    //生成16个位置的label
   for(int i=0;i<4;i++){
       QLabel *label=new QLabel(QString::number(i+1));
       label->setStyleSheet("background-color: rgb(167, 167, 167);");
       QLabel *label2=new QLabel(" ");
       QHBoxLayout *phLayout=new QHBoxLayout();
       phLayout->addWidget(label,1);
       phLayout->addWidget(label2,4);
       ui->gridLayout_2->addLayout(phLayout,0,i);

       listAddressLabel.append(label2);
   }

   for(int i=4;i<8;i++){
       QLabel *label=new QLabel(QString::number(i+1));
       label->setStyleSheet("background-color: rgb(167, 167, 167);");
       QLabel *label2=new QLabel(" ");
       QHBoxLayout *phLayout=new QHBoxLayout();
       phLayout->addWidget(label,1);
       phLayout->addWidget(label2,4);
       ui->gridLayout_2->addLayout(phLayout,1,i-4);

       listAddressLabel.append(label2);
   }

   for(int i=8;i<12;i++){
       QLabel *label=new QLabel(QString::number(i+1));
       label->setStyleSheet("background-color: rgb(167, 167, 167);");
       QLabel *label2=new QLabel(" ");
       QHBoxLayout *phLayout=new QHBoxLayout();
       phLayout->addWidget(label,1);
       phLayout->addWidget(label2,4);
       ui->gridLayout_2->addLayout(phLayout,2,i-8);

       listAddressLabel.append(label2);
   }

   for(int i=12;i<16;i++){
       QLabel *label=new QLabel(QString::number(i+1));
       label->setStyleSheet("background-color: rgb(167, 167, 167);");
       QLabel *label2=new QLabel(" ");
       QHBoxLayout *phLayout=new QHBoxLayout();
       phLayout->addWidget(label,1);
       phLayout->addWidget(label2,4);
       ui->gridLayout_2->addLayout(phLayout,3,i-12);

       listAddressLabel.append(label2);
   }

}


void Chengtaizhuangtai::slotReceviedIsnThread(State_Inode state_Inode, int length)
{


    //计算总内码
    float currentAllIsn=0;
    for(int i=0;i<length;i++){
        currentAllIsn+=state_Inode.CellState[i].isn;
    }


    //内码按钮
    if(btnFlag==0){
        if(btnSwitchFlag==1){//切换按钮激活
            for(int i=0;i<length;i++){
                //暂且认为 空秤内码为零点内码减去 开机置零内码和手动置零内码-----------------------------------空秤内码 不知道怎么获得不确定
                listAddressLabel[i]->setText(QString::number(state_Inode.CellState[i].isn));
            }
            ui->lineEdit_AllISN->setText(QString::number(currentAllIsn));
            ui->lineEdit_state->setText("当前内码-空秤内码");
        }else{//没激活
            empty_State_Inode=state_Inode; //在没激活切换按钮时保存空秤内码
            for(int i=0;i<length;i++){
                listAddressLabel[i]->setText(QString::number(state_Inode.CellState[i].isn));
            }
            ui->lineEdit_AllISN->setText(QString::number(currentAllIsn));
            ui->lineEdit_state->setText("当前内码");
        }

    //标定零点按钮
    }else if(btnFlag==1){
        if(btnSwitchFlag==1){//切换按钮激活
            for(int i=0;i<length;i++){
                listAddressLabel[i]->setText(QString::number(state_Inode.CellState[i].isn-sensorList[i].getZeroIsn()));
            }
            ui->lineEdit_state->setText("当前内码-标定零点");
        }else{//没激活
            for(int i=0;i<length;i++){
                listAddressLabel[i]->setText(QString::number(sensorList[i].getZeroIsn()));
            }
            ui->lineEdit_AllISN->setText(" ");
            ui->lineEdit_state->setText("标定时空秤的内码");
        }

    }

}


void Chengtaizhuangtai::slotBtnIsn()
{
    btnFlag=0;
    btnSwitchFlag=0;//还原
}


void Chengtaizhuangtai::slotBtnZeroIsn()
{
    btnFlag=1;
    btnSwitchFlag=0;//还原
}


void Chengtaizhuangtai::slotBtnSwitch()
{
    btnSwitchFlag=1;
}
