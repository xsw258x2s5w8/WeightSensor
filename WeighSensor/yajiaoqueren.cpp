#include "yajiaoqueren.h"
#include "ui_yajiaoqueren.h"
#include "index.h"
#include "zidongtiaojiaocha.h"

Yajiaoqueren::Yajiaoqueren(State_Inode empty_State_Inode,float emptyCurrentAllISN,int sensorNumber,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Yajiaoqueren)
{
    ui->setupUi(this);
    //this->setWindowState(Qt::WindowFullScreen);
    this->setAttribute(Qt::WA_DeleteOnClose);//为了关闭子窗口后能够调用析构函数

    //获得从空秤界面传过来的数据
    this->empty_State_Inode=empty_State_Inode;
    this->emptyCurrentAllISN=emptyCurrentAllISN;
    this->sensorNumber=sensorNumber;

    //根据传感器数量生成label
    GenerateLabels(sensorNumber);

    //开启读内码  的线程；
    sensorIsnThread.SetSensorNumber(sensorNumber);//为了配置启动常规采集命令的信息
    sensorIsnThread.start();
    steedyThread.start();

    //读取内码线程与 判断稳定线程的槽连接
    connect(&sensorIsnThread,SIGNAL(SendISN(State_Inode,int)),&steedyThread,SLOT(slotGetISN(State_Inode,int)));


    //判断稳定的线程与界面的槽连接
    connect(&steedyThread,SIGNAL(SendSteedyFlag(QString,float,State_Inode)),this,SLOT(slotRevceviedSteedyFlag(QString,float,State_Inode)));

    //按钮槽
    connect(ui->returnIndex,SIGNAL(clicked()),this,SLOT(returnIndex()));
    connect(ui->returnPage,SIGNAL(clicked()),this,SLOT(returnPage()));
    connect(ui->confirm,SIGNAL(clicked()),this,SLOT(slotconfirm()));
}

Yajiaoqueren::~Yajiaoqueren()
{
    sensorIsnThread.close();
    steedyThread.close();
    delete ui;
}

void Yajiaoqueren::returnIndex()
{
//    Index *menu=new Index();
//    menu->show();
    this->close();
}

void Yajiaoqueren::returnPage()
{
    Zidongtiaojiaocha *returnPage=new Zidongtiaojiaocha();
    returnPage->show();
    this->close();
}


void Yajiaoqueren::GenerateLabels(int length)
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


void Yajiaoqueren::SelectLabelPaint(bool select_label, int pos)
{
    if(select_label==true){//需要选中label  画边框
         listLabel[pos]->setStyleSheet("background-color:rgb(172, 172, 172);border-width: 2px;border-style:solid;border-color:blue;");
    }else{//取消边框
         listLabel[pos]->setStyleSheet("background-color:rgb(172, 172, 172)");
    }
}


int Yajiaoqueren::biggestSensorAddr(float bigvalue, int runtype)
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
    for(i=0;i<sensorNumber;i++){
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


void Yajiaoqueren::slotRevceviedSteedyFlag(QString str, float currentAllISN, State_Inode state_Inode)
{
    ui->label_state->setText(str);
    this->state_Inode=state_Inode;
    this->currentAllISN=currentAllISN;
    biggestAddress=biggestSensorAddr(50,0);
    ui->lineEdit_2->setText(QString::number(biggestAddress+1));
}


void Yajiaoqueren::slotconfirm()
{
    if(ui->label_state->text()=="稳定"){

        //按钮逻辑部分
        int flag=confirmBtn();

        //确认到最后一个传感器了
        if(sensorNumber==addressList.length()&&flag==0){

            //发送设地址的命令

            //保存到数据库

            //关闭本页面
            qDebug()<<"这已经是最后一个传感器了，地址为："<<biggestAddress;

        }

    }else{
        QMessageBox::information(NULL,"温馨提示","秤台不稳定，请稳定后在按确认");
    }
}


int Yajiaoqueren::confirmBtn()
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

//        //设置地址和id号
//        set_Address_Sensor.address[sensorAddress-1]=biggestAddress+1;

//        //确定该地址对应的id号,遍历原先的设置地址与id号信息
//        for(int i=0;i<all_Link_Sensor_ID.number;i++){
//            if(Ori_set_Address_Sensor.address[i]==(biggestAddress+1)){
//                set_Address_Sensor.ID[sensorAddress-1]=Ori_set_Address_Sensor.ID[i];
//            }
//        }

        //将该角位地址加入到List列表中
        addressList.append(QString::number(biggestAddress+1));

       //确定勾选地址并绘出边框
       SelectLabelPaint(true,biggestAddress);

//       //移到下一个待确认的地址并且显示
//       sensorAddress++;
//       ui->lineEdit_address->setText(QString::number(sensorAddress));
       qDebug()<<"---------------------------------------------------确认的地址为："<<biggestAddress;
    }else{
        QMessageBox::information(NULL,"温馨提示","该角位已经确认过。",QMessageBox::Yes);
    }

    return flag;
}
