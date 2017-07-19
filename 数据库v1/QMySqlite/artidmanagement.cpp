#include "artidmanagement.h"

ArtIdManagement::ArtIdManagement()
{
}
int ArtIdManagement::getId()
{
    return id;
}
void ArtIdManagement::setId(int id)
{
    this->id = id;
}
QString ArtIdManagement::getArtId()
{
    return artId;
}
void ArtIdManagement::setArtId(QString artId)
{
    this->artId = artId;
}
QString ArtIdManagement::getCommonName()
{
    return commonName;
}
void ArtIdManagement::setCommonName(QString commonName)
{
    this->commonName = commonName;
}
