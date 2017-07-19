#ifndef ARTIDMANAGEMENT_H
#define ARTIDMANAGEMENT_H
#include <QString>
class ArtIdManagement
{
public:
    ArtIdManagement();
    int getId();
    void setId(int id);
    QString getArtId();
    void setArtId(QString artId);
    QString getCommonName();
    void setCommonName(QString commonName);

private:
    int id;
    QString artId;//货号
    QString commonName;//常用名
};

#endif // ARTIDMANAGEMENT_H
