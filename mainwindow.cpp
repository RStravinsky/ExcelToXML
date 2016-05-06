#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    fillMachines();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_excelPathBtn_released()
{
    QString path = QFileDialog::getOpenFileName(this,tr("Wybierz harmonogram"), QDir::currentPath(), tr("Excel (*.xlsx)"));

    if(!path.isEmpty()) { // TODO - prevent loading existing schedule
        schedulePath = path;
        ui->excelPathLe->setText(path);
        generatePartList();
    }
}

void MainWindow::on_excelPathLe_textChanged(const QString &arg1)
{
    ui->fitBtn->setEnabled(!arg1.isEmpty());
    ui->machineryCb->setEnabled(!arg1.isEmpty());
}

void MainWindow::on_xmlPathBtn_released()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Zapisz plik XML"), QDir::currentPath(), tr("XML (*.xml)"));
    if(!fileName.isEmpty()) ui->xmlPathLe->setText(fileName);
}

void MainWindow::on_searchPathBtn_clicked()
{
    QString dir = QFileDialog::getExistingDirectory(this, tr("Wybierz ścieżkę wyszukiwania"), "//k1/Produkcja/TECHNOLODZY/BAZA_DO_TXT/txt", QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);
    if(!dir.isEmpty()) ui->searchPathLe->setText(dir);
}

void MainWindow::on_convertButton_released()
{
    QStringList missingPaths;
    if( ui->searchPathLe->text().isEmpty() || !ui->searchPathLe->text().contains("/"))
        missingPaths << "ścieżka wyszukiwania";
    if( ui->xmlPathLe->text().isEmpty() || !ui->xmlPathLe->text().contains("/"))
        missingPaths << "ścieżka pliku XML";
    if( ui->excelPathLe->text().isEmpty() || !ui->excelPathLe->text().contains("xlsx"))
        missingPaths << "ścieżka harmonogramu";

    if (!missingPaths.isEmpty()) {
        QMessageBox::information(this, tr("Informacja"), QString("Brakujące ścieżki: "+missingPaths.join(",")+"" + "."));
        return;
    }
    else {
        if(createXML()){
            QMessageBox::information(this, tr("Informacja"), QString("Wygenerowano plik XML."));
        }
    }
}

void MainWindow::createCommandTag(std::unique_ptr<QXmlStreamWriter> &xml, PartInfo * partInfo)
{
    qDebug() << "Drawing number: " << partInfo->getDrawingNumber() << endl;

    QStringList TblRef(QStringList() << "PRODUCTS" << "PRODUCT OPERATIONS" << "IMPORTGEO" << "MANUFACTURING");
    QStringList FldRefFirst(QStringList()  << "PrdRef" << "PrdRef" << "Product");
    QStringList FldRefSecond(QStringList() << "MatRef" << "WrkRef" << "GeometryType");
    QStringList FldRefThird(QStringList()  << "Height" << "OprRef" << "GeometryPath");
    QStringList FldRefFourth(QStringList()  << "mnOID" << "PrdRefDst" << "Descrip" << "OrdRef" << "ComName" << "RQ" << "DDate");

    for(int i=0;i<3;++i) {

        xml->writeStartElement("COMMAND");

        xml->writeAttribute("Name","Import");
        xml->writeAttribute("TblRef",TblRef[i]);

        // first line
        xml->writeStartElement("Field");
        xml->writeAttribute("FldRef",FldRefFirst[i]);
        xml->writeAttribute("FldValue","Indeks_detalu"); // drawing number ALWAYS
        xml->writeAttribute("FldType", "20");
        xml->writeEndElement();

        // second line
        xml->writeStartElement("Field");
        xml->writeAttribute("FldRef",FldRefSecond[i]);
        xml->writeAttribute("FldValue",(i==0) ? partInfo->getMaterial() : (i==1 ? "Eckert" : "DXF")); // i=0 - TYPE , i=1 - MACHINE, i=2 = "DXF"
        xml->writeAttribute("FldType","20");
        xml->writeEndElement();

        // third line
        xml->writeStartElement("Field");
        xml->writeAttribute("FldRef",FldRefThird[i]);
        xml->writeAttribute("FldValue",(i==0) ? QString::number(partInfo->getThickness()) : (i==1 ? "2D Cut" : partInfo->getDrawingNumber())); // i=0 - HEIGHT , i=1 - "2D CUT", i=2 = DXF PATH
        xml->writeAttribute("FldType",(i==0) ? "100": "20");
        xml->writeEndElement();

        xml->writeEndElement(); // Command
    }

    xml->writeStartElement("COMMAND");
    xml->writeAttribute("Name","Import");
    xml->writeAttribute("TblRef",TblRef[TblRef.size()-1]); // MANUFACTURING

    for(int i=0;i<7;++i) {
        xml->writeStartElement("Field");
        xml->writeAttribute("FldRef",FldRefFourth[i]);
        xml->writeAttribute("FldValue","Indeks_detalu"); // drawing number ALWAYS
        xml->writeAttribute("FldType", (i==5) ? "30" : (i==6 ? "120" : "20"));
        xml->writeEndElement();
    }

    xml->writeEndElement(); // Command
}

bool MainWindow::createXML()
{
    QFile file(ui->xmlPathLe->text());
    if (!file.open(QFile::WriteOnly | QFile::Text)) {
        QMessageBox::warning(this, tr("Uwaga"), QString("Nie można otworzyć pliku XML."));
        return false;
    }

    std::unique_ptr<QXmlStreamWriter> xmlWriter(new QXmlStreamWriter(&file));
    xmlWriter->setAutoFormatting(true);

    xmlWriter->writeStartDocument();
    xmlWriter->writeStartElement("DATAEX");

    //for(int i=0; i<finder->getPartList().size(); ++i)
    //    createCommandTag(xmlWriter, finder->getPartList().at(i));

    xmlWriter->writeEndElement(); // Dataex
    xmlWriter->writeEndDocument();

    file.close();
    if (file.error()) {
        QMessageBox::warning(this, tr("Uwaga"), QString("Nie można otworzyć pliku XML."));
        return false;
    }

    return true;
}

bool MainWindow::generatePartList()
{
    if(finder!=nullptr) delete finder;
    if(finderThread!=nullptr) delete finderThread;

    finder = new Finder(0,ui->excelPathLe->text());
    finderThread = new QThread;
    finder->moveToThread(finderThread);

    QObject::connect( finder, SIGNAL(finished(bool,QString)), this, SLOT(on_processingFinished(bool,QString)));
    QObject::connect( finder, SIGNAL(addItemToListWidget(QString,bool)), this, SLOT(on_addItemToListWidget(QString,bool)));
    QObject::connect( finder, SIGNAL(signalProgress(int,QString) ), this, SLOT(on_setValue(int,QString)));

    QObject::connect( finderThread, SIGNAL(started()), finder, SLOT(loadFileList())); // start searching
    QObject::connect( finder, SIGNAL(finished(bool,QString)), finderThread, SLOT(quit()),Qt::DirectConnection);

    finderThread->start();
}

void MainWindow::on_setValue(int value, QString labelText)
{
    ui->progressBar->setValue(value);
    ui->statusLabel->setText(labelText);
}

void MainWindow::on_addItemToListWidget(QString itemName, bool isFound)
{
    QListWidgetItem * item = new QListWidgetItem(itemName);

    item->setFlags(item->flags() | Qt::ItemIsUserCheckable);
    item->setCheckState(Qt::Unchecked);
    if(!isFound) item->setForeground(QBrush(QColor(Qt::red)));

    ui->listWidget->insertItem(0,item);
}

void MainWindow::on_processingFinished(bool isSuccess, QString information)
{
    ui->statusLabel->clear();
    if (isSuccess)
        ui->progressBar->setValue(100);
    else {
        ui->listWidget->clear();
        ui->progressBar->setValue(0);

        if(!information.isEmpty()) {
            QMessageBox emptyListMessage;
            emptyListMessage.setWindowIcon(QIcon(":/images/images/logo.png"));
            emptyListMessage.setIcon(QMessageBox::Information);
            emptyListMessage.setText(information);
            emptyListMessage.setWindowTitle("Informacja");
            emptyListMessage.exec();
        }
    }

    if(ui->listWidget->count() != 0)
       ui->listWidget->sortItems(Qt::AscendingOrder);
}

void MainWindow::fillMachines()
{
    QStringList list;
    list = getItemsFromFile("MACHINERY.txt");
    ui->machineryCb->clear();
    ui->machineryCb->addItems(list);
}

QStringList MainWindow::getItemsFromFile(QString fileName)
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
        QMessageBox::warning(this, tr("Uwaga"), QString("Nie można otworzyć pliku z danymi."));
        return QStringList();
    }

    return list;
}

void MainWindow::on_fitBtn_clicked()
{
    bool isChecked = false;
    for(int i=0;i<ui->listWidget->count();++i) {
        if(ui->listWidget->item(i)->checkState()) {
            isChecked = true;
            ui->listWidget->item(i)->setIcon(QIcon(":/images/images/found.png"));
            // TODO
        }
        ui->listWidget->item(i)->setCheckState(Qt::Unchecked);
    }

    if(!isChecked)
        QMessageBox::information(this, tr("Informacja"), QString("Nie zaznaczono wierszy."));
}
