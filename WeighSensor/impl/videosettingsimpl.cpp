#include "videosettingsimpl.h"
#include <QDebug>
VideoSettingsImpl::VideoSettingsImpl()
{
    //创建数据库连接
    if(QSqlDatabase::contains("qt_sql_default_connection"))
      database = QSqlDatabase::database("qt_sql_default_connection");
    else
      database = QSqlDatabase::addDatabase("QSQLITE");
    //设置数据库
    database.setDatabaseName("/opt/sqlite/D28QT.db");
    //打开连接
    if( !database.open())
    {
       qDebug() << database.lastError();
    }
    else
    {
        qDebug( "Connected!" );
        QSqlQuery query;
        QString createTable_sql = "create table if not exists VideoSettings(videoFormatId INTEGER PRIMARY KEY AUTOINCREMENT,videoFormat varchar(20),width int,height int)";
        query.prepare(createTable_sql);
        if(!query.exec())
        {
            qDebug() << query.lastError();
        }
    }

    database.close();
}

VideoSettings VideoSettingsImpl::selectVideoSettingById(int videoFormatId)//根据视频格式id查询记录
{
    VideoSettings videoSettings;
    QString QId = QString::number(videoFormatId, 10);
    if(database.open())
    {
        qDebug()<<"database opened";
        QSqlQuery query;

        QString select_sql = "select * from VideoSettings where videoFormatId = " + QId;

        query.prepare(select_sql);

        if(!query.exec())
        {
             qDebug()<<query.lastError();
        }
        else
        {
            while(query.next())
            {
                videoSettings.setVideoFormatId(query.value(0).toInt());
                videoSettings.setVideoFormat(query.value(1).toString());
                videoSettings.setWidth(query.value(2).toInt());
                videoSettings.setHeight(query.value(3).toInt());
            }

        }

    }
    database.close();
    return videoSettings;
}

VideoSettings VideoSettingsImpl::selectVideoSettingByFormat(QString videoFormat)//根据视频格式来查询记录
{
    VideoSettings videoSettings;
    if(database.open())
    {
        qDebug()<<"database opened";
        QSqlQuery query;

        QString select_sql = "select * from VideoSettings where videoFormat = '" + videoFormat + "'";

        query.prepare(select_sql);

        if(!query.exec())
        {
             qDebug()<<query.lastError();
        }
        else
        {
            while(query.next())
            {
                videoSettings.setVideoFormatId(query.value(0).toInt());
                videoSettings.setVideoFormat(query.value(1).toString());
                videoSettings.setWidth(query.value(2).toInt());
                videoSettings.setHeight(query.value(3).toInt());
            }

        }

    }
    database.close();
    return videoSettings;
}
