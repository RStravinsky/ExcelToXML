#include "partinfo.h"

QStringList PartInfo::cut2DList(QStringList() << "Durma Laser" << "Eckert" << "Zakmet");
QStringList PartInfo::benderList(QStringList() << "Krawedziarka" << "Pila");

QString PartInfo::defineTechnology(QString machine)
{
    if(cut2DList.contains(machine,Qt::CaseInsensitive))
        return QString("2D Cut");
    else if(machine == "Krawedziarka")
        return QString("Giecie");
    else if(machine == "Pila")
        return QString("Ciecie");
    else
        return QString("Non Cut");
}
