#ifndef YICIGUOBANG_H
#define YICIGUOBANG_H

#include <QWidget>
#include "impl/weightrecordsimpl.h"
#include "impl/caridmanagementimpl.h"

namespace Ui {
class Yiciguobang;
}

class Yiciguobang : public QWidget
{
    Q_OBJECT
    
public:
    explicit Yiciguobang(QWidget *parent = 0);
    ~Yiciguobang();

public:
    void showData(QStringList strList);//用于刚开始进入界面显示数据
    void setCarWeight(QString data);//获得重量
    void setCarTare(QString data);//获得皮重
    
private:
    Ui::Yiciguobang *ui;

public slots:
    void returnIndex();//主页
    void returnPage();//返回上一页

    void showOkBtn();//点击确定
    void showCheliangBtn();//点击车辆按钮

private:
    WeightRecordsImpl *weight;//称重表的接口
    CarIdManagementImpl *car;//车号表的接口

    float carWeight;//称台重量
    float carTare;//预设皮重
    float carMemoryTare;//记忆皮重
};

#endif // YICIGUOBANG_H
