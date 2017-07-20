#ifndef OVERWEIGHT_H
#define OVERWEIGHT_H
#include <QString>
class overWeight
{
public:
    overWeight();
    int getId();
    void setId(int id);
    QString getDate();
    void setDate(QString date);
    QString getTime();
    void setTime(QString time);
    float getOverweight();
    void setOverweight(float overweight);

private:
    int id;
    QString date;
    QString time;
    float overweight;
};

#endif // OVERWEIGHT_H
