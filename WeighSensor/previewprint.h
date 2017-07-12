#ifndef PREVIEWPRINT_H
#define PREVIEWPRINT_H

#include <QWidget>
#include <QPrintPreviewWidget>
#include<QPrinter>

namespace Ui {
class previewPrint;
}

class previewPrint : public QWidget
{
    Q_OBJECT
    
public:
    explicit previewPrint(QWidget *parent = 0);
    ~previewPrint();
    
private:
    Ui::previewPrint *ui;

    QPrintPreviewWidget *preview;
    QPrinter *printer;

public slots:
    void slotprint(QPrinter *printer);
    void slotClose();
};

#endif // PREVIEWPRINT_H
