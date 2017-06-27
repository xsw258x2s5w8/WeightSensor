#include "index.h"
#include "ui_index.h"
#include "page2.h"

Index::Index(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Index)
{
    ui->setupUi(this);
    connect(ui->menu,SIGNAL(clicked()),this,SLOT(showMenuWidget()));
}

Index::~Index()
{
    delete ui;
}

void Index::showMenuWidget()
{
    page2 *menu=new page2();
    menu->show(); //open menu Widget
    this->close();  //close parent Widget
}
