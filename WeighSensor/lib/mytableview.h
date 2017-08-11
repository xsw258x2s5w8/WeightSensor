#ifndef MYTABLEVIEW_H
#define MYTABLEVIEW_H
#include <QTableView>
#include <QStandardItemModel>
#include "mydelegate.h"
#include "impl/maininterface.h"
class MyTableView:public QTableView
{
public:
    MyTableView(QWidget * parent=0);
    virtual ~ MyTableView(){}
    int setModelData(MainInterface mainInterface);
    QList<MainInterface> getModelData();

private:
    MyDelegate * delegate;
    QStandardItemModel * model;
};

#endif // MYTABLEVIEW_H
