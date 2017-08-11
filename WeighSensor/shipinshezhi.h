#ifndef SHIPINSHEZHI_H
#define SHIPINSHEZHI_H

#include <QWidget>
#include "impl/videosettingstemp.h"
#include "impl/videosettingstempimpl.h"
#include <QMessageBox>
namespace Ui {
class Shipinshezhi;
}

class Shipinshezhi : public QWidget
{
    Q_OBJECT
    
public:
    explicit Shipinshezhi(QWidget *parent = 0);
    ~Shipinshezhi();

private:
    Ui::Shipinshezhi *ui;
public slots:
    void returnIndex();//zhuye
    void returnPage();//fanhuicaidan
    void emptyInfo();//清空设置
    void saveVideoInfo();//保存视频设置
};

#endif // SHIPINSHEZHI_H
