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
#include "partinfo.h"

class PartInfo;

class Finder : public QObject
{
    Q_OBJECT

public:
    explicit Finder(QObject *parent, const QString & schedulePath, const QString & searchedFolder = QString("//K1/Produkcja/TECHNOLODZY/BAZA DO TXT/txt/PLA/")) :
        QObject(parent), m_schedulePath(schedulePath), m_searchedFolder(searchedFolder) { m_abort = false; qDebug() << m_schedulePath; }
    void abort();
    void showPartList();
    void sortPartList();
    QList<PartInfo*> & getPartList() { return m_partList; }

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
    bool rowCount(QXlsx::Document & schedule, int &lastRow);
    bool checkSchedule(QXlsx::Document & schedule);
    QString findFilePath(const QString & filename);
};

#endif // FINDER_H
