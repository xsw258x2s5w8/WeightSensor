#include "previewprint.h"
#include "ui_previewprint.h"

#include <QPainter>
#include <QPrintDialog>
#include <QPageSetupDialog>

#include <testpreviewdialogsetup.h>
#include<QDebug>
#include<QProcess>
#include <sys/stat.h>
#include<QDateTime>

previewPrint::previewPrint(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::previewPrint)
{
    ui->setupUi(this);
    connect(ui->close,SIGNAL(clicked()),this,SLOT(slotClose()));
    connect(ui->deflate,SIGNAL(clicked()),this,SLOT(slotZoomOut()));//缩小
    connect(ui->amplify,SIGNAL(clicked()),this,SLOT(slotZoomIn()));//放大
    connect(ui->print,SIGNAL(clicked()),this,SLOT(slotPrint()));
    connect(ui->pageSetup,SIGNAL(clicked()),this,SLOT(slotPageSetup()));



    //----------------------参数初始化-------------------------------
    // cell margins
    topDistance=0;
    bottomDistance=100;
    leftDistance=0;
    rightDistance=100;

    //联单间隔
    cellMargin=10;

    //绘画开始坐标点
    initX=10;
    initY=10;

    //每行字段之间的距离
    cellTocellDistance=50;

    //字体长寛高
    cellWidth=100;
    cellHeight=50;

    //---------------------创建预览界面------------------------
    printer = new QPrinter(QPrinter::PrinterResolution);


    preview = new QPrintPreviewWidget(printer, this);
    ui->verticalLayout->addWidget(preview);
    preview->setFont(QFont("Arial",18,QFont::Bold));
    //connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(print()));
    connect(preview, SIGNAL(paintRequested(QPrinter*)), this, SLOT(slotprint(QPrinter*)));
    preview->setZoomFactor(1);
    preview->show();
}

previewPrint::~previewPrint()
{
    delete ui;
}

void previewPrint::rePaint()
{
    QVector<QString> headers = QVector<QString>() << "number"<<" DATE1" <<"TIME1"<<"DATE2"<< "TIME2" << "VEHCLE NO " << "GROSS"<<"TARE";
    QVector<QString> bodys = QVector<QString>() <<"0001"<< "2017-6-12"<<" 22：54" <<"2017-6-12"<<"22：54"<< "浙B88888 " << "GROSS"<<"TARE";
    QPainter painter;

    painter.begin(printer);
    //painter.setRenderHints(QPainter::Antialiasing | QPainter::TextAntialiasing | QPainter::SmoothPixmapTransform, true);

    int i;
    int m=0;
    int height=50;//字段属性的上下间隔
    int width=100;  //联的宽度
    for(i=0;i<headers.count();i++){
        //QRect rec(leftMargin, topMargin, columnWidth[i] - rightMargin - leftMargin, maxHeight);
        QRect rec(initX-leftDistance+rightDistance, initY+m-topDistance+bottomDistance, cellWidth, cellHeight);
        painter.drawText(rec, Qt::AlignLeft | Qt::TextWordWrap, headers[i]);

        QRect rec1(initX+cellWidth+cellMargin+initX-leftDistance+rightDistance, initY+m-topDistance+bottomDistance, cellWidth, cellHeight);
        painter.drawText(rec1, Qt::AlignLeft | Qt::TextWordWrap, bodys[i]);

        m+=cellTocellDistance;
    }

   //if() 绘画新的一页
    //printer->newPage();



    painter.end();
}





void previewPrint::slotprint(QPrinter *)
{
//    QPainter p(printer);
//        p.setRenderHints(QPainter::Antialiasing | QPainter::TextAntialiasing | QPainter::SmoothPixmapTransform, true);


//        for (int page = 0; page < 2; page++)
//        {
//            p.drawText(200, 200, QString("Date:"));//.arg(QDateTime::currentDateTime().toString("dd.MM.yyyy")));


//            //p.fillRect(QRect(150,150,2179,125),QBrush(QColor(222,222,230,255)));
//            printer->newPage();
//        }

        //----------------------绘图----------------------------------------------------------
        rePaint();
}

void previewPrint::slotClose()
{
    this->close();
}

void previewPrint::slotZoomIn()
{
    preview->zoomIn();
}

void previewPrint::slotZoomOut()
{
    preview->zoomOut();
}

void previewPrint::slotPrint()
{


    //QPrintDialog dlg(printer);

    //printer->setPrinterName("usblp0");
    //printer->setPrintProgram("foo2zjs");
    printer->setOutputFormat(QPrinter::PostScriptFormat);
    printer->setOutputFileName("/opt/qt4.8.5/demos/chess.ps");

    sleep(5);
    QDateTime time = QDateTime::currentDateTime();//获取系统现在的时间
    QString str = time.toString("yyyy-MM-dd hh:mm:ss ddd"); //设置显示格式
    qDebug()<<"shengcheng ok:"<<str;

    QProcess::execute("gs -q -dBATCH -dSAFER -dQUIET -dNOPAUSE -sPAPERSIZE=a4 -r600x600 -sDEVICE=pbmraw -sOutputFile=/opt/qt4.8.5/demos/test_1.pbm /opt/qt4.8.5/demos/chess.ps");
    time = QDateTime::currentDateTime();//获取系统现在的时间
    QString str1=time.toString("yyyy-MM-dd hh:mm:ss ddd"); //设置显示格式
    qDebug()<<"zhuanhuan ok"<<str1;
    sleep(10);
    QProcess::execute("foo2zjs -z1 -p9 -r600x600 test_1.pbm > /dev/usb/lp0");
   // if(dlgw.exec()==QDialog::Accepted){


    preview->print();
    //}
}

void previewPrint::slotPageSetup()
{
//   // preview->close();
//     bottomDistance=400;
//    preview = new QPrintPreviewWidget(printer, this);
//    ui->verticalLayout->addWidget(preview);
//    preview->setFont(QFont("Arial",18,QFont::Bold));
//    //connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(print()));
//    //connect(preview, SIGNAL(paintRequested(QPrinter*)), this, SLOT(slotprint(QPrinter*)));

//    //rePaint();
//    preview->setZoomFactor(1);
//    preview->show();
    QPageSetupDialog pageSetup(printer);
    if (pageSetup.exec() == QDialog::Accepted) {
        // update possible orientation changes
        if (preview->orientation() == QPrinter::Portrait) {
            preview->setPortraitOrientation();
        }else {
            preview->setLandscapeOrientation();
        }
    }
//    bottomDistance=200;
//    rePaint(printer);
//    testPreviewDialogSetup *p=new testPreviewDialogSetup();
//    if(p->exec()){
//        bottomDistance=200;
//        rePaint(printer);
//    }
}

void previewPrint::slotSetup()
{

}

void previewPrint::setTopDistance(int topDistance)
{
    this->topDistance=topDistance;
}

void previewPrint::setBottomDistance(int bottomDistance)
{
    this->bottomDistance=bottomDistance;
}

void previewPrint::setLeftDistance(int leftDistance)
{
    this->leftDistance=leftDistance;
}

void previewPrint::setRightDistance(int rightDistance)
{
    this->rightDistance=rightDistance;
}

void previewPrint::setCellMargin(int cellMargin)
{
    this->cellMargin=cellMargin;
}

void previewPrint::setInitX(int initX)
{
    this->initX=initX;
}

void previewPrint::setInitY(int initY)
{
    this->initY=initY;
}

void previewPrint::setCellTocellDistance(int cellTocellDistance)
{
    this->cellTocellDistance=cellTocellDistance;
}

void previewPrint::setCellWidth(int cellWidth)
{
    this->cellWidth=cellWidth;
}

void previewPrint::setCellHeight(int cellHeight)
{
    this->cellHeight=cellHeight;
}

void previewPrint::updatePre()
{
    preview->updatePreview();
}


