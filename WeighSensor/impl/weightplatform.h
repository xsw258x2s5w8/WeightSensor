#ifndef WEIGHTPLATFORM_H
#define WEIGHTPLATFORM_H

class WeightPlatform
{
public:
    WeightPlatform();
    int getWpfmId();
    void setWpfmId(int wpfmId);
    int getScale();
    void setScale(int scale);
    int getDecimalPlaces();
    void setDecimalPlaces(int decimalPlaces);
    int getFilterMethod();
    void setFilterMethod(int filterMethod);
    int getTradeModel();
    void setTradeModel(int tradeModel);
    int getSubZero();
    void setSubZero(int subZero);
    int getZeroTrack();
    void setZeroTrack(int zeroTrack);
    int getManualZero();
    void setManualZero(int manualZero);
    int getTurnonZero();
    void setTurnonZero(int turnonZero);
    int getMeasurement();
    void setMeasurement(int measurement);
    float getFullRange();
    void setFullRange(float fullRange);
    float getSwitchScale1();
    void setSwitchScale1(float switchScale1);
    float getSwitchScale2();
    void setSwitchScale2(float switchScale2);
    float getEmptyScale();
    void setEmptyScale(float emptyScale);
    float getFirstThread();
    void setFirstThread(float firstThread);
    float getSecondThread();
    void setSecondThread(float secondThread);
    float getLoadPoint();
    void setLoadPoint(float loadPoint);
    float getLoadPoint2();
    void setLoadPoint2(float loadPoint);

private:
    int wpfmId;//称台设置编号(id)
    int scale;//分度值
    int decimalPlaces;//小数位
    int filterMethod;//滤波方式
    int tradeModel;//贸易模式
    int subZero;//去皮下置零范围
    int zeroTrack;//零点跟踪范围
    int manualZero;//手动置零范围
    int turnonZero;//开机置零范围
    int measurement;//计量单位
    float fullRange;//满量程
    float switchScale1;//切换分度值1
    float switchScale2;//切换分度值2
    float emptyScale;//空秤内码
    float firstThread;//第一段线性
    float secondThread;//第二段线性
    float loadPoint;//加载点1内码
    float loadPoint2;//加载点2内码
//    float weighData1;//加载点1重量
//    float weighData2;//加载点2重量
};

#endif // WEIGHTPLATFORM_H
