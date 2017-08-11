#include "bangzhushouce.h"
#include "ui_bangzhushouce.h"
#include "index.h"
#include "page3.h"
#include "bangzhushouce1.h"

#include<QFileDialog>
#include<QMessageBox>

Bangzhushouce::Bangzhushouce(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Bangzhushouce)
{
    ui->setupUi(this);
    this->setWindowState(Qt::WindowFullScreen);

    connect(ui->returnIndex,SIGNAL(clicked()),this,SLOT(returnIndex()));
    connect(ui->returnPage,SIGNAL(clicked()),this,SLOT(returnPage()));
    connect(ui->next,SIGNAL(clicked()),this,SLOT(showNext()));
    connect(ui->preview,SIGNAL(clicked()),this,SLOT(showPreview()));

    //can shu chu shi hua
    currentPage=1;

    //dakai pdf
    documentWidget = new DocumentWidget();
    ui->scrollArea->setWidget(documentWidget);

    connect(this, SIGNAL(pageChanged(int)), documentWidget, SLOT(setPage(int)));

    PDFpath="/root/桌面/WeighSensor/pdf/QtCreater.pdf";
    documentWidget->setDocument(PDFpath);

}

Bangzhushouce::~Bangzhushouce()
{
    delete ui;
}

void Bangzhushouce::returnIndex()
{
//    Index *menu=new Index();
//    menu->show();
    this->close();
}

void Bangzhushouce::returnPage()
{
    Page3 *returnPage=new Page3();
    returnPage->show();
    this->close();
}

void Bangzhushouce::showNext()
{
//    Bangzhushouce1 *showNext=new Bangzhushouce1();
//    showNext->show();
    //this->close();
    currentPage+=1;
    if(currentPage>documentWidget->document()->numPages()){
        currentPage=documentWidget->document()->numPages();
    }

    emit pageChanged(currentPage);
}

void Bangzhushouce::showPreview()
{
//    Bangzhushouce1 *showNext=new Bangzhushouce1();
//    showNext->show();
    //this->close();
    currentPage-=1;
    if(currentPage<1){
        currentPage=1;
    }
    emit pageChanged(currentPage);
}
