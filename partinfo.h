#ifndef PARTINFO_H
#define PARTINFO_H

#include <QObject>

class PartInfo : public QObject
{
    Q_OBJECT
public:
    explicit PartInfo(const QString & drawingNumber, const QString & material, double thickness, const QString & filePath = QString(), QObject *parent = 0) :
        m_drawingNumber(drawingNumber), m_material(material), m_thickness(thickness), m_filePath(filePath), QObject(parent) {}
    QString getDrawingNumber() { return m_drawingNumber; }
    QString getMaterial() { return m_material; }
    double getThickness() { return m_thickness; }
    QString getFilePath() { return m_filePath; }

signals:

public slots:

private:
    QString m_drawingNumber;
    QString m_material;
    double m_thickness;
    QString m_filePath;

};

#endif // PARTINFO_H
