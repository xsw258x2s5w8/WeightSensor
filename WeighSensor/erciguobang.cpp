#include "erciguobang.h"
#include "ui_erciguobang.h"
#include "index.h"
#include "index.h"
#include<QDebug>

Erciguobang::Erciguobang(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Erciguobang)
{
    ui->setupUi(this);

    weight=new WeightRecordsImpl();//创建数据库接口

    //自定义的信号与槽  主要用于页面之间传数据
    carid=new Erciguobang_car();
    connect(carid,SIGNAL(sendCarId(QString)),this,SLOT(getCarData(QString)));

    artid=new Erciguobang_art();
    connect(artid,SIGNAL(sendArtid(QString)),this,SLOT(getArtData(QString)));
//    connect();

    //按钮槽
    connect(ui->returnIndex,SIGNAL(clicked()),this,SLOT(returnIndex()));
    connect(ui->returnPage,SIGNAL(clicked()),this,SLOT(returnPage()));
    connect(ui->caridbtn,SIGNAL(clicked()),this,SLOT(showCarData()));
    connect(ui->artidbtn,SIGNAL(clicked()),this,SLOT(showArtData()));
    connect(ui->okbtn,SIGNAL(clicked()),this,SLOT(checkOkbtn()));
    connect(ui->replaceBtn,SIGNAL(clicked()),this,SLOT(replaceBTN()));
}

Erciguobang::~Erciguobang()
{
    delete ui;
}

void Erciguobang::getWeight(QString data)
{
   carWeight=data.toFloat();
   //ui->currentTime->setText(data);
}

void Erciguobang::showData(QStringList strList)
{
//    if()判断是否是第一次过磅
    //如果是第一次过磅‘’‘ 直接显示
    //如果是二次过磅’‘’ 读数据库 再显示

    QDateTime time = QDateTime::currentDateTime();//获取系统现在的时间
    QString str = time.toString("yyyy-MM-dd hh:mm:ss"); //设置显示格式
    ui->currentTime->setText(str); //显示当前时间

    WeightRecords weightRecords;

    int id1=weight->isComplete(strList[0]);//根据车号查
    if(id1!=-1){//属于二次过磅第二次
       //获取上次第一过磅的时间
       weightRecords = weight->selectWR(id1);
       QString strLast=weightRecords.getDate1()+weightRecords.getTime1();
       ui->lastTime->setText(strLast);

       ui->lineEdit_car->setText(weightRecords.getCarId());
       ui->lineEdit_art->setText(weightRecords.getArtId());
       ui->lineEdit_remark->setText(weightRecords.getRemark());

    }else{
        ui->lineEdit_car->setText(strList[0]);
        ui->lineEdit_art->setText(strList[1]);
        ui->lineEdit_remark->setText(strList[2]);
    }




}

void Erciguobang::getCarData(QString data)
{
    ui->lineEdit_car->setText(data);


    //
    WeightRecords weightRecords;

    int id1=weight->isComplete(ui->lineEdit_car->text());//根据车号查
    if(id1!=-1){//属于二次过磅第二次
       //获取上次第一过磅的时间
       weightRecords = weight->selectWR(id1);
       QString strLast=weightRecords.getDate1()+weightRecords.getTime1();
       ui->lastTime->setText(strLast);

       ui->lineEdit_art->setText(weightRecords.getArtId());
       ui->lineEdit_remark->setText(weightRecords.getRemark());
    }else{
        ui->lastTime->setText("");
    }
}

void Erciguobang::getArtData(QString data)
{
    ui->lineEdit_art->setText(data);
}

void Erciguobang::getRemarkData(QString data)
{
    ui->lineEdit_remark->setText(data);
}

void Erciguobang::checkOkbtn()
{
//    if(){ //判断是否是一次过磅
            //如果第一次过磅'''直接插入数据库
            //如果是第二次过磅 ‘’‘ 更新数据库

    //    }
    WeightRecords weightRecords;

    int id1=weight->isComplete(ui->lineEdit_car->text());
    if(id1!=-1){ //****************************************二次过磅中的第二次*************************************
        //weightRecords.setId(id1);
        WeightRecords test = weight->selectWR(id1);
        test.setComplete(1);//表明二次过磅已完成
        test.setTare(carWeight);     //皮重
        test.setDate2(ui->currentTime->text().mid(0,10));
        test.setTime2(ui->currentTime->text().mid(10,18));

        weight->updateWeightRecords(test);

//         this->close();
        qDebug()<<"更新成功 并要打印";
    }else{  //****************************************二次过磅中的第一次插入*************************************
        weightRecords.setComplete(0);           //用于判断二次过磅是否完整
        weightRecords.setPonderation(2);        //用于判断是属于二次过磅还是一次过磅
        weightRecords.setCarId(ui->lineEdit_car->text());
        weightRecords.setArtId(ui->lineEdit_art->text());
        weightRecords.setRemark(ui->lineEdit_remark->text());
        weightRecords.setGrossWeight(carWeight);  //毛重
        weightRecords.setDate1(ui->currentTime->text().mid(0,10));
        weightRecords.setTime1(ui->currentTime->text().mid(10,18));

        weight->insertWeightRecords(weightRecords);
        qDebug()<<"插入成功 erciguobang页面";
//        qDebug()<<ui->lineEdit_car->text();
//        qDebug()<<ui->currentTime->text().mid(0,10);
//        qDebug()<<ui->currentTime->text().mid(10,15);
    }
}

void Erciguobang::replaceBTN()
{
    //判断是否是第二次
    //如果是就允许替换'''
    int id1=weight->isComplete(ui->lineEdit_car->text());
    if(id1!=-1){
        WeightRecords test1 = weight->selectWR(id1);
        test1.setDate1(ui->currentTime->text().mid(0,10));
        test1.setTime1(ui->currentTime->text().mid(10,18));
        test1.setGrossWeight(carWeight);  //毛重

        weight->replaceLastWeightRecords(test1);
        qDebug()<<"替换上次记录成功";
    }else{
        qDebug()<<"点击替换失败";
    }
}

void Erciguobang::returnIndex()
{
    Index *menu=new Index();
    menu->show();
    this->close();
}

void Erciguobang::returnPage()
{
    Index *menu=new Index();
    menu->show();
    this->close();
}

void Erciguobang::showCarData()
{
    carid->show();
}

void Erciguobang::showArtData()
{
    artid->show();
}
