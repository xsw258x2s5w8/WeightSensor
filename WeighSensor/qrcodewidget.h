#ifndef QRCODE_H
#define QRCODE_H

#include <QWidget>
#include <QTextCodec>
extern "C" {
#include <png.h>
}
#include <QPicture>
#include "qrencode.h"
#include <QString>
#include "impl/weightrecordsimpl.h"
#include "impl/weightrecords.h"
#define INCHES_PER_METER (100.0/2.54)

namespace Ui {
class QRCode;
}

class QRCodeWidget : public QWidget
{
    Q_OBJECT

public:
    explicit QRCodeWidget(QString carId1, QWidget *parent = 0);
    ~QRCodeWidget();
	QRcode *qrcode; 
	int margin;
	int size;
	int version;
    unsigned int fg_color[4] ;
    unsigned int bg_color[4];
    int dpi;
    int writePNG(QRcode *qrcode, const char *outfile);
    void produceqrcodefirst();
    void produceqrcodesecond();

private:
    Ui::QRCode *ui;
    WeightRecordsImpl *weightimpl;//称重表的接口
    QString carId;

private slots:
    void on_returnIndex_1_clicked();
    void on_returnIndex_clicked();
    void on_returnyiciguobang_clicked();

};

#endif // QRCODE_H
