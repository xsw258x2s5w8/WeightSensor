#include "yiciguobang.h"
#include "ui_yiciguobang.h"
#include "index.h"
#include "index.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QMessageBox>

Yiciguobang::Yiciguobang(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Yiciguobang)
{
    ui->setupUi(this);
   // this->setWindowState(Qt::WindowFullScreen);

    //参数初始化
    carWeight=0;
    carTare=0;
    carMemoryTare=0;

    //数据库接口
   // weight=new WeightRecordsImpl();
    qDebug()<<"car 数据库打开：";
  //  car=new CarIdManagementImpl();
   // maininterfacetempimpl=new MainInterfaceTempImpl();
    //weight=new WeightRecordsImpl();

    //按钮槽
    connect(ui->returnIndex,SIGNAL(clicked()),this,SLOT(returnIndex()));
    connect(ui->returnPage,SIGNAL(clicked()),this,SLOT(returnPage()));
    connect(ui->okBtn,SIGNAL(clicked()),this,SLOT(showOkBtn()));
    connect(ui->cheliangBtn,SIGNAL(clicked()),this,SLOT(showCheliangBtn()));
}

Yiciguobang::~Yiciguobang()
{
    delete ui;
}

void Yiciguobang::showData(QStringList strList)
{
    /*
        一次过磅：1.预设皮重
                2.记忆皮重
                3.车辆按钮

    */

        //显示时间
        QDateTime time = QDateTime::currentDateTime();//获取系统现在的时间
        QString str = time.toString("yyyy-MM-dd hh:mm:ss"); //设置显示格式
        ui->currentTime->setText(str); //显示当前时间

        //创建部件,并显示部件
        showLineEdit();

        //给相应的控件显示数据
        ui->lineEdit_carId->setText(strList[0]);
        ui->lineEdit_artId->setText(strList[1]);
        for(int i=0;i<listLedit.length();i++){
            listLedit[i]->setText(strList[i+2]);
        }


        //查表看是否有预先设置的 记忆皮重
        carMemoryTare=car.selectDataByCarId(strList[0]);

        if(carTare!=0){  //有预设皮重的时候（皮重框里输入了值）
            ui->label_tare->setText("");
        }else if(carTare==0&&carMemoryTare!=-1){  //没有预设皮重，并且有记忆皮重

            ui->label_tare->setText(QString::number(carMemoryTare));

        }

        qDebug()<<"carMemoryTare:"<<carMemoryTare;
        qDebug()<<"carWeight:"<<carWeight;
        qDebug()<<"carTare:"<<carTare;

}

void Yiciguobang::setCarWeight(QString data)
{
    carWeight=data.toFloat();

}

void Yiciguobang::setCarTare(QString data)
{
    carTare=data.toFloat();
}

void Yiciguobang::returnIndex()
{
//    Index *menu=new Index();
//    menu->show();
    this->close();
}

void Yiciguobang::returnPage()
{
//    Index *menu=new Index();
//    menu->show();
    this->close();
}

void Yiciguobang::showOkBtn()
{

    WeightRecords weightRecords;

    weightRecords.setComplete(0);           //用于判断二次过磅是否完整
    weightRecords.setPonderation(1);        //用于判断是属于二次过磅还是一次过磅
    weightRecords.setCarId(ui->lineEdit_carId->text());
    weightRecords.setArtId(ui->lineEdit_artId->text());
    weightRecords.setRemark(ui->lineEdit_remark->text());
    weightRecords.setDate1(ui->currentTime->text().mid(0,10));
    weightRecords.setTime1(ui->currentTime->text().mid(10,18));

    chooseWRecrods(&weightRecords);//选择插入动态生成编辑框的字段

    //有预设皮重
    if(carTare!=0){
            weightRecords.setGrossWeight(carWeight+carTare);  //有预设皮重下 毛重=传过来秤台重量+皮重
            weightRecords.setTare(carTare);
            weightRecords.setNetWeight(carWeight);

            weight.insertWeightRecords(weightRecords);//插入数据库
            qDebug()<<"插入成功 yiciguobang 界面 预设皮重";

            //二维码
             QRCodeWidget *qrcode = new QRCodeWidget(ui->lineEdit_carId->text());
             qrcode->show();

    //无预设皮重，并且有记忆皮重
    }else if(carTare==0&&carMemoryTare!=-1){
            weightRecords.setGrossWeight(carWeight);  //有记忆皮重的情况下，毛重  等于传过来的秤台重量
            weightRecords.setTare(carMemoryTare);
            weightRecords.setNetWeight(carWeight-carMemoryTare);//净重为传过来-记忆皮重

            weight.insertWeightRecords(weightRecords);//插入数据库
            qDebug()<<"插入成功 yiciguobang 界面 记忆皮重";

            //二维码
             QRCodeWidget *qrcode = new QRCodeWidget(ui->lineEdit_carId->text());
             qrcode->show();

    //无预设皮重，也无记忆皮重
    }else{

        QMessageBox::information(NULL, "提醒", "该车辆既无预设皮重，也无记忆皮重。请按车辆或者返回", QMessageBox::Yes);
        qDebug()<<"请按车辆";
    }


    //判断是否要生成二维码
//        if(){
//          //弹到二维码界面，再那个界面再选择打印
//        }else{
//          //直接打印
//        }

}

void Yiciguobang::showCheliangBtn()
{
        WeightRecords weightRecords;

        weightRecords.setComplete(0);           //用于判断二次过磅是否完整
        weightRecords.setPonderation(1);        //用于判断是属于二次过磅还是一次过磅
        weightRecords.setCarId(ui->lineEdit_carId->text());
        weightRecords.setArtId(ui->lineEdit_artId->text());
        weightRecords.setRemark(ui->lineEdit_remark->text());
        weightRecords.setGrossWeight(carWeight+carTare);  //毛重 预设皮重+称出重量
        weightRecords.setTare(0);
        weightRecords.setNetWeight(carWeight+carTare);    //一次过磅 等于毛重
        weightRecords.setDate1(ui->currentTime->text().mid(0,10));
        weightRecords.setTime1(ui->currentTime->text().mid(10,18));

        chooseWRecrods(&weightRecords);//选择插入动态生成编辑框的字段

        weight.insertWeightRecords(weightRecords);
        qDebug()<<"插入成功 yiciguobang 界面 按下车辆按钮";

        QRCodeWidget *qrcode = new QRCodeWidget(ui->lineEdit_carId->text());
        qrcode->show();

        //判断是否要生成二维码
//        if(){
//          //弹到二维码界面，再那个界面再选择打印
//        }else{
//          //直接打印
//        }
}


void Yiciguobang::showLineEdit()
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
       pHLayout->addWidget(label,1,Qt::AlignRight);
       pHLayout->addWidget(lineEdit,1);

       ui->verticalLayout_3->addLayout(pHLayout);

       //添加
       listLedit.append(lineEdit);
    }

}


void Yiciguobang::chooseWRecrods(WeightRecords *weightRecords)
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
