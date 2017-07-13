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

signals:
    void SignalsendString(QStringList strList);

public slots:
    void sendOK();
};

#endif // TESTPREVIEWDIALOGSETUP_H
