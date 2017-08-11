#ifndef YICIGUOBANG_H
#define YICIGUOBANG_H

#include <QWidget>
#include "impl/weightrecordsimpl.h"
#include "impl/caridmanagementimpl.h"
#include "impl/maininterfacetemp.h"
#include "impl/maininterfacetempimpl.h"
#include "qrcodewidget.h"

namespace Ui {
class Yiciguobang;
}

class Yiciguobang : public QWidget
{
    Q_OBJECT
    
public:
    explicit Yiciguobang(QWidget *parent = 0);
    ~Yiciguobang();
    void showData(QStringList strList);//用于刚开始进入界面显示数据
    void setCarWeight(QString data);//设置重量
    void setCarTare(QString data);//设置皮重

public slots:
    void returnIndex();//主页
    void returnPage();//返回上一页
    void showOkBtn();//点击确定
    void showCheliangBtn();//点击车辆按钮

private:
    Ui::Yiciguobang *ui;
    WeightRecordsImpl weight;//称重表的接口
    CarIdManagementImpl car;//车号表的接口
    MainInterfaceTempImpl maininterfacetempimpl;//数据接口
    QList<QLineEdit *> listLedit;  //用于保存生成的字段编辑框

    float carWeight;//称台重量  切记 这个不是毛重
    float carTare;//预设皮重
    float carMemoryTare;//记忆皮重

private:
    void showLineEdit();//根据maintemp表显示主界面的可选字段

    void chooseWRecrods(WeightRecords *weightRecords);//选择插入那个字段

};

#endif // YICIGUOBANG_H
