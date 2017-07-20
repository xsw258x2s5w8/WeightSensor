#include <QApplication>
#include "overweightimpl.h"
#include "overweight.h"
#include "caridmanagement.h"
#include "caridmanagementimpl.h"
#include "artidmanagementimpl.h"
#include "artidmanagement.h"
#include "weightrecords.h"
#include "weightrecordsimpl.h"
#include <QList>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));


    WeightRecordsImpl weight;//WeightRecords表访问接口
    WeightRecords weightRecords;
    weightRecords.setCarId("浙A-2342");
    weightRecords.setArtId("s2904");
    weightRecords.setGrossWeight(10000);
    weightRecords.setTare(5000);
    weightRecords.setNetWeight(5000);
    weightRecords.setFactoryIn("家纺");
    weightRecords.setFactoryOut("纺织厂");
    weightRecords.setUserId(12);
    weightRecords.setDeduction(89.0);
    //weightRecords.setDate1("2017-1-5");
    //weightRecords.setTime1("16:08");
    weightRecords.setDate2("2017-1-6");
    weightRecords.setTime2("7:07");
    //weightRecords.setMonitorId();
    weightRecords.setComplete(1);
    weightRecords.setPonderation(2);
    weightRecords.setRemark("");

    //int result = weight.insertWeightRecords(weightRecords);
    //qDebug()<<result;
    int id1 = weight.isComplete("浙A-2342");
    qDebug()<<"id="<<id1;
    if(id1!=-1)
    {
        WeightRecords test = weight.selectWR(id1);
        int id = test.getId();
        QString carId = test.getCarId();
        QString artId = test.getArtId();
        float grossWeight = test.getGrossWeight();
        float tare = test.getTare();
        float netWeight = test.getNetWeight();
        QString factoryIn = test.getFactoryIn();
        QString factoryOut = test.getFactoryOut();
        int userId = test.getUserId();
        float deduction = test.getDeduction();
        QString date1 = test.getDate1();
        //QString date2 = test.getDate2();
        QString time1 = test.getTime1();
        //QString time2 = test.getTime2();
        //int monitorId = test.getMonitorId();
        int complete = test.getComplete();
        int ponderation = test.getPonderation();
        //QString remark = test.getRemark();

        qDebug()<<"id="<<id<<",carId="<<carId<<",artId="<<artId<<",grossWeight="<<grossWeight<<",tare="<<tare<<",netWeight="<<netWeight<<",factoryIn="<<factoryIn<<",factoryOut="<<factoryOut;
        qDebug()<<"userId="<<userId<<",deduction="<<deduction<<",date1="<<date1<<",time1="<<time1<<",complete"<<complete<<",ponderation="<<ponderation;
    }



    int result = weight.updateWeightRecords(weightRecords);
    qDebug()<<result;

    int id2 = weight.isComplete("浙A-2342");
    qDebug()<<"id="<<id2;
    if(id1!=-1)
    {
        WeightRecords test = weight.selectWR(id2);
        int id = test.getId();
        QString carId = test.getCarId();
        QString artId = test.getArtId();
        float grossWeight = test.getGrossWeight();
        float tare = test.getTare();
        float netWeight = test.getNetWeight();
        QString factoryIn = test.getFactoryIn();
        QString factoryOut = test.getFactoryOut();
        int userId = test.getUserId();
        float deduction = test.getDeduction();
        QString date1 = test.getDate1();
        //QString date2 = test.getDate2();
        QString time1 = test.getTime1();
        //QString time2 = test.getTime2();
        int monitorId = test.getMonitorId();
        int complete = test.getComplete();
        int ponderation = test.getPonderation();
        QString remark = test.getRemark();

        qDebug()<<"id="<<id<<",carId="<<carId<<",artId="<<artId<<",grossWeight="<<grossWeight<<",tare="<<tare<<",netWeight="<<netWeight<<",factoryIn="<<factoryIn<<",factoryOut="<<factoryOut;
        qDebug()<<"userId="<<userId<<",deduction="<<deduction<<",date1="<<date1<<",time1="<<time1<<",complete"<<complete<<",ponderation="<<ponderation;
    }
    /*
    overWeightImpl over; //overWeight表访问接口

    overWeight overweight;
    overweight.setId(2);
    overweight.setDate("12-10");
    overweight.setTime("11:00");
    overweight.setOverweight(1002);

    QList<overWeight> overlist;
    //int result = over.insertDate(overweight);//把overWeight对象指针传入接口，实现插入数据的功能,result为插入结果
    //操作前
    overlist = over.selectDate();//从接口接收overWeight对象数据,若对象数据为NULL，则为查找失败或者无数据
    for(int i=0;i<overlist.length();i++)
    {
        overWeight overweight1 = overlist.value(i);
        int id = overweight1.getId();
        QString date = overweight1.getDate();
        QString time = overweight1.getTime();
        int overweight2 = overweight1.getOverweight();
        qDebug()<<"id="<<id<<" date="<<date<<" time="<<time<<" overweight="<<overweight2;//打印输出信息
    }


    int result = over.deleteDate(overweight);//通过接口删除数据库中overWeight对象数据,result为删除结果

    //操作后
    overlist = over.selectDate();//从接口接收overWeight对象数据,若对象数据为NULL，则为查找失败或者无数据
    for(int i=0;i<overlist.length();i++)
    {
        overWeight overweight1 = overlist.value(i);
        int id = overweight1.getId();
        QString date = overweight1.getDate();
        QString time = overweight1.getTime();
        int overweight2 = overweight1.getOverweight();
        qDebug()<<"id="<<id<<" date="<<date<<" time="<<time<<" overweight="<<overweight2;//打印输出信息
    }

    //qDebug()<<result;


    ArtIdManagementImpl art; //overWeight表访问接口

    ArtIdManagement artIdManagement;
    artIdManagement.setId(3);
    artIdManagement.setArtId("56667658");
    artIdManagement.setCommonName("二号货物");

    QList<ArtIdManagement> artlist;

    //操作前
    artlist = art.selectData();//从接口接收overWeight对象数据,若对象数据为NULL，则为查找失败或者无数据
    for(int i=0;i<artlist.length();i++)
    {
        ArtIdManagement artIdManagement1 = artlist.value(i);
        int id = artIdManagement1.getId();
        QString artId = artIdManagement1.getArtId();
        QString commonName = artIdManagement1.getCommonName();
        qDebug()<<"id="<<id<<" artId="<<artId<<" commonName="<<commonName;//打印输出信息
    }

    int result = art.insertData(artIdManagement);//把overWeight对象指针传入接口，实现插入数据的功能,result为插入结果

    //int result = art.deleteData(artIdManagement);//通过接口删除数据库中overWeight对象数据,result为删除结果

  //  int reuslt = art.updateData(artIdManagement);
    //操作后
    artlist = art.selectData();//从接口接收overWeight对象数据,若对象数据为NULL，则为查找失败或者无数据
    for(int i=0;i<artlist.length();i++)
    {	
        ArtIdManagement artIdManagement1 = artlist.value(i);
        int id = artIdManagement1.getId();
        QString artId = artIdManagement1.getArtId();
        QString commonName = artIdManagement1.getCommonName();
        qDebug()<<"id="<<id<<" artId="<<artId<<" commonName="<<commonName;//打印输出信息
    }


    //qDebug()<<result;
    */
    return 0;
}
