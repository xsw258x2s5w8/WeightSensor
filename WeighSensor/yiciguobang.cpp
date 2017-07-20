#include "yiciguobang.h"
#include "ui_yiciguobang.h"
#include "index.h"
#include "index.h"

Yiciguobang::Yiciguobang(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Yiciguobang)
{
    ui->setupUi(this);

    //参数初始化
    carWeight=0;
    carTare=0;
    carMemoryTare=0;

    //数据库接口
    weight=new WeightRecordsImpl();
    qDebug()<<"car 数据库打开：";
    car=new CarIdManagementImpl();
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
    //    if()判断是否是第一次过磅
        //如果是第一次过磅‘’‘ 直接显示
        //如果是二次过磅’‘’ 读数据库 再显示
       // car=new CarIdManagementImpl();

        QDateTime time = QDateTime::currentDateTime();//获取系统现在的时间
        QString str = time.toString("yyyy-MM-dd hh:mm:ss"); //设置显示格式
        ui->currentTime->setText(str); //显示当前时间

        ui->lineEdit_carId->setText(strList[0]);
        ui->lineEdit_artId->setText(strList[1]);
        ui->lineEdit_remark->setText(strList[2]);

        float id1=car->selectDataByCarId(strList[0]);//查表看是否有预先设置的皮重

        if(carTare!=0){  //有预设皮重的时候
            ui->label_tare->setText("");
        }else if(carTare==0&&id1!=-1){

                   ui->label_tare->setText(QString::number(id1));
                   carMemoryTare=id1;

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
    Index *menu=new Index();
    menu->show();
    this->close();
}

void Yiciguobang::returnPage()
{
    Index *menu=new Index();
    menu->show();
    this->close();
}

void Yiciguobang::showOkBtn()
{
    //    if(){ //判断是否是一次过磅
                //如果第一次过磅'''直接插入数据库
                //如果是第二次过磅 ‘’‘ 更新数据库

        //    }

        WeightRecords weightRecords;
        if(carTare!=0){
            weightRecords.setComplete(0);           //用于判断二次过磅是否完整
            weightRecords.setPonderation(1);        //用于判断是属于二次过磅还是一次过磅
            weightRecords.setCarId(ui->lineEdit_carId->text());
            weightRecords.setArtId(ui->lineEdit_artId->text());
            weightRecords.setRemark(ui->lineEdit_remark->text());
            weightRecords.setGrossWeight(carWeight+carTare);  //毛重
            weightRecords.setTare(carTare);
            weightRecords.setNetWeight(carWeight);
            weightRecords.setDate1(ui->currentTime->text().mid(0,10));
            weightRecords.setTime1(ui->currentTime->text().mid(10,18));

            weight->insertWeightRecords(weightRecords);
            qDebug()<<"插入成功 yiciguobang 界面 与设皮重";
        }else if(carTare==0&&carMemoryTare!=0){
            weightRecords.setComplete(0);           //用于判断二次过磅是否完整
            weightRecords.setPonderation(1);        //用于判断是属于二次过磅还是一次过磅
            weightRecords.setCarId(ui->lineEdit_carId->text());
            weightRecords.setArtId(ui->lineEdit_artId->text());
            weightRecords.setRemark(ui->lineEdit_remark->text());
            weightRecords.setGrossWeight(carWeight+carMemoryTare);  //毛重
            weightRecords.setTare(carMemoryTare);
            weightRecords.setNetWeight(carWeight);
            weightRecords.setDate1(ui->currentTime->text().mid(0,10));
            weightRecords.setTime1(ui->currentTime->text().mid(10,18));

            weight->insertWeightRecords(weightRecords);
            qDebug()<<"插入成功 yiciguobang 界面 记忆皮重";
        }
        qDebug()<<"请按车辆";

}

void Yiciguobang::showCheliangBtn()
{
        WeightRecords weightRecords;

        weightRecords.setComplete(0);           //用于判断二次过磅是否完整
        weightRecords.setPonderation(1);        //用于判断是属于二次过磅还是一次过磅
        weightRecords.setCarId(ui->lineEdit_carId->text());
        weightRecords.setArtId(ui->lineEdit_artId->text());
        weightRecords.setRemark(ui->lineEdit_remark->text());
        weightRecords.setGrossWeight(carWeight);  //毛重
        weightRecords.setTare(0);
        weightRecords.setNetWeight(carWeight);
        weightRecords.setDate1(ui->currentTime->text().mid(0,10));
        weightRecords.setTime1(ui->currentTime->text().mid(10,18));

        weight->insertWeightRecords(weightRecords);
        qDebug()<<"插入成功 yiciguobang 界面 按下车辆按钮";
}
