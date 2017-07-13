#ifndef TESTPREVIEWDIALOGSETUP_H
#define TESTPREVIEWDIALOGSETUP_H

#include <QDialog>

namespace Ui {
class testPreviewDialogSetup;
}

class testPreviewDialogSetup : public QDialog
{
    Q_OBJECT
    
public:
    explicit testPreviewDialogSetup(QWidget *parent = 0);
    ~testPreviewDialogSetup();
    
private:
    Ui::testPreviewDialogSetup *ui;
};

#endif // TESTPREVIEWDIALOGSETUP_H
