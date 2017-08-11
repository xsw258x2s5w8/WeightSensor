#include "weightplatformimpl.h"

WeightPlatformImpl::WeightPlatformImpl()
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
        //创建表
        QString createTable_sql = "create table if not exists WeightPlatform(wpfmId INTEGER PRIMARY KEY AUTOINCREMENT,scale int,decimalPlaces int,filterMethod int,tradeModel int,subZero int,zeroTrack int,manualZero int,turnonZero int,measurement int,fullRange REAL,switchScale1 REAL,switchScale2 REAL,emptyScale REAL,firstThread REAL,secondThread REAL,loadPoint REAL,loadPoint2 REAL);";
        query.prepare(createTable_sql);
        if(!query.exec())
        {
            qDebug() << query.lastError();
        }
    }

    database.close();
}
WeightPlatform WeightPlatformImpl::selectWeightPlatform()//读取秤台参数设置表内数据
{
    WeightPlatform weightPlatform;
    if(database.open())
    {
        QSqlQuery query(database);

        QString select_all_sql = "select * from WeightPlatform";
        query.prepare(select_all_sql);
        if(!query.exec())
        {
             qDebug()<<query.lastError();
        }
        else
        {
            while(query.next())
            {
                weightPlatform.setWpfmId(query.value(0).toInt());
                weightPlatform.setScale(query.value(1).toInt());
                weightPlatform.setDecimalPlaces(query.value(2).toInt());
                weightPlatform.setFilterMethod(query.value(3).toInt());
                weightPlatform.setTradeModel(query.value(4).toInt());
                weightPlatform.setSubZero(query.value(5).toInt());
                weightPlatform.setZeroTrack(query.value(6).toInt());
                weightPlatform.setManualZero(query.value(7).toInt());
                weightPlatform.setTurnonZero(query.value(8).toInt());
                weightPlatform.setMeasurement(query.value(9).toInt());
                weightPlatform.setFullRange(query.value(10).toFloat());
                weightPlatform.setSwitchScale1(query.value(11).toFloat());
                weightPlatform.setSwitchScale2(query.value(12).toFloat());
                weightPlatform.setEmptyScale(query.value(13).toFloat());
                weightPlatform.setFirstThread(query.value(14).toFloat());
                weightPlatform.setSecondThread(query.value(15).toFloat());
                weightPlatform.setLoadPoint(query.value(16).toFloat());
                weightPlatform.setLoadPoint2(query.value(17).toFloat());
            }


        }
    }
    database.close();
    return weightPlatform;
}
int WeightPlatformImpl::insertWeightPlatform(WeightPlatform weightPlatform)//往秤台参数设置表内插入数据
{
    QTextCodec::setCodecForTr(QTextCodec::codecForLocale());
    if(database.open())
    {

        qDebug()<<"database opened"<<endl;
        QSqlQuery query;
        QString insert_sql = "insert into WeightPlatform(scale,decimalPlaces,filterMethod,tradeModel,subZero,zeroTrack,manualZero,turnonZero,measurement,fullRange,switchScale1,switchScale2,emptyScale,firstThread,secondThread,loadPoint,loadPoint2) values(?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?)";
        //插入数据
        query.prepare(insert_sql);
        //给数据赋值
        QVariantList GroupScale;
        GroupScale.append(weightPlatform.getScale());
        QVariantList GroupDecimalPlaces;
        GroupDecimalPlaces.append(weightPlatform.getDecimalPlaces());
        QVariantList GroupFilterMethod;
        GroupFilterMethod.append(weightPlatform.getFilterMethod());
        QVariantList GroupTradeModel;
        GroupTradeModel.append(weightPlatform.getTradeModel());
        QVariantList GroupSubZero;
        GroupSubZero.append(weightPlatform.getSubZero());
        QVariantList GroupZeroTrack;
        GroupZeroTrack.append(weightPlatform.getZeroTrack());
        QVariantList GroupManualZero;
        GroupManualZero.append(weightPlatform.getManualZero());
        QVariantList GroupTurnonZero;
        GroupTurnonZero.append(weightPlatform.getTurnonZero());
        QVariantList GroupMeasurement;
        GroupMeasurement.append(weightPlatform.getMeasurement());
        QVariantList GroupFullRange;
        GroupFullRange.append(weightPlatform.getFullRange());
        QVariantList GroupSwitchScale1;
        GroupSwitchScale1.append(weightPlatform.getSwitchScale1());
        QVariantList GroupSwitchScale2;
        GroupSwitchScale2.append(weightPlatform.getSwitchScale2());
        QVariantList GroupEmptyScale;
        GroupEmptyScale.append(weightPlatform.getEmptyScale());
        QVariantList GroupFirstThread;
        GroupFirstThread.append(weightPlatform.getFirstThread());
        QVariantList GroupSecondThread;
        GroupSecondThread.append(weightPlatform.getSecondThread());
        QVariantList GroupLoadPoint;
        GroupLoadPoint.append(weightPlatform.getLoadPoint());
        QVariantList GroupLoadPoint2;
        GroupLoadPoint2.append(weightPlatform.getLoadPoint2());

        //插入到sql语句中
        query.addBindValue(GroupScale);
        query.addBindValue(GroupDecimalPlaces);
        query.addBindValue(GroupFilterMethod);
        query.addBindValue(GroupTradeModel);
        query.addBindValue(GroupSubZero);
        query.addBindValue(GroupZeroTrack);
        query.addBindValue(GroupManualZero);
        query.addBindValue(GroupTurnonZero);
        query.addBindValue(GroupMeasurement);
        query.addBindValue(GroupFullRange);
        query.addBindValue(GroupSwitchScale1);
        query.addBindValue(GroupSwitchScale2);
        query.addBindValue(GroupEmptyScale);
        query.addBindValue(GroupFirstThread);
        query.addBindValue(GroupSecondThread);
        query.addBindValue(GroupLoadPoint);
        query.addBindValue(GroupLoadPoint2);


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
int WeightPlatformImpl::deleteWeightPlatform()//删除秤台参数设置表内的全部数据
{
    if(database.open())
    {
        QSqlQuery query;
        QString delete_sql = "delete from WeightPlatform";
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
