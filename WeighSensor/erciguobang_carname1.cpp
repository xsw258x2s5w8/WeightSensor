#include "erciguobang_carname1.h"
#include <QGridLayout>
#include <QPushButton>
#include <QMessageBox>

Erciguobang_carName1::Erciguobang_carName1(QWidget *parent) :
    QWidget(parent)
{ 
    //10个button
    QString buttontext = "浙,泸,玉,油,奶,花,水,铁,麻,豆";
    QStringList texts = buttontext.split(",");
    signalMapper = new QSignalMapper(this);
    QGridLayout *gridLayout = new QGridLayout;
    for (int i = 0; i < texts.size(); ++i)
    {
       QPushButton *button = new QPushButton(texts[i], this);
       button->setObjectName(texts[i]);
       //原始信号传递给signalmapper
       connect(button, SIGNAL(clicked()), signalMapper, SLOT(map()));
       signalMapper->setMapping(button, texts[i]);
       //设置signalmapper的转发规则, 转发为参数为QString类型的信号， 并把texts[i]的内容作为实参传递。
       gridLayout->addWidget(button, i / 3, i % 3);
    }
    //将转发的信号连接到最终的槽函数
    connect(signalMapper, SIGNAL(mapped(const QString &)), this, SLOT(doClicked(const QString &)));
    setLayout(gridLayout);
}

void Erciguobang_carName1::doClicked(const QString &btnname)
{
    emit sendCarName1(btnname);

    this->close();
}
