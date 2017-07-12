#include "index.h"
#include "shipin.h"
#include "shiboqi.h"
#include <QApplication>
#include <QTranslator>

#include <QPrinter>
#include <QPrintPreviewDialog>
#include <QPainter>
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlTableModel>
#include <QTextCodec>
#include <QFont>

void initDb(){
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("exampleDb");
    if(!db.open()) {
        qWarning() << "can't open db" << db.lastError().text();
    }
    QSqlQuery query;
    query.exec("CREATE TABLE IF NOT EXISTS exampleTable(Column_0 INT, Column_1 TEXT, Column_2 TEXT, Column_3 TEXT);");
    query.exec("DELETE FROM exampleTable;");
    QSqlDatabase::database().transaction();
    for(int i = 1; i < 20; i++) {
        query.exec(QString("INSERT INTO exampleTable VALUES (%1, '%2', '%3', '%4');")
                   .arg(i).arg("text in column 1").arg("text in column 2").arg("text in column 3"));
    }
    query.exec(QString("INSERT INTO exampleTable VALUES(%1, '%2', '%3', '%4');")
               .arg(20).arg("long text results in column with big height one two three four five six seven eigth nine ten")
               .arg("text in column 2").arg("text in column 3"));
    query.exec(QString("INSERT INTO exampleTable VALUES(%1, '%2', '%3', '%4');")
               .arg(21).arg("text in column 1")
               .arg("text in column 2")
               .arg("long text results in column with big height one two three four five six seven eigth nine ten"));
    for(int i = 22; i < 31; i++) {
        query.exec(QString("INSERT INTO  exampleTable VALUES(%1, '%2', '%3', '%4');")
                   .arg(i).arg("text in column 1").arg("text in column 2").arg("text in column 3"));
    }
    QSqlDatabase::database().commit();
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // 以下部分解决中文乱码
    QTextCodec *codec = QTextCodec::codecForName("utf8"); //GBK gbk
    QTextCodec::setCodecForTr(codec);
    QTextCodec::setCodecForLocale(codec);
    QTextCodec::setCodecForCStrings(codec);

    QFont font("wenquanyi",12,QFont::Bold);
    a.setFont(font);
    // 以上部分解决中文乱码



    QTranslator translator;
    //加载自定义窗口的翻译文件
    translator.load("../WeighSensor/WeighSensor.qm");
    a.installTranslator(&translator);
    //加载qt默认窗口的翻译文件
    translator.load("../WeighSensor/qt_zh_CN.qm");
    a.installTranslator(&translator);

    //模拟数据库的数据，到时候要删除掉。
    initDb();

    Index w;
    w.setWindowFlags(Qt::Window);
    w.showFullScreen();
    w.show();

//    Shipin b;
//    b.show();

//    Shiboqi c;
//    c.show();
    
    return a.exec();
}
