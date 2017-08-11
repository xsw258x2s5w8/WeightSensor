#include <QApplication>
#include <QStyledItemDelegate>
#include <QPainter>
#include <QMouseEvent>
#include <QStandardItemModel>
#include <QDialog>
#include <QDesktopWidget>
#include <QDebug>
#include <QMessageBox>
#include "mydelegate.h"

MyDelegate::MyDelegate(QObject * parent)
:QItemDelegate(parent)
{

}


QRect MyDelegate::CheckBoxRect(const QStyleOptionViewItem &viewItemStyleOptions)const
{
    //绘制按钮所需要的参数
    QStyleOptionButton checkBoxStyleOption;
    //按照给定的风格参数 返回元素子区域
    QRect checkBoxRect = QApplication::style()->subElementRect( QStyle::SE_CheckBoxIndicator, &checkBoxStyleOption);
    //返回QCheckBox坐标
    QPoint checkBoxPoint(viewItemStyleOptions.rect.x() + viewItemStyleOptions.rect.width() / 2 - checkBoxRect.width() / 2,
                         viewItemStyleOptions.rect.y() + viewItemStyleOptions.rect.height() / 2 - checkBoxRect.height() / 2);
    //返回QCheckBox几何形状
    return QRect(checkBoxPoint, checkBoxRect.size());
}

QRect MyDelegate::PushButtonRect(const QStyleOptionViewItem &viewItemStyleOptions)const
{
    //绘制按钮所需要的参数
    QStyleOptionButton checkBoxStyleOption;
    //按照给定的风格参数 返回元素子区域
    QRect checkBoxRect = QApplication::style()->subElementRect( QStyle::SE_CheckBoxIndicator, &checkBoxStyleOption);
    //返回QCheckBox坐标
    QPoint checkBoxPoint(viewItemStyleOptions.rect.x() + viewItemStyleOptions.rect.width() / 2 - checkBoxRect.width() / 2,
                         viewItemStyleOptions.rect.y() + viewItemStyleOptions.rect.height() / 2 - checkBoxRect.height() / 2);
    //返回QCheckBox几何形状
    return QRect(checkBoxPoint, checkBoxRect.size());
}

QRect MyDelegate::PushButtonRect1(const QStyleOptionViewItem &viewItemStyleOptions)const
{
    //绘制按钮所需要的参数
    QStyleOptionButton checkBoxStyleOption;
    //按照给定的风格参数 返回元素子区域
    QRect checkBoxRect;
    checkBoxRect.adjust(12,12,-12,-12);
    //返回QCheckBox坐标
    QPoint checkBoxPoint(viewItemStyleOptions.rect.x() + viewItemStyleOptions.rect.width() / 2 - checkBoxRect.width() / 2,
                         viewItemStyleOptions.rect.y() + viewItemStyleOptions.rect.height() / 2 - checkBoxRect.height() / 2);
    //返回QCheckBox几何形状
    return QRect(checkBoxPoint, checkBoxRect.size());
}

//重绘
void MyDelegate::paint(QPainter * painter,
                           const QStyleOptionViewItem & option,
                           const QModelIndex & index) const
{
    //对第二行中的内容进行重新渲染
//    if(index.column()==0)
//    {
//        //获得当前数据项的值
//        //int id = index.model()->data(index,Qt::DisplayRole).toInt();
//        //QString text = QString("ID:%1").arg(id,6,10,QChar('0'));


//        //获取项风格设置
//        //QStyleOptionViewItem myOption = option;
//       //myOption.displayAlignment = Qt::AlignRight | Qt::AlignVCenter;
//        //QString text = QString::number(id,10);
//        //绘制文本
//        //QApplication::style()->drawItemText ( painter, myOption.rect , myOption.displayAlignment,
//        //                                     QApplication::palette(), true, "你好" );
//    }

    if (index.column() == 1)
    {
        //获取值
        bool checked = index.model()->data(index, Qt::DisplayRole).toBool();
        //按钮的风格选项
        QStyleOptionButton *checkBoxOption = new QStyleOptionButton();
        checkBoxOption->state |= QStyle::State_Enabled;
        //根据值判断是否选中
        if(checked)
        {
            checkBoxOption->state |= QStyle::State_On;
        }
        else
        {
            checkBoxOption->state |= QStyle::State_Off;
        }
        //返回QCheckBox几何形状
        checkBoxOption->rect = CheckBoxRect(option);
        //绘制QCheckBox
        QApplication::style()->drawControl(QStyle::CE_CheckBox,checkBoxOption,painter);

    }

    else if(index.column()==2)
    {
        //按钮的风格选项
        QStyleOptionButton *pushButtonOption = new QStyleOptionButton();
        pushButtonOption->state |= QStyle::State_Enabled;
        pushButtonOption->rect = PushButtonRect(option);
        pushButtonOption->text = "↑";

        QApplication::style()->drawControl(QStyle::CE_PushButton, pushButtonOption, painter);

    }
    else if(index.column()==3)
    {
        //按钮的风格选项
        QStyleOptionButton *pushButtonOption = new QStyleOptionButton();
        pushButtonOption->state |= QStyle::State_Enabled;
        pushButtonOption->rect = PushButtonRect1(option);
        pushButtonOption->text = "删除";
        QApplication::style()->drawControl(QStyle::CE_PushButton, pushButtonOption, painter);

    }

    else
    {
        //否则调用默认委托
        QItemDelegate::paint(painter,option,index);
    }

}

//编辑时
bool MyDelegate::editorEvent(QEvent * event,
       QAbstractItemModel * model,
       const QStyleOptionViewItem & option,
       const QModelIndex & index)
{
    //当编辑框被点击触发时
    if((event->type()==QEvent::MouseButtonRelease ||(event->type() == QEvent::MouseButtonDblClick))&&
            index.column()==0){


        //获取该编辑框是否可编辑的信息

        QModelIndex index1 =  model->index(index.row(),2);
        QString isChecked = index.model()->data(index1, Qt::DisplayRole).toString();

        if(isChecked=="1"){
            QMessageBox::about(NULL, "Edit it", "该数据无法编辑");
        }



    }

    //复选框被点击时触发
    if((event->type()==QEvent::MouseButtonRelease ||(event->type() == QEvent::MouseButtonDblClick))&&
            index.column()==1){


        //判断能否编辑
        QModelIndex index1 =  model->index(index.row(),2);
        QString isChecked = index.model()->data(index1, Qt::DisplayRole).toString();

        if(isChecked=="1"){
            QMessageBox::about(NULL, "Edit it", "该数据无法编辑");
        }
        else
        {
            bool checked = index.model()->data(index, Qt::DisplayRole).toBool();

            model->setData(index, !checked, Qt::EditRole);
        }


        return true;

    }
    else if(index.column()==2)
    {
        if ((event->type() == QEvent::MouseButtonPress) ||(event->type() == QEvent::MouseButtonDblClick)) {
            //上下交换
            int row = index.row();//首先得知那一行
            int column = index.column();
            if(row>0)
            {
                QModelIndex index1 =  model->index(row-1,2);//获得上一行是否固定的信息(isMust==1)
                QString isChecked = index.model()->data(index1, Qt::DisplayRole).toString();
                if(isChecked=="1"){
                    QMessageBox::about(NULL, "Move it", "无法与固定的主界面字段相互交换");
                }
                else
                {

                    QVariant data[5];

                    //int row1=row-1;
                    for(int i=0;i<5;i++)
                    {
                        QModelIndex index1 = model->index(row,i);
                        data[i] = index1.data();

                         QString data1 = data[i].toString();
                         qDebug()<<data1;
                     }
                     model->removeRow(row);

                     //QModelIndex index2;


                     model->insertRow(row-1);

                     for(int i=0;i<5;i++)
                     {
                         QModelIndex index1 = model->index(row-1,i);
                         model->setData(index1,data[i]);
                     }
                 }
            }
            else
            {
                QMessageBox::about(NULL, "Move it", "这是第一行，无法交换");
            }


        }
    }
    else if(index.column()==3)
    {
        if ((event->type() == QEvent::MouseButtonPress) ||(event->type() == QEvent::MouseButtonDblClick)) {

            int row = index.row();//首先得知那一行

            QModelIndex index1 =  model->index(index.row(),2);//获得该行的第三列信息
            QString isChecked = index.model()->data(index1, Qt::DisplayRole).toString();//来判断该行是否可以删除
            if(isChecked!="1")
            {
                QMessageBox::StandardButton rb = QMessageBox::question(NULL, "Delete it", "是否删除这一行？", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
                if(rb == QMessageBox::Yes)
                {
                    //删除该行
                    model->removeRow(row);
                }
            }
            else
            {
                QMessageBox::about(NULL, "Delete it", "该行无法删除");
            }

        }
    }


    else
    {
        return QItemDelegate::editorEvent(event,model,option,index);
    }

}
