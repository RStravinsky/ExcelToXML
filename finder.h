#ifndef FINDER_H
#define FINDER_H

#include <QObject>
#include <QtXlsx>
#include <QDir>
#include <QDirIterator>
#include <QThread>
#include <QtAlgorithms>
#include <QSet>
#include <QMetaType>
#include <QString>
#include <QFile>
#include <memory>
#include <utility>
#include <algorithm>
#include "partinfo.h"

class PartInfo;

class Finder : public QObject
{
    Q_OBJECT

public:
    explicit Finder(QObject *parent, const QString & schedulePath, const QString & searchedFolder = QString("//K1/Produkcja/TECHNOLODZY/BAZA DO TXT/txt/PLA/")) :
        QObject(parent), m_schedulePath(schedulePath), m_searchedFolder(searchedFolder)
    {
        m_abort = false;
        m_S235JRG2 = getItemsFromFile("S235JRG2.txt");
        m_S355J2G3 = getItemsFromFile("S355J2G3.txt");
        m_StainlessSteel = getItemsFromFile("StainlessSteel.txt");
        qDebug() << "S235JRG2.txt file: " << m_S235JRG2 << endl;
        qDebug() << "S355J2G3.txt file: " << m_S355J2G3 << endl;
        qDebug() << "StainlessSteel.txt file: " << m_StainlessSteel << endl;
    }

    void abort();
    QList<PartInfo*> & getPartList() { return m_partList; }
    QString getOrderNumber() { return m_orderNumber; }
    QString getDeliveryDate() { return m_deliveryDate; }
    QString getClient() { return m_client; }

signals:
    void signalProgress(int, QString);
    void finished(bool,QString = "");
    void addItemToListWidget(QString, bool);

public slots:
    void loadFileList();

private:
    QList<PartInfo*> m_partList;
    QString m_schedulePath;
    QString m_searchedFolder;
    bool m_abort;
    int filesCounter;
    QString m_orderNumber;
    QString m_deliveryDate;
    QString m_client;
    QStringList m_S235JRG2;
    QStringList m_S355J2G3;
    QStringList m_StainlessSteel;

    bool rowCount(QXlsx::Document & schedule, int &lastRow);
    bool checkSchedule(QXlsx::Document & schedule);
    QString findFilePath(const QString & filename);
    void showPartList();
    void sortPartList();
    QStringList getItemsFromFile(QString fileName);
    QString defineMaterial(QString material);
};

#endif // FINDER_H
