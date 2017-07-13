#ifndef WANZHENG_CHAXUN_H
#define WANZHENG_CHAXUN_H

#include <QWidget>
#include <QSqlTableModel>
#include <previewprint.h>

namespace Ui {
class Wanzheng_chaxun;
}

class Wanzheng_chaxun : public QWidget
{
    Q_OBJECT
    
public:
    explicit Wanzheng_chaxun(QWidget *parent = 0);
    ~Wanzheng_chaxun();
    
private:
    Ui::Wanzheng_chaxun *ui;
    QSqlTableModel *model;

    previewPrint *preview;
  //  void initDb();

public slots:
    void returnIndex();//主页
    void returnPage();//返回上一页

    void doprintPreview();//slotcao
    void printPreview(QPrinter *printer);//预览页面

    void slotPrintPveview();//进入自定义打印界面

    void slotSetupPrint();//设置  目前是用来测试的

    void SlotGetString(QStringList strList);//获得测试设置对话框里的 数据
};

#endif // WANZHENG_CHAXUN_H
