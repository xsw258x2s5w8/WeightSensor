#include "erciguobang.h"
#include "ui_erciguobang.h"
#include "index.h"
#include "index.h"
#include<QDebug>
#include "qrcodewidget.h"
#include <QMessageBox>

Erciguobang::Erciguobang(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Erciguobang)
{
    ui->setupUi(this);
 //   this->setWindowState(Qt::WindowFullScreen);

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

void Erciguobang::setcarWeight(QString data)
{
   carWeight=data.toFloat();
   //ui->currentTime->setText(data);
}

void Erciguobang::showData(QStringList strList)
{
    /*
     判断是否是第一次过磅
     如果是第一次过磅‘’‘ 直接显示
     如果是二次过磅’‘’ 读数据库 再显示
    */
    QDateTime time = QDateTime::currentDateTime();//获取系统现在的时间
    QString str = time.toString("yyyy-MM-dd hh:mm:ss"); //设置显示格式
    ui->currentTime->setText(str); //显示当前时间



    showLineEdit();

    int id1=weight->isComplete(strList[0]);//根据车号查，如果为空返回-1，否则返回字段号

    //过磅第第二次
    WeightRecords weightRecords;
    if(id1!=-1){
       //获取上次第一过磅的时间
       weightRecords = weight->selectWR(id1);
       QString strLast=weightRecords.getDate1()+weightRecords.getTime1();
       ui->lastTime->setText(strLast);

       ui->lineEdit_car->setText(weightRecords.getCarId());
       ui->lineEdit_art->setText(weightRecords.getArtId());

       //为动态生成的编辑框直接调用数据库的值
       chooseGetWRecrods(&weightRecords);

    //过磅第一次
    }else{
        ui->lineEdit_car->setText(strList[0]);
        ui->lineEdit_art->setText(strList[1]);

        for(int i=0;i<listLedit.length();i++){
            qDebug()<<strList[i+2];
            listLedit[i]->setText(strList[i+2]);
        }
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
    }else{
        ui->lastTime->setText("");
    }
}

void Erciguobang::getArtData(QString data)
{
    ui->lineEdit_art->setText(data);
}


void Erciguobang::checkOkbtn()
{
   /*
     判断是否是一次过磅
     如果第一次过磅'''直接插入数据库
     如果是第二次过磅 ‘’‘ 更新数据库
   */

    WeightRecords weightRecords;

    int id1=weight->isComplete(ui->lineEdit_car->text());

    //****************************************二次过磅中的第二次*************************************
    if(id1!=-1){
        //weightRecords.setId(id1);
        WeightRecords test = weight->selectWR(id1);

        //过磅完成
        test.setComplete(1);//表明二次过磅已完成


        test.setDate2(ui->currentTime->text().mid(0,10));
        test.setTime2(ui->currentTime->text().mid(10,18));

        //确定毛重，皮重，净重
        float spareWeight=test.getSpareWeight();
        if(spareWeight>carWeight){
           test.setGrossWeight(spareWeight);
           test.setTare(carWeight);
           test.setNetWeight(spareWeight-carWeight);
        }else{
           test.setGrossWeight(carWeight);
           test.setTare(spareWeight);
           test.setNetWeight(carWeight-spareWeight);
        }

        //更新数据库
        weight->updateWeightRecords(test);


        QRCodeWidget *qrcode = new QRCodeWidget(ui->lineEdit_car->text());
        qrcode->show();

        //判断是否要生成二维码
//        if(){
//          //弹到二维码界面，再那个界面再选择打印
//        }else{
//          //直接打印
//        }
//         this->close();
        qDebug()<<"更新成功 并要打印";

    //****************************************二次过磅中的第一次插入*************************************
    }else{
        weightRecords.setComplete(0);           //用于判断二次过磅是否完整
        weightRecords.setPonderation(2);        //用于判断是属于二次过磅还是一次过磅
        weightRecords.setCarId(ui->lineEdit_car->text());
        weightRecords.setArtId(ui->lineEdit_art->text());

        weightRecords.setSpareWeight(carWeight);  //第一次称出来的重量存放再临时重量字段中
        weightRecords.setDate1(ui->currentTime->text().mid(0,10));
        weightRecords.setTime1(ui->currentTime->text().mid(10,18));

        //为动态生成的字段编辑框插入数据
        chooseInsertWRecrods(&weightRecords);

        weight->insertWeightRecords(weightRecords);
        qDebug()<<"插入成功 erciguobang页面";
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
        QMessageBox::information(NULL, "提醒", "该车辆是第一次过磅，请按确认按键", QMessageBox::Yes);
        qDebug()<<"点击替换失败";
    }
}

void Erciguobang::returnIndex()
{
//    Index *menu=new Index();
//    menu->show();
    this->close();
}

void Erciguobang::returnPage()
{
//    Index *menu=new Index();
//    menu->show();
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


void Erciguobang::showLineEdit()
{
    //先获取临时表中的字段
    QList<MainInterfaceTemp> maininterfaceTemplist=maininterfacetempimpl.selectMainInterfaceTemp();

    //遍历list，序号从3 开始是因为前面三条是固定下来的
    for(int i=3;i<maininterfaceTemplist.length();i++){
       MainInterfaceTemp temp;
       temp=maininterfaceTemplist.at(i);


       //创建部件
       QLabel *label=new QLabel(temp.getOtherName()+":");
       QLineEdit *lineEdit=new QLineEdit();
       lineEdit->setObjectName(temp.getPara());

       QHBoxLayout *pHLayout=new QHBoxLayout();
       pHLayout->addWidget(label,3,Qt::AlignRight);
       pHLayout->addWidget(lineEdit,3);
       pHLayout->addStretch(1);


       ui->verticalLayout_3->addLayout(pHLayout);

       //添加
       listLedit.append(lineEdit);
    }
}


void Erciguobang::chooseGetWRecrods(WeightRecords *weightRecords)
{
    //需要设置的数据字段
    for(int i=0;i<listLedit.length();i++){

       //根据字段类型选择获取数据
       if(listLedit[i]->objectName()=="remark"){
            listLedit[i]->setText(weightRecords->getRemark());
            qDebug()<<"remark"<<weightRecords->getRemark();

       }else if(listLedit[i]->objectName()=="factoryIn"){
            listLedit[i]->setText(weightRecords->getFactoryIn());
            qDebug()<<"facoryIn"<<weightRecords->getFactoryIn();

       }else if(listLedit[i]->objectName()=="factoryOut"){
           listLedit[i]->setText(weightRecords->getFactoryOut());
            qDebug()<<"facoryOut"<<weightRecords->getFactoryOut();

       }else if(listLedit[i]->objectName()=="deduction"){
            listLedit[i]->setText(QString::number(weightRecords->getDeduction()));
            qDebug()<<"deduction"<<weightRecords->getDeduction();

       }else if(listLedit[i]->objectName()=="reserved1"){
           listLedit[i]->setText(weightRecords->getReserved1());
            qDebug()<<"reserved1"<<weightRecords->getReserved1();

       }else if(listLedit[i]->objectName()=="reserved2"){
           listLedit[i]->setText(weightRecords->getReserved2());
            qDebug()<<"reserved2"<<weightRecords->getReserved2();

       }else if(listLedit[i]->objectName()=="reserved3"){
            listLedit[i]->setText(weightRecords->getReserved3());
            qDebug()<<"reserved3"<<weightRecords->getReserved3();

       }else if(listLedit[i]->objectName()=="reserved4"){
            listLedit[i]->setText(weightRecords->getReserved4());
            qDebug()<<"reserved4"<<weightRecords->getReserved4();
       }
    }
}


void Erciguobang::chooseInsertWRecrods(WeightRecords *weightRecords)
{
    //需要插入的数据字段
    for(int i=0;i<listLedit.length();i++){

       //根据字段类型选择获取数据
       if(listLedit[i]->objectName()=="remark"){
            weightRecords->setRemark(listLedit.at(i)->text());
            qDebug()<<"remark"<<listLedit.at(i)->text();

       }else if(listLedit[i]->objectName()=="factoryIn"){
            weightRecords->setFactoryIn(listLedit.at(i)->text());
            qDebug()<<"facoryIn"<<listLedit.at(i)->text();

       }else if(listLedit[i]->objectName()=="factoryOut"){
            weightRecords->setFactoryOut(listLedit.at(i)->text());
            qDebug()<<"facoryOut"<<listLedit.at(i)->text();

       }else if(listLedit[i]->objectName()=="deduction"){
            weightRecords->setDeduction(listLedit.at(i)->text().toFloat());
            qDebug()<<"deduction"<<listLedit.at(i)->text();

       }else if(listLedit[i]->objectName()=="reserved1"){
            weightRecords->setReserved1(listLedit.at(i)->text());
            qDebug()<<"reserved1"<<listLedit.at(i)->text();

       }else if(listLedit[i]->objectName()=="reserved2"){
            weightRecords->setReserved2(listLedit.at(i)->text());
            qDebug()<<"reserved2"<<listLedit.at(i)->text();

       }else if(listLedit[i]->objectName()=="reserved3"){
            weightRecords->setReserved3(listLedit.at(i)->text());
            qDebug()<<"reserved3"<<listLedit.at(i)->text();

       }else if(listLedit[i]->objectName()=="reserved4"){
            weightRecords->setReserved4(listLedit.at(i)->text());
            qDebug()<<"reserved4"<<listLedit.at(i)->text();
       }
    }
}
