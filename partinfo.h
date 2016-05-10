#ifndef PARTINFO_H
#define PARTINFO_H

#include <QObject>
#include <QStringList>

class PartInfo : public QObject
{
    Q_OBJECT
public:
    explicit PartInfo(const QString & drawingNumber, const QString & material, double thickness, int quantity = 1, const QString & filePath = QString(), QObject *parent = 0) :
        m_drawingNumber(drawingNumber), m_material(material), m_thickness(thickness), m_quantity(quantity), m_filePath(filePath), QObject(parent) {}
    QString getDrawingNumber() { return m_drawingNumber; }
    QString getMaterial() { return m_material; }
    double getThickness() { return m_thickness; }
    QString getFilePath() { return m_filePath; }
    int getQuantity() { return m_quantity; }
    QStringList & getMachineList() { return m_machineList; }
    void addMachine(const QString & machine) { m_machineList.push_back(machine); }

signals:

public slots:

private:
    QString m_drawingNumber;
    QString m_material;
    double m_thickness;
    int m_quantity;
    QString m_filePath;
    QStringList m_machineList;
};

#endif // PARTINFO_H
