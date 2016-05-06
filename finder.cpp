#include "finder.h"


void Finder::abort()
{
    m_abort = true;
}

void Finder::showPartList()
{
    for(auto elem : m_partList) {
        qDebug() << elem->getDrawingNumber() << " - " << elem->getMaterial() << " - " << elem->getThickness() << " - " << elem->getFilePath() << endl;
    }
}

bool Finder::loadFileList()
{
    emit signalProgress(100, "Wczytywanie harmonogramu ...");
    //QXlsx::Document schedule(QString("\"%1\")").arg(m_schedulePath));
    QXlsx::Document schedule(m_schedulePath);
    if(!checkSchedule(schedule)) {
        emit finished(false, "Harmonogram niepoprawnie sformatowany.");
        return false;
    }

    // find last row of schedule
    int lastRow = 0;
    if(!rowCount(schedule,lastRow))
        return false;

    qDebug() << "lastRow: " << lastRow;

    for (int row = 7; row <= lastRow; ++row)
    {
        bool abort = m_abort;
        if (abort) {
            emit finished(false);
            return false;
        }

        //if (QXlsx::Cell *cell=schedule.cellAt(row, 3))
            m_partList.push_back(new PartInfo(schedule.cellAt(row, 3)->value().toString(), schedule.cellAt(row, 8)->value().toString(), 0.0, findFilePath(schedule.cellAt(row, 3)->value().toString()))); // TODO: Add thickness reading !!

        emit signalProgress(int((double(row)/double(lastRow)*100))+1, "Tworzenie listy części ...");
    }

    qDebug() << "Part list size: " << m_partList.size();
    return true;
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


            if(cell->value() == QVariant("Masa"))
            {
                lastRow = row - 2;
                break;
            }
        }

    }

    return true;
}


QString Finder::findFilePath(const QString & filename)
{
    emit signalProgress( 100, "Szukanie pliku .dxf ...");
    QDir dir(QDir::currentPath(), QString("*.dxf"), QDir::NoSort, QDir::Files | QDir::NoSymLinks);
    QDirIterator counterIt(dir, QDirIterator::Subdirectories);
    filesCounter = 0;
    while (counterIt.hasNext()) {
            bool abort = m_abort;
            if (abort) {
                emit finished(false);
                return QString("");
            }


            if(counterIt.fileName().contains(filename, Qt::CaseInsensitive)) {
                ++filesCounter;
                return counterIt.filePath();
            }
            counterIt.next();
    }
    if(filesCounter == 0) {
        emit finished(false, "Nie znaleziono pliku .dxf.");
        return QString("");
    }

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

