#include "previewprint.h"
#include "ui_previewprint.h"

#include <QPainter>

previewPrint::previewPrint(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::previewPrint)
{
    ui->setupUi(this);
    connect(ui->close,SIGNAL(clicked()),this,SLOT(slotClose()));


    printer = new QPrinter(QPrinter::PrinterResolution);
    printer->setOutputFormat(QPrinter::PdfFormat);
    printer->setOutputFileName("sample.pdf");
    printer->setPaperSize(QPrinter::A4);
    printer->setFullPage(true);
    printer->setResolution(300);

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


void previewPrint::slotprint(QPrinter *printer)
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

        QVector<QString> headers = QVector<QString>() << "number"<<" DATE1" <<"TIME1"<<"DATE2"<< "TIME2" << "VEHCLE NO " << "GROSS"<<"TARE";
        QVector<QString> bodys = QVector<QString>() <<"0001"<< "2017-6-12"<<" 22：54" <<"2017-6-12"<<"22：54"<< "浙B88888 " << "GROSS"<<"TARE";
        QPainter painter;

        painter.begin(printer);
        //painter.setRenderHints(QPainter::Antialiasing | QPainter::TextAntialiasing | QPainter::SmoothPixmapTransform, true);

        int i;
        int m=0;
        int height=50;//字段属性的上下间隔
        int width=500;  //联的宽度
        for(i=0;i<headers.count();i++){
            //QRect rec(leftMargin, topMargin, columnWidth[i] - rightMargin - leftMargin, maxHeight);
            QRect rec(10, 10+m, 200, 50);
            painter.drawText(rec, Qt::AlignLeft | Qt::TextWordWrap, headers[i]);

            QRect rec1(100+width, 10+m, 200, 50);
            painter.drawText(rec1, Qt::AlignLeft | Qt::TextWordWrap, bodys[i]);

            m=m+height;
        }

        printer->newPage();
        for(i=0;i<headers.count();i++){
            //QRect rec(leftMargin, topMargin, columnWidth[i] - rightMargin - leftMargin, maxHeight);
            QRect rec2(10, 100+m, 200, 50);
            painter.drawText(rec2, Qt::AlignLeft | Qt::TextWordWrap, headers[i]);

            QRect rec13(100+width+200, 100+m, 200, 50);
            painter.drawText(rec13, Qt::AlignLeft | Qt::TextWordWrap, bodys[i]);

            m=m+height;
        }

        printer->newPage();
        for(i=0;i<headers.count();i++){
            //QRect rec(leftMargin, topMargin, columnWidth[i] - rightMargin - leftMargin, maxHeight);
            QRect rec2(10, 100+m, 200, 50);
            painter.drawText(rec2, Qt::AlignLeft | Qt::TextWordWrap, headers[i]);

            QRect rec13(100+width+200, 100+m, 200, 50);
            painter.drawText(rec13, Qt::AlignLeft | Qt::TextWordWrap, bodys[i]);

            m=m+height;
        }


        painter.end();
}

void previewPrint::slotClose()
{
    this->close();
}
