#include "finder.h"


void Finder::abort()
{
    m_abort = true;
}

void Finder::showPartList()
{
    qDebug() << "------------------------PART LIST---------------------------";
    for(auto elem : m_partList) {
        qDebug() << elem->getDrawingNumber() << " - " << elem->getMaterial() << " - " << elem->getThickness() << " - " << elem->getFilePath() << endl;
    }
    qDebug() << "------------------------END PART LIST---------------------------";
}

void Finder::sortPartList()
{
    qSort(m_partList.begin(), m_partList.end(),
          [](PartInfo * part1, PartInfo * part2) {
                return (part1->getDrawingNumber() < part2->getDrawingNumber());
    });
}

QStringList Finder::getItemsFromFile(QString fileName)
{
    QStringList list;
    QFile file(QDir::currentPath() + "\\" + fileName);
    if ( file.open(QIODevice::ReadWrite) ) {
        QString line;
        QTextStream t( &file );
        do {
            line = t.readLine();
            if(!line.isEmpty())
                list.append(line);
         } while (!line.isNull());
        file.close();
    }

    else {
        return QStringList();
    }

    return list;
}

QString Finder::defineMaterial(QString material)
{
    if(std::any_of(m_S235JRG2.begin(),m_S235JRG2.end(), [material](QString elem){ return material.contains(elem);}))
        return QString("S235JRG2");
    else if(std::any_of(m_S355J2G3.begin(),m_S355J2G3.end(), [material](QString elem){ return material.contains(elem);}))
        return QString("S355J2G3");
    else if(std::any_of(m_StainlessSteel.begin(),m_StainlessSteel.end(), [material](QString elem){ return material.contains(elem);}))
        return QString("Stainless Steel");

    return QString();
}

void Finder::loadFileList()
{
    emit signalProgress(100, "Wczytywanie harmonogramu ...");

    QXlsx::Document schedule(m_schedulePath);
    if(!checkSchedule(schedule)) {
        emit finished(false, "Harmonogram niepoprawnie sformatowany."); // failed
        return;
    }
    else {
        m_orderNumber = schedule.cellAt(1,9)->value().toString();
        m_deliveryDate = schedule.cellAt(3,4)->dateTime().toString("yyyyMMdd");
        m_client = schedule.cellAt(2,7)->value().toString();

        qDebug() << m_orderNumber << m_deliveryDate << m_client;
    }

    // find last row of schedule
    int lastRow = 0;
    if(!rowCount(schedule,lastRow)) {
        emit finished(false, "Harmonogram niepoprawnie sformatowany."); // failed
        return;
    }

    emit signalProgress(0, "Tworzenie listy części ...");
    for (int row = 7; row <= lastRow; ++row)
    {
        bool abort = m_abort;
        if (abort) {
            emit finished(false); // break
            return;
        }

        QString dxfPath = findFilePath(schedule.cellAt(row, 3)->value().toString());
        QString material =  defineMaterial(schedule.cellAt(row, 8)->value().toString());
        if(material.isEmpty()) {
            emit finished(false,"Nie dopasowano gatunku dla rysunku: "+schedule.cellAt(row, 3)->value().toString()+"");
            return;
        }

        m_partList.push_back(new PartInfo(schedule.cellAt(row, 3)->value().toString(), material, 0.0, schedule.cellAt(row, 5)->value().toInt(), dxfPath)); // TODO: Add thickness reading !!
        emit addItemToListWidget(schedule.cellAt(row, 3)->value().toString(), !dxfPath.isEmpty());
        emit signalProgress(int((double(row)/double(lastRow)*100))+1, "Tworzenie listy części ...");
    }

    sortPartList();
    showPartList();
    emit finished(true); // success
}

bool Finder::rowCount(QXlsx::Document &schedule, int & lastRow)
{
    for (int row = 7; row < 65536; ++row)
    {
        bool abort = m_abort;
        if (abort) {
            emit finished(false);
            return false;
        }

        if(QXlsx::Cell *cell=schedule.cellAt(row, 6))
        {
            if(cell->value() == QVariant("Masa")) {
                lastRow = row - 1;
                break;
            }
        }
    }

    return true;
}

QString Finder::findFilePath(const QString & filename)
{
    QDir dir(m_searchedFolder, QString("*.dxf"), QDir::NoSort, QDir::Files | QDir::NoSymLinks);
    QDirIterator counterIt(dir, QDirIterator::Subdirectories);
    filesCounter = 0;
    while (counterIt.hasNext()) {

            bool abort = m_abort;
            if (abort) {
                emit finished(false);
                break;
            }

            if(counterIt.fileName().contains(filename, Qt::CaseInsensitive)) {
                ++filesCounter;
                return counterIt.filePath();
            }
            counterIt.next();
    }
    if(filesCounter == 0)
        return QString("");

    return QString("");
}

bool Finder::checkSchedule(QXlsx::Document &schedule)
{
    QString orderDigit = schedule.cellAt(6, 2)->value().toString();
    QString drawingNr = schedule.cellAt(6, 3)->value().toString();
    QString cooperator = schedule.cellAt(6, 10)->value().toString();

    if( orderDigit.contains("L.p.") && drawingNr.contains("Nr rys.") && cooperator.contains("Kooperant") ) // TODO : Add thickness checking !!
        return true;
    else
        return false;
}

