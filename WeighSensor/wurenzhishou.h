#ifndef WURENZHISHOU_H
#define WURENZHISHOU_H

#include <QWidget>

namespace Ui {
class Wurenzhishou;
}

class Wurenzhishou : public QWidget
{
    Q_OBJECT
    
public:
    explicit Wurenzhishou(QWidget *parent = 0);
    ~Wurenzhishou();
    
private:
    Ui::Wurenzhishou *ui;

public slots:
  void returnIndex();//zhuye
  void returnPage();//fanhuicaidan
  void showSetVideo();//进入视频设置界面
  void showVideoProgress();//进入视频流程界面
};

#endif // WURENZHISHOU_H
