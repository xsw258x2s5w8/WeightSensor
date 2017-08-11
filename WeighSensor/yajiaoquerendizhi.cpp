#include "yajiaoquerendizhi.h"
#include "ui_yajiaoquerendizhi.h"
#include "index.h"
#include "kongchengqueren.h"
#include "dizhi.h"

Yajiaoquerendizhi::Yajiaoquerendizhi(All_Link_Sensor_ID all_Link_Sensor_ID,State_Inode empty_State_Inode,Set_Address_Sensor Ori_set_Address_Sensor, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Yajiaoquerendizhi)
{
    ui->setupUi(this);
    //this->setWindowState(Qt::WindowFullScreen);
    this->setAttribute(Qt::WA_DeleteOnClose);//为了关闭子窗口后能够调用析构函数

    //获得从空秤界面传过来的空秤内码
    this->all_Link_Sensor_ID=all_Link_Sensor_ID;
    this->empty_State_Inode=empty_State_Inode;
    this->Ori_set_Address_Sensor=Ori_set_Address_Sensor;
    qDebug()<<"从空秤界面传过来的数据："<<empty_State_Inode.CellState[0].isn<<"个数："<<all_Link_Sensor_ID.number;

    //初始化第一个地址（将被用来设置传感器的地址），这个用来显示在界面的
    sensorAddress=1;
    ui->lineEdit_address->setText(QString::number(sensorAddress));

    //根据传感器数量生成label
    GenerateLabels(all_Link_Sensor_ID.number);

    //开启读内码的线程
    sensorIsnThread.SetSensorNumber(all_Link_Sensor_ID.number);
    sensorIsnThread.start();
    connect(&sensorIsnThread,SIGNAL(SendISN(State_Inode,int)),this,SLOT(slotReceviedIsnThread(State_Inode,int)));


    //界面槽连接
    connect(ui->returnIndex,SIGNAL(clicked()),this,SLOT(returnIndex()));
    connect(ui->returnPage,SIGNAL(clicked()),this,SLOT(returnPage()));
    connect(ui->confirm_Btn,SIGNAL(clicked()),this,SLOT(slotConfirmBtn()));
    connect(ui->restoreBtn,SIGNAL(clicked()),this,SLOT(slotRestoreBtn()));

}

Yajiaoquerendizhi::~Yajiaoquerendizhi()
{
    sensorIsnThread.close();
    delete ui;
}

void Yajiaoquerendizhi::returnIndex()
{
//    Index *menu=new Index();
//    menu->show();
    this->close();
}

void Yajiaoquerendizhi::returnPage()
{
    Dizhi *returnPage=new Dizhi();
    returnPage->show();
    this->close();
}


void Yajiaoquerendizhi::GenerateLabels(int length)
{
    for(int i=0;i<length;i++){
         QLabel *label=new QLabel(QString::number(i+1));
         label->setAlignment(Qt::AlignCenter);
         label->setStyleSheet("background-color:rgb(172, 172, 172)");

         //用于生成
         if(i%2==0){
             ui->gridLayout->addWidget(label,0,i/2);
         }else if(i%2==1){
             ui->gridLayout->addWidget(label,1,i/2);
         }

         listLabel.append(label);

    }
}


void Yajiaoquerendizhi::SelectLabelPaint(bool select_label, int pos)
{
    if(select_label==true){//需要选中label  画边框
         listLabel[pos]->setStyleSheet("background-color:rgb(172, 172, 172);border-width: 2px;border-style:solid;border-color:blue;");
    }else{//取消边框
         listLabel[pos]->setStyleSheet("background-color:rgb(172, 172, 172)");
    }



}


void Yajiaoquerendizhi::slotConfirmBtn()
{
    //按钮逻辑部分
    int flag=confirmBtn();

    //确认到最后一个传感器了
    if(sensorAddress==listLabel.length()&&flag==0){

        //发送设地址的命令

        //保存到数据库

        //关闭本页面
        qDebug()<<"这已经是最后一个传感器了，地址为："<<sensorAddress;

    }


}


void Yajiaoquerendizhi::slotRestoreBtn()
{
    //还原传感器地址
    sensorAddress=1;
    ui->lineEdit_address->setText(QString::number(sensorAddress));

    //还原label显示
    for(int i=0;i<listLabel.length();i++){
        SelectLabelPaint(false,i);
    }

    //清空addressList
    addressList.clear();
}


void Yajiaoquerendizhi::slotReceviedIsnThread(State_Inode state_Inode, int)
{
    this->state_Inode=state_Inode;//保存压角时传感器的数据
    qDebug()<<"压角的数据为："<<this->state_Inode.CellState[0].isn;
    biggestAddress=biggestSensorAddr(50,0);
    ui->lineEdit_Oaddress->setText(QString::number(biggestAddress+1));
    qDebug()<<"最大的地址："<<biggestAddress+1;
}


int Yajiaoquerendizhi::biggestSensorAddr(float bigvalue, int runtype)
{
        FP32 F_temp0,F_temp1,F_temp2;
        INT8U big_sensor =0;
        INT8U i;

        if(runtype == 0){
                 F_temp1 = 1.0;
        }else{
                F_temp1=1.4;//F_temp1 = GSWeighPare.SenPara[i].cornerPara;
        }
        F_temp0 = (state_Inode.CellState[0].isn-empty_State_Inode.CellState[0].isn)*F_temp1;
        qDebug()<<"........................................";
        for(i=0;i<all_Link_Sensor_ID.number;i++){
            if(runtype == 0){
                        F_temp1 = 1.0;
             } else{
                       F_temp1=1.4; //F_temp1 = GSWeighPare.SenPara[i].cornerPara;
             }

             F_temp2 = (state_Inode.CellState[i].isn-empty_State_Inode.CellState[i].isn)*F_temp1;
             qDebug()<<i+1<<"号传感器差值："<<F_temp2;
             qDebug()<<i+1<<"号传感器当前内码："<<state_Inode.CellState[i].isn;
             qDebug()<<i+1<<"号传感器空秤时的内码："<<empty_State_Inode.CellState[i].isn;
             if(F_temp0<=F_temp2) {
                    F_temp0 = F_temp2;
                    big_sensor = i;  //取出最大变化量的那个传感器
             }else {
                    big_sensor = big_sensor;
             }
         }
        qDebug()<<"........................................";

        if(qAbs(F_temp0)<bigvalue){
                big_sensor = 50;
        }

        return big_sensor;

}


int Yajiaoquerendizhi::confirmBtn()
{
    //判断该传感器是否设置过
    int flag=0;//用于判断角位是否确认过
    for(int i=0;i<addressList.length();i++){
        if(biggestAddress+1==addressList[i].toInt()){
            flag=1;
            qDebug()<<"3333333333333333333333333333333333333333333";
        }
    }


    if(flag==0){

        //设置地址和id号
        set_Address_Sensor.address[sensorAddress-1]=biggestAddress+1;

        //确定该地址对应的id号,遍历原先的设置地址与id号信息
        for(int i=0;i<all_Link_Sensor_ID.number;i++){
            if(Ori_set_Address_Sensor.address[i]==(biggestAddress+1)){
                set_Address_Sensor.ID[sensorAddress-1]=Ori_set_Address_Sensor.ID[i];
            }
        }

        //将该角位地址加入到List列表中
        addressList.append(QString::number(biggestAddress+1));

       //确定勾选地址并绘出边框
       SelectLabelPaint(true,sensorAddress-1);

       //移到下一个待确认的地址并且显示
       sensorAddress++;
       ui->lineEdit_address->setText(QString::number(sensorAddress));
       qDebug()<<"---------------------------------------------------确认的地址为："<<sensorAddress-1;
    }else{
        QMessageBox::information(NULL,"温馨提示","该角位已经确认过。",QMessageBox::Yes);
    }

    return flag;
}
