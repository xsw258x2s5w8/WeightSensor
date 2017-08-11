#ifndef WEIGHTRECORDS_H
#define WEIGHTRECORDS_H
#include <QString>
class WeightRecords
{
public:
    WeightRecords();
    int getId();
    void setId(int id);
    int getUserId();
    void setUserId(int userId);
    QString getDate1();
    void setDate1(QString date1);
    QString getDate2();
    void setDate2(QString date2);
    QString getTime1();
    void setTime1(QString time1);
    QString getTime2();
    void setTime2(QString time2);
    QString getFactoryIn();
    void setFactoryIn(QString factoryIn);
    QString getFactoryOut();
    void setFactoryOut(QString factoryOut);
    QString getCarId();
    void setCarId(QString carId);
    QString getArtId();
    void setArtId(QString artId);
    float getGrossWeight();
    void setGrossWeight(float grossWeight);
    float getTare();
    void setTare(float tare);
    float getNetWeight();
    void setNetWeight(float netWeight);
    float getDeduction();
    void setDeduction(float deduction);
    int getMonitorId();
    void setMonitorId(int monitorId);
    QString getRemark();
    void setRemark(QString remark);
    int getPonderation();
    void setPonderation(int ponderation);
    int getComplete();
    void setComplete(int complete);
    QString getReserved1();
    void setReserved1(QString reserved1);
    QString getReserved2();
    void setReserved2(QString reserved2);
    QString getReserved3();
    void setReserved3(QString reserved3);
    QString getReserved4();
    void setReserved4(QString reserved4);
    float getSpareWeight();
    void setSpareWeight(float spareWeight);
private:
    int id;//*
    int userId;//用户id
    QString date1;//第一次过磅日期*
    QString date2;//第二次过磅日期*
    QString time1;//第一次过磅时间*
    QString time2;//第二次过磅时间*
    QString factoryIn;//入厂单位
    QString factoryOut;//出厂单位
    QString carId;//车号*
    QString artId;//货号*
    float grossWeight;//毛重*
    float tare;//皮重*
    float netWeight;//净重*
    float deduction;//扣杂*
    int monitorId;//监控资源id
    QString remark;//备注*
    int complete;//记录完整性（0：完整记录 1：不完整记录）
    int ponderation;//过磅次序（1：一次过磅，2：二次过磅）
    QString reserved1;//预留字段1
    QString reserved2;//预留字段2
    QString reserved3;//预留字段3
    QString reserved4;//预留字段4
    float spareWeight;//备用重量

};

#endif // WEIGHTRECORDS_H
