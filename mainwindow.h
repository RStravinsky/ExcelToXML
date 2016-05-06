#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QDebug>
#include <QMessageBox>
#include <QtXml>
#include <memory>
#include <QThread>
#include "finder.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_excelPathBtn_released();
    void on_xmlPathBtn_released();
    void on_searchPathBtn_clicked();
    void on_convertButton_released();
    void on_excelPathLe_textChanged(const QString &arg1);
    void on_setValue(int value, QString labelText);
    void on_addItemToListWidget(QString itemName, bool isFound);
    void on_processingFinished(bool isSuccess, QString information);

private:
    Ui::MainWindow *ui;
    QThread * finderThread{nullptr};
    Finder * finder{nullptr};
    QXmlStreamWriter xml;
    QString schedulePath;
    void createCommandTag(std::unique_ptr<QXmlStreamWriter> &xml);
    bool createXML();
    QXmlStreamWriter * xmlWriter;
    void fillMachines();
    QStringList getItemsFromFile(QString fileName);
    bool generatePartList();
};

#endif // MAINWINDOW_H
