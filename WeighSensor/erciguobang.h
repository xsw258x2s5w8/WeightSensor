#ifndef ERCIGUOBANG_H
#define ERCIGUOBANG_H

#include <QWidget>
#include <erciguobang_car.h>
#include <erciguobang_art.h>

#include "impl/weightrecords.h"
#include "impl/weightrecordsimpl.h"

namespace Ui {
class Erciguobang;
}

class Erciguobang : public QWidget
{
    Q_OBJECT
    
public:
    explicit Erciguobang(QWidget *parent = 0);
    ~Erciguobang();

public:
    void getWeight(QString data);
    void showData(QStringList strList);//在主页点击二次过磅的处理操作

    
private:
    Ui::Erciguobang *ui;

    Erciguobang_car *carid;
    Erciguobang_art *artid;

public slots:
    void returnIndex();//主页
    void returnPage();//返回上一页
    void showCarData();//显示车牌设置界面
    void showArtData();//显示货号选择界面

    void getCarData(QString data);//获得修改后的车牌号
    void getArtData(QString data);//获得修改后的货号
    void getRemarkData(QString data);//获得备注

    void checkOkbtn();//二次过磅确认界面
    void replaceBTN();//替换上次

private:
    float carWeight;

    WeightRecordsImpl *weight;//WeightRecords表访问接口
};

#endif // ERCIGUOBANG_H
