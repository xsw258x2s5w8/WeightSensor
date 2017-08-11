#include <QPicture>
#include "qrcodewidget.h"
#include "ui_qrcode.h"
#include "index.h"
#include "yiciguobang.h"
#include <QDebug>
QRCodeWidget::QRCodeWidget(QString carId1, QWidget *parent) :
    QWidget(parent, Qt::Dialog),
    ui(new Ui::QRCode)
{
    ui->setupUi(this);
    this->setWindowState(Qt::WindowFullScreen);

    qDebug()<<carId;
    fg_color[0] = 0;
    fg_color[1] = 0;
    fg_color[2] = 0;
    fg_color[3] = 255;

    bg_color[0] =  255;
    bg_color[1] =  255;
    bg_color[2] =  255;
    bg_color[3] =  255;

    QTextCodec *codec = QTextCodec::codecForName("utf8");
    QTextCodec::setCodecForLocale(codec);
    QTextCodec::setCodecForCStrings(codec);
    QTextCodec::setCodecForTr(codec);



    carId = carId1;
    weightimpl = new WeightRecordsImpl();
    margin = 2;
    size = 7;
    version = 2;    
    qrcode = NULL;
    produceqrcodesecond();
}

QRCodeWidget::~QRCodeWidget()
{
    delete ui;
}

int  QRCodeWidget::writePNG(QRcode *qrcode, const char *outfile)
{
    static FILE *fp; // avoid clobbering by setjmp.
    png_structp png_ptr;
    png_infop info_ptr;
    png_colorp palette;
    png_byte alpha_values[2];
    unsigned char *row, *p, *q;
    int x, y, xx, yy, bit;
    int realwidth;

    realwidth = (qrcode->width + margin * 2) * size;
    row = (unsigned char *)malloc((realwidth + 7) / 8);
    if(row == NULL) {
        fprintf(stderr, "Failed to allocate memory.\n");
        exit(EXIT_FAILURE);
    }

    if(outfile[0] == '-' && outfile[1] == '\0') {
        fp = stdout;
    } else {
        fp = fopen(outfile, "wb");
        if(fp == NULL) {
            fprintf(stderr, "Failed to create file: %s\n", outfile);
            perror(NULL);
            exit(EXIT_FAILURE);
        }
    }

    png_ptr = png_create_write_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
    if(png_ptr == NULL) {
        fprintf(stderr, "Failed to initialize PNG writer.\n");
        exit(EXIT_FAILURE);
    }

    info_ptr = png_create_info_struct(png_ptr);
    if(info_ptr == NULL) {
        fprintf(stderr, "Failed to initialize PNG write.\n");
        exit(EXIT_FAILURE);
    }

    if(setjmp(png_jmpbuf(png_ptr))) {
        png_destroy_write_struct(&png_ptr, &info_ptr);
        fprintf(stderr, "Failed to write PNG image.\n");
        exit(EXIT_FAILURE);
    }

    palette = (png_colorp) malloc(sizeof(png_color) * 2);
    if(palette == NULL) {
        fprintf(stderr, "Failed to allocate memory.\n");
        exit(EXIT_FAILURE);
    }
    palette[0].red   = fg_color[0];
    palette[0].green = fg_color[1];
    palette[0].blue  = fg_color[2];
    palette[1].red   = bg_color[0];
    palette[1].green = bg_color[1];
    palette[1].blue  = bg_color[2];
    alpha_values[0] = fg_color[3];
    alpha_values[1] = bg_color[3];
    png_set_PLTE(png_ptr, info_ptr, palette, 2);
    png_set_tRNS(png_ptr, info_ptr, alpha_values, 2, NULL);

    png_init_io(png_ptr, fp);
    png_set_IHDR(png_ptr, info_ptr,
            realwidth, realwidth,
            1,
            PNG_COLOR_TYPE_PALETTE,
            PNG_INTERLACE_NONE,
            PNG_COMPRESSION_TYPE_DEFAULT,
            PNG_FILTER_TYPE_DEFAULT);
    png_set_pHYs(png_ptr, info_ptr,
            dpi * INCHES_PER_METER,
            dpi * INCHES_PER_METER,
            PNG_RESOLUTION_METER);
    png_write_info(png_ptr, info_ptr);

    /* top margin */
    memset(row, 0xff, (realwidth + 7) / 8);
    for(y=0; y<margin * size; y++) {
        png_write_row(png_ptr, row);
    }

    /* data */
    p = qrcode->data;
    for(y=0; y<qrcode->width; y++) {
        bit = 7;
        memset(row, 0xff, (realwidth + 7) / 8);
        q = row;
        q += margin * size / 8;
        bit = 7 - (margin * size % 8);
        for(x=0; x<qrcode->width; x++) {
            for(xx=0; xx<size; xx++) {
                *q ^= (*p & 1) << bit;
                bit--;
                if(bit < 0) {
                    q++;
                    bit = 7;
                }
            }
            p++;
        }
        for(yy=0; yy<size; yy++) {
            png_write_row(png_ptr, row);
        }
    }
    /* bottom margin */
    memset(row, 0xff, (realwidth + 7) / 8);
    for(y=0; y<margin * size; y++) {
        png_write_row(png_ptr, row);
    }

    png_write_end(png_ptr, info_ptr);
    png_destroy_write_struct(&png_ptr, &info_ptr);

    fclose(fp);
    free(row);
    free(palette);

    return 0;
}

void QRCodeWidget::produceqrcodefirst()
{

    WeightRecords weight;
    weight = weightimpl->selectWR1(carId);
    QString info ="序号SERIAL  NO." + QString::number(weight.getId(),10) + "\n" +
                  "日期DATE  "+ weight.getDate1() + "\n" +
                  "时间TIME  " + weight.getTime1()  + "\n" +
                  "车号VEHICLE  NO." + weight.getCarId() + "\n" +
                  "货号GARGO  NO." + weight.getArtId() + "\n" +
                  "总重GROSS  " + QString("float is %1").arg(weight.getGrossWeight()) + "\n" +
                  "皮重TARE  " + QString("float is %1").arg(weight.getTare()) + "\n" +
                  "扣率DISCOUNT  " + QString("float is %1").arg(weight.getDeduction()) + "\n" +
                  "净重NET  " + QString("float is %1").arg(weight.getNetWeight()) + "\n" +
                  "备注  " + weight.getRemark();
    if (info.isEmpty()) {
        return;
    }    

    char outfile[] = "output.png";
    qrcode = QRcode_encodeString(info.toStdString().data(), 2, QR_ECLEVEL_L, QR_MODE_8, 0);
    writePNG(qrcode, outfile);
    ui->label_3->setPixmap(QPixmap(outfile));
    QRcode_free(qrcode);
    qrcode = NULL;
}

void QRCodeWidget::produceqrcodesecond()
{
    WeightRecords weight;
    weight = weightimpl->selectWR2(carId);
    QString info ="序号SERIAL  NO." + QString::number(weight.getId(),10) + "\n" +
                  "第一过磅日期DATE  "+ weight.getDate1() + "\n" +
                  "第一过磅时间TIME  " + weight.getTime1()  + "\n" +
                  "第二过磅日期DATE  "+ weight.getDate2() + "\n" +
                  "第二过磅时间TIME  " + weight.getTime2()  + "\n" +
                  "车号VEHICLE  NO." + weight.getCarId() + "\n" +
                  "货号GARGO  NO." + weight.getArtId() + "\n" +
                  "总重GROSS  " + QString("float is %1").arg(weight.getGrossWeight()) + "\n" +
                  "皮重TARE  " + QString("float is %1").arg(weight.getTare()) + "\n" +
                  "扣率DISCOUNT  " + QString("float is %1").arg(weight.getDeduction()) + "\n" +
                  "净重NET  " + QString("float is %1").arg(weight.getNetWeight()) + "\n" +
                  "备注  " + weight.getRemark();
    if (info.isEmpty()) {
        return;
    }

    char outfile[] = "output.png";
    qrcode = QRcode_encodeString(info.toStdString().data(), 2, QR_ECLEVEL_L, QR_MODE_8, 0);
    writePNG(qrcode, outfile);
    ui->label_3->setPixmap(QPixmap(outfile));
    QRcode_free(qrcode);
    qrcode = NULL;
}


void QRCodeWidget::on_returnIndex_1_clicked()
{
//    Index *index = new Index();
//    index->show();
    this->close();
}

void QRCodeWidget::on_returnIndex_clicked()
{
//    Index *menu=new Index();
//    menu->show();
    this->close();
}

void QRCodeWidget::on_returnyiciguobang_clicked()
{
    Yiciguobang *ycgb = new Yiciguobang();
    ycgb->show();
    this->close();
}
