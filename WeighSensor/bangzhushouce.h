#ifndef BANGZHUSHOUCE_H
#define BANGZHUSHOUCE_H

#include <QWidget>
#include <poppler-qt4.h>
#include "lib/documentwidget.h"

namespace Ui {
class Bangzhushouce;
}

class Bangzhushouce : public QWidget
{
    Q_OBJECT
    
public:
    explicit Bangzhushouce(QWidget *parent = 0);
    ~Bangzhushouce();

public:
    Poppler::Document *doc;
    
private:
    Ui::Bangzhushouce *ui;
    DocumentWidget *documentWidget;

private:
    QString PDFpath;// pdf de lujing
    int currentPage;

public slots:
    void returnIndex();//主页
    void returnPage();//返回上一页
    void showNext();//zhun bei diao yong fa song xia yi ye  xin hao
    void showPreview();//显示preview页面

signals:
    void pageChanged(int currentPage); //fan ye xin hao
};

#endif // BANGZHUSHOUCE_H
