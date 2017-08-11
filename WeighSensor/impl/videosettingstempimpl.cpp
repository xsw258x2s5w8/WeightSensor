#include "videosettingstempimpl.h"
#include <QDebug>
VideoSettingsTempImpl::VideoSettingsTempImpl()
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
        QString createTable_sql = "create table if not exists VideoSettingsTemp(id INTEGER PRIMARY KEY AUTOINCREMENT,videoFormatId int,isOpenCamera int,compcRatio int)";
        query.prepare(createTable_sql);
        if(!query.exec())
        {
            qDebug() << query.lastError();
        }
    }

    database.close();
}

int VideoSettingsTempImpl::deleteSettingTemp()//删除临时表
{
    if(database.open())
    {
        QSqlQuery query;
        QString delete_sql = "delete from VideoSettingsTemp";
        query.prepare(delete_sql);
        if(!query.exec())
        {
            qDebug()<<query.lastError();
            database.close();
            return -1;
        }
        else
        {
            qDebug()<<"delete success";
            database.close();
            return 1;
        }
    }
    database.close();
    return -1;
}

int VideoSettingsTempImpl::insertVideoSettings(VideoSettingsTemp videoSettingsTemp)//把视频设置数据插入到临时表
{
    QTextCodec::setCodecForTr(QTextCodec::codecForLocale());
    if(database.open())
    {

        qDebug()<<"database opened"<<endl;
        QSqlQuery query;
        QString insert_sql = "insert into VideoSettingsTemp(videoFormatId,isOpenCamera,compcRatio) values(?,?,?)";
        //插入数据
        query.prepare(insert_sql);
        //给数据赋值
        QVariantList GroupVideoFormatId;
        GroupVideoFormatId.append(videoSettingsTemp.getVideoFormatId());
        QVariantList GroupIsOpenCamera;
        GroupIsOpenCamera.append(videoSettingsTemp.getIsOpenCamera());
        QVariantList GroupCompcRatio;
        GroupCompcRatio.append(videoSettingsTemp.getCompcRatio());
        //插入到sql语句中
        query.addBindValue(GroupVideoFormatId);
        query.addBindValue(GroupIsOpenCamera);
        query.addBindValue(GroupCompcRatio);

        if(!query.execBatch())
        {
             qDebug()<<query.lastError();
             database.close();
             return -1;
        }
        else
        {
             qDebug()<<"插入记录成功";
             database.close();
             return 1;
         }

    }
}

VideoSettingsTemp VideoSettingsTempImpl::selectVideoSettings()//对临时表进行查询
{
    VideoSettingsTemp videoSettingsTemp;
    if(database.open())
    {
        QSqlQuery query(database);

        QString select_all_sql = "select * from VideoSettingsTemp";
        query.prepare(select_all_sql);
        if(!query.exec())
        {
             qDebug()<<query.lastError();
        }
        else
        {
            while(query.next())
            {
                videoSettingsTemp.setId(query.value(0).toInt());
                videoSettingsTemp.setVideoFormatId(query.value(1).toInt());
                videoSettingsTemp.setIsOpenCamera(query.value(2).toInt());
                videoSettingsTemp.setCompcRatio(query.value(3).toInt());
            }


        }
    }
    database.close();
    return videoSettingsTemp;
}

int VideoSettingsTempImpl::isExistVideoSettings()//判断临时表是否存在数据
{
   int result=-1;
    if(database.open())
    {
        QSqlQuery query(database);

        QString select_all_sql = "select count(*) from VideoSettingsTemp";
        query.prepare(select_all_sql);
        if(!query.exec())
        {
             qDebug()<<query.lastError();
        }
        else
        {
            while(query.next())
            {
                result = query.value(0).toInt();
            }


        }
    }
    database.close();
    return result;
}
