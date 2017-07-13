#include "testpreviewdialogsetup.h"
#include "ui_testpreviewdialogsetup.h"

testPreviewDialogSetup::testPreviewDialogSetup(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::testPreviewDialogSetup)
{
    ui->setupUi(this);
}

testPreviewDialogSetup::~testPreviewDialogSetup()
{
    delete ui;
}
