#include "wanzheng_chaxun.h"
#include "ui_wanzheng_chaxun.h"
#include "wanzheng.h"
#include "index.h"

#include "lib/tableprinter.h"

#include <QPrinter>
#include <QPrintPreviewDialog>
#include <QPainter>
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlTableModel>
#include<QTextDocument>

Wanzheng_chaxun::Wanzheng_chaxun(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Wanzheng_chaxun)
{
    ui->setupUi(this);
  /***********************模拟的数据**************************/
  //  initDb();
    model = new QSqlTableModel;
    model->setTable("exampleTable");
    model->select();

    connect(ui->returnIndex,SIGNAL(clicked()),this,SLOT(returnIndex()));
    connect(ui->returnPage,SIGNAL(clicked()),this,SLOT(returnPage()));
    connect(ui->print,SIGNAL(clicked()),this,SLOT(doprintPreview()));//打印按钮的槽
}

Wanzheng_chaxun::~Wanzheng_chaxun()
{
    delete ui;
}

//void Wanzheng_chaxun::initDb()
//{
//        QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
//        db.setDatabaseName("exampleDb");
//        if(!db.open()) {
//            qWarning() << "can't open db" << db.lastError().text();
//        }
//        QSqlQuery query;
//        query.exec("CREATE TABLE IF NOT EXISTS exampleTable(Column_0 INT, Column_1 TEXT, Column_2 TEXT, Column_3 TEXT);");
//        query.exec("DELETE FROM exampleTable;");
//        QSqlDatabase::database().transaction();
//        for(int i = 1; i < 20; i++) {
//            query.exec(QString("INSERT INTO exampleTable VALUES (%1, '%2', '%3', '%4');")
//                       .arg(i).arg("text in column 1").arg("text in column 2").arg("text in column 3"));
//        }
//        query.exec(QString("INSERT INTO exampleTable VALUES(%1, '%2', '%3', '%4');")
//                   .arg(20).arg("long text results in column with big height one two three four five six seven eigth nine ten")
//                   .arg("text in column 2").arg("text in column 3"));
//        query.exec(QString("INSERT INTO exampleTable VALUES(%1, '%2', '%3', '%4');")
//                   .arg(21).arg("text in column 1")
//                   .arg("text in column 2")
//                   .arg("long text results in column with big height one two three four five six seven eigth nine ten"));
//        for(int i = 22; i < 31; i++) {
//            query.exec(QString("INSERT INTO  exampleTable VALUES(%1, '%2', '%3', '%4');")
//                       .arg(i).arg("text in column 1").arg("text in column 2").arg("text in column 3"));
//        }
//        QSqlDatabase::database().commit();
//}

void Wanzheng_chaxun::returnIndex()
{
    Index *menu=new Index();
    menu->show();
    this->close();
}

void Wanzheng_chaxun::returnPage()
{
    Wanzheng *returnPage=new Wanzheng();
    returnPage->show();
    this->close();
}

void Wanzheng_chaxun::doprintPreview()
{
    QPrintPreviewDialog dialog;
    connect(&dialog, SIGNAL(paintRequested(QPrinter*)), this, SLOT(printPreview(QPrinter*)));
    dialog.exec();
}

void Wanzheng_chaxun::printPreview(QPrinter *printer)
{
    //------------------------------------绘图法打印（该方法可以自定义）-------------------------------
//    QPainter painter;
//    if(!painter.begin(printer)) {
//        qWarning() << "can't start printer";
//        return;
//    }
//    // print table
//    TablePrinter tablePrinter(&painter, printer);

//    //设置header和conent字体
//    QFont font1; // font for header
//    font1.setBold(true);
//    font1.setPointSize(20);
//    tablePrinter.setHeadersFont(font1);
//    QFont font2; // font for content
//    font2.setItalic(true);
//    font2.setPointSize(15);
//    tablePrinter.setHeadersFont(font2);

//    //header和content颜色
//    tablePrinter.setHeaderColor(Qt::red);
//    tablePrinter.setContentColor(Qt::blue);

//    //显示每列的比例大小
//    QVector<int> columnStretch = QVector<int>() << 5 << 5 << 10 << 15;

//    //表头属性
//    QVector<QString> headers = QVector<QString>() << "Header 1" << "Header 2" << "Header 3" << "Header 4";

//    //执行打印
//    if(!tablePrinter.printTable(model, columnStretch,headers)) {
//        qDebug() << tablePrinter.lastError();
//    }
//    painter.end();

   //-----------------------------直接打印整个界面的方法-------------------------------
    //    QPainter painter;
    //    painter.begin(printer);
    //    double xscale = printer->pageRect().width()/double(ui->widget->width());
    //    double yscale = printer->pageRect().height()/double(ui->widget->height());
    //    double scale = qMin(xscale, yscale);
    //    painter.translate(printer->paperRect().x() + printer->pageRect().width()/2,
    //                       printer->paperRect().y() + printer->pageRect().height()/2);
    //    painter.scale(scale, scale);
    //    painter.translate(-width()/2, -height()/2);

    //   ui->widget->render(&painter);

    //-------------------------------用html格式来打印表格界面------------------------------
    QString html;
    QString html_table1;
    QString html_table2;
    QString html_body;
    QVector<QString> headers = QVector<QString>() << "number"<<" DATE1" <<"TIME1"<<"DATE2"<< "TIME2" << "VEHCLE NO " << "GROSS"<<"TARE";
    QVector<QString> bodys = QVector<QString>() <<"0001"<< "2017-6-12"<<" 22：54" <<"2017-6-12"<<"22：54"<< "浙B88888 " << "GROSS"<<"TARE";
    QString title = headers[0];
    QString body = headers[1];
//    html = "<table width='100%/' border=1 cellspacing=0>"
//                    "<tr><td bgcolor='lightgray'><font size='+1'>"
//                    "<b><i>" + title + "</i></b></font><tr><td>" + body
//                    + "</table><br>";

    int i=0;
    html_table1="<table width='100%' border=1 cellspacing=0>";
    html_table2="</table>";
    for(i=0;i<headers.count();i=i+2){
        html_body+=
                "<tr>"
                    "<td>"+Qt::escape(headers[i])+"</td><td>"+Qt::escape(bodys[i])+"</td><td>"+headers[i+1]+"</td><td>"+bodys[i+1]+"</td>"
                "</tr>";
    }
    html=html_table1+html_body+html_table2;


    //QPainter painter(printer);
    QTextDocument textDocument;
    textDocument.setHtml(html);
    textDocument.print(printer);
}


