#ifndef YITAIWANGSHEZHI_H
#define YITAIWANGSHEZHI_H

#include <QWidget>
#include <QProcess>
#include <QMessageBox>
#include "wangluoshezhi.h"
#include "index.h"
#include "impl/ipconfig.h"
#include "impl/ipconfigimpl.h"

namespace Ui {
class Yitaiwangshezhi;
}

class Yitaiwangshezhi : public QWidget
{
    Q_OBJECT
    
public:
    explicit Yitaiwangshezhi(QWidget *parent = 0);
    ~Yitaiwangshezhi();
    void setEthernet();//设置以太网

private:
    Ui::Yitaiwangshezhi *ui;

public slots:
    void returnIndex();//主页
    void returnPage();//返回上一页
private slots:
    void saveInfo();
};

#endif // YITAIWANGSHEZHI_H
