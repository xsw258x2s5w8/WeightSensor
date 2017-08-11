#ifndef YAJIAOQUEREN_H
#define YAJIAOQUEREN_H
#include "lib/sensorisnthread.h"
#include "lib/steedythread.h"
#include <QWidget>
#include <QLabel>

namespace Ui {
class Yajiaoqueren;
}

class Yajiaoqueren : public QWidget
{
    Q_OBJECT
    
public:
    explicit Yajiaoqueren(State_Inode empty_State_Inode,float emptyCurrentAllISN,int sensorNumber,QWidget *parent = 0);
    ~Yajiaoqueren();
    
private:
    Ui::Yajiaoqueren *ui;
    void GenerateLabels(int length);//根据传感器数量生成对应的label标识
    void SelectLabelPaint(bool select_label,int pos);//根据是否被选中，以及第几个label来确定label的显示
    int biggestSensorAddr(float bigvalue,int runtype);//返回变化量最大的传感器  标准参数， runtype确定是否使用传感器的角差

    int confirmBtn();//判断传感器是否设置过

private:
    SensorIsnThread sensorIsnThread;
    SteedyThread steedyThread;

    QList<QLabel *> listLabel;//Generatelabels 生成的label
    int biggestAddress;// 真实地址为 biggestddress+1
    QList<QString> addressList;//用于判断角位是否被确认过

    State_Inode empty_State_Inode;//空秤界面传过来的各个传感器空秤内码
    float emptyCurrentAllISN;//空秤时的内码
    int sensorNumber;//传感器个数

    //从线程中读取的各个传感器内码和滤波后总内码
    State_Inode state_Inode;//线程读取的内码
    float currentAllISN;//线程读取的总内码

public slots:
    void returnIndex();//主页
    void returnPage();//返回上一页
    void slotconfirm();//确认

    void slotRevceviedSteedyFlag(QString str,float currentAllISN,State_Inode state_Inode);//收到稳定符号

};

#endif // YAJIAOQUEREN_H
