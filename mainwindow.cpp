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
    if(m_finder!=nullptr) {
        m_finder->abort();
        m_finderThread->wait();
        delete m_finderThread;
        delete m_finder;
    }

    delete ui;
}

void MainWindow::setProcessing(bool isEnabled)
{
    if(isEnabled) {
        processing = true;
        ui->searchPathLe->setEnabled(false);
        ui->excelPathLe->setEnabled(false);
        ui->xmlPathLe->setEnabled(false);
        ui->fitBtn->setEnabled(false);
        ui->machineryCb->setEnabled(false);
        ui->convertButton->setText("Anuluj");
        ui->convertButton->setIcon(QIcon(":/images/images/cancel.png"));
    }
    else {
        processing = false;
        ui->searchPathLe->setEnabled(true);
        ui->excelPathLe->setEnabled(true);
        ui->xmlPathLe->setEnabled(true);
        ui->fitBtn->setEnabled(true);
        ui->machineryCb->setEnabled(true);
        ui->convertButton->setText("Konwertuj");
        ui->convertButton->setIcon(QIcon(":/images/images/convert.png"));
    }
}

void MainWindow::on_excelPathBtn_released()
{
    if(!processing){
        QString path = QFileDialog::getOpenFileName(this,tr("Wybierz harmonogram"), QDir::currentPath(), tr("Excel (*.xlsx)"));

        if(!path.isEmpty()) { // TODO - prevent loading existing schedule
            m_schedulePath = path;
            ui->excelPathLe->setText(path);
            generatePartList();
        }
    }
    else QMessageBox::information(this,"Informacja","Nie można wybrać ścieżki dostępu podczas wyszukiwania.");
}

void MainWindow::on_excelPathLe_textChanged(const QString &arg1)
{
    ui->fitBtn->setEnabled(!arg1.isEmpty());
    ui->machineryCb->setEnabled(!arg1.isEmpty());
}

void MainWindow::on_xmlPathBtn_released()
{
    if(!processing) {
        QString fileName = QFileDialog::getSaveFileName(this, tr("Zapisz plik XML"), QDir::currentPath(), tr("XML (*.xml)"));
        if(!fileName.isEmpty()) ui->xmlPathLe->setText(fileName);
    }
    else QMessageBox::information(this,"Informacja","Nie można wybrać ścieżki dostępu podczas wyszukiwania.");
}

void MainWindow::on_searchPathBtn_clicked()
{
    if(!processing) {
        QString dir = QFileDialog::getExistingDirectory(this, tr("Wybierz ścieżkę wyszukiwania"), "//k1/Produkcja/TECHNOLODZY/BAZA DO TXT/txt", QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);
        if(!dir.isEmpty()) ui->searchPathLe->setText(dir);
    }
    else QMessageBox::information(this,"Informacja","Nie można wybrać ścieżki dostępu podczas wyszukiwania.");
}

void MainWindow::on_convertButton_released()
{
    if(!processing) {

//        QStringList missingPaths;
//        if( ui->searchPathLe->text().isEmpty() || !ui->searchPathLe->text().contains("/"))
//            missingPaths << "ścieżka wyszukiwania";
//        if( ui->xmlPathLe->text().isEmpty() || !ui->xmlPathLe->text().contains("/"))
//            missingPaths << "ścieżka pliku XML";
//        if( ui->excelPathLe->text().isEmpty() || !ui->excelPathLe->text().contains("xlsx"))
//            missingPaths << "ścieżka harmonogramu";

//        if (!missingPaths.isEmpty()) {
//            QMessageBox::information(this, tr("Informacja"), QString("Brakujące ścieżki: "+missingPaths.join(",")+"" + "."));
//            return;
//        }
//        else {
//            for(int i=0; i<m_finder->getPartList().size(); ++i) {
//                if(m_finder->getPartList().at(i)->getMachine().isEmpty()){
//                    QMessageBox::information(this, tr("Informacja"), QString("Nie wybrano maszyny dla wszystkich części."));
//                    return;
//                }
//            }
            if(createXML()){
                QMessageBox::information(this, tr("Informacja"), QString("Wygenerowano plik XML."));
            }
//        }

    }

    else {
        ui->statusLabel->setText("Anulowanie ...");
        m_finder->abort();
        m_finderThread->wait();
        delete m_finderThread;
        delete m_finder;
        m_finder = nullptr;
        m_finderThread = nullptr;
    }
}

void MainWindow::createCommandTag(std::unique_ptr<QXmlStreamWriter> &xml, PartInfo * partInfo, int counter)
{
    QStringList TblRef(QStringList() << "PRODUCTS" << "PRODUCT OPERATIONS" << "IMPORTGEO" << "MANUFACTURING");
    QStringList FldRefFirst(QStringList()  << "PrdRef" << "PrdRef" << "Product");
    QStringList FldRefSecond(QStringList() << "MatRef" << "WrkRef" << "GeometryType");
    QStringList FldRefThird(QStringList()  << "Height" << "OprRef" << "GeometryPath");
    QStringList FldRefFourth(QStringList()  << "MnOID" << "PrdRefDst" << "OrdRef" << "ComName" << "RQ" << "DDate");
    QStringList ManufacturingFields;
    ManufacturingFields << m_finder->getOrderNumber() + "_" + QString::number(counter) // mnIDO
                        << partInfo->getDrawingNumber() // PrdRefDst
                        << m_finder->getOrderNumber() // OrdRef
                        << m_finder->getClient() // ComName
                        << QString::number(partInfo->getQuantity()) // RQ
                        << m_finder->getDeliveryDate(); // DDate

    for(int i=0;i<3;++i) {

        xml->writeStartElement("COMMAND");

        xml->writeAttribute("Name","Import");
        xml->writeAttribute("TblRef",TblRef[i]);

        // first line
        xml->writeStartElement("Field");
        xml->writeAttribute("FldRef",FldRefFirst[i]);
        xml->writeAttribute("FldValue", partInfo->getDrawingNumber()); // drawing number ALWAYS
        xml->writeAttribute("FldType", "20");
        xml->writeEndElement();

        // second line
        xml->writeStartElement("Field");
        xml->writeAttribute("FldRef",FldRefSecond[i]);
        xml->writeAttribute("FldValue",(i==0) ? partInfo->getMaterial() : (i==1 ? "MASZYNA" : "DXF")); // i=0 - TYPE , i=1 - MACHINE, i=2 = "DXF"
        xml->writeAttribute("FldType","20");
        xml->writeEndElement();

        // third line
        xml->writeStartElement("Field");
        xml->writeAttribute("FldRef",FldRefThird[i]);
        xml->writeAttribute("FldValue",(i==0) ? QString::number(partInfo->getThickness()) : (i==1 ? "2D Cut" : partInfo->getFilePath())); // i=0 - HEIGHT , i=1 - "2D CUT", i=2 = DXF PATH
        xml->writeAttribute("FldType",(i==0) ? "100": "20");
        xml->writeEndElement();

        xml->writeEndElement(); // Command
    }

    xml->writeStartElement("COMMAND");
    xml->writeAttribute("Name","Import");
    xml->writeAttribute("TblRef",TblRef[TblRef.size()-1]); // MANUFACTURING

    for(int i=0;i<6;++i) {
        xml->writeStartElement("Field");
        xml->writeAttribute("FldRef",FldRefFourth[i]);
        xml->writeAttribute("FldValue",ManufacturingFields[i]); // drawing number ALWAYS
        xml->writeAttribute("FldType", (i==4) ? "30" : (i==5 ? "120" : "20"));
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

    for(int i=0; i<m_finder->getPartList().size(); ++i)
        createCommandTag(xmlWriter, m_finder->getPartList().at(i), i);

    xmlWriter->writeEndElement(); // Dataex
    xmlWriter->writeEndDocument();

    file.close();
    if (file.error()) {
        QMessageBox::warning(this, tr("Uwaga"), QString("Nie można otworzyć pliku XML."));
        return false;
    }

    return true;
}

void MainWindow::generatePartList()
{
    setProcessing(true);

    if(m_finder!=nullptr) delete m_finder;
    if(m_finderThread!=nullptr) delete m_finderThread;
    ui->listWidget->clear();

    m_finder = new Finder(0,ui->excelPathLe->text(),ui->searchPathLe->text());
    m_finderThread = new QThread;
    m_finder->moveToThread(m_finderThread);

    QObject::connect( m_finder, SIGNAL(finished(bool,QString)), this, SLOT(on_processingFinished(bool,QString)));
    QObject::connect( m_finder, SIGNAL(addItemToListWidget(QString,bool)), this, SLOT(on_addItemToListWidget(QString,bool)));
    QObject::connect( m_finder, SIGNAL(signalProgress(int,QString) ), this, SLOT(on_setValue(int,QString)));

    QObject::connect( m_finderThread, SIGNAL(started()), m_finder, SLOT(loadFileList())); // start searching
    QObject::connect( m_finder, SIGNAL(finished(bool,QString)), m_finderThread, SLOT(quit()),Qt::DirectConnection);

    m_finderThread->start();
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
    setProcessing(false);

    ui->statusLabel->clear();
    if (isSuccess) {
        ui->progressBar->setValue(100);
        if(ui->listWidget->count() != 0)
           ui->listWidget->sortItems(Qt::AscendingOrder);
    }
    else {
        ui->progressBar->setValue(0);
        ui->listWidget->clear();
        if(!information.isEmpty()) {
            QMessageBox::information(this,"Informacja",information);
        }
    }
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
    if(processing) return;

    bool isChecked = false;
    for(int i=0;i<ui->listWidget->count();++i) {
        if(ui->listWidget->item(i)->checkState()) {
            isChecked = true;
            ui->listWidget->item(i)->setIcon(QIcon(":/images/images/checked.png"));
            //m_finder->getPartList().at(i)->setMachine(ui->machineryCb->currentText());
        }
        ui->listWidget->item(i)->setCheckState(Qt::Unchecked);
    }

    if(!isChecked)
        QMessageBox::information(this, tr("Informacja"), QString("Nie zaznaczono wierszy."));
}

