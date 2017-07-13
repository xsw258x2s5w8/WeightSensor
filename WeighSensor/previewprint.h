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

    // 移动距离
    int topDistance;
    int bottomDistance;
    int leftDistance;
    int rightDistance;

    //联单间隔
    int cellMargin;

    //绘画开始坐标点
    int initX;
    int initY;

    //每行字段之间的距离
    int cellTocellDistance;

    //字体长寛高
    int cellWidth;
    int cellHeight;
private:
    void rePaint();


public slots:
    void slotprint(QPrinter *);//用于调用最开始的预览界面

    void slotClose();
    void slotZoomIn();//缩小预览界面内容
    void slotZoomOut();//放大预览界面内容
    void slotPrint();//打印对话框
    void slotPageSetup();//页面设置

    void slotSetup();//属性设置

public:
    //set方法
    // 移动距离
    void setTopDistance(int topDistance);
    void setBottomDistance(int bottomDistance);
    void setLeftDistance(int leftDistance);
    void setRightDistance(int rightDistance);

    //联单间隔
    void setCellMargin(int cellMargin);

    //绘画开始坐标点
    void setInitX(int initX);
    void setInitY(int initY);

    //每行字段之间的距离
    void setCellTocellDistance(int cellTocellDistance);

    //字体长寛高
    void setCellWidth(int cellWidth);
    void setCellHeight(int cellHeight);

    //成员函数
    void updatePre();//重新发射paintRequest信号，，更新画面
};

#endif // PREVIEWPRINT_H
