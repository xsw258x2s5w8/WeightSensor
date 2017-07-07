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
    QPainter painter;
    if(!painter.begin(printer)) {
        qWarning() << "can't start printer";
        return;
    }
    // print table
    TablePrinter tablePrinter(&painter, printer);
    QVector<int> columnStretch = QVector<int>() << 5 << 5 << 10 << 15;
    QVector<QString> headers = QVector<QString>() << "Header1" << "Header 2" << "Header 3" << "Header 4";
    if(!tablePrinter.printTable(model, columnStretch,headers)) {
        qDebug() << tablePrinter.lastError();
    }
    painter.end();
}


