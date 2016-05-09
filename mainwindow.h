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
    void on_fitBtn_clicked();

private:
    Ui::MainWindow *ui;
    QThread * m_finderThread{nullptr};
    Finder * m_finder{nullptr};
    QString m_schedulePath;
    void createCommandTag(std::unique_ptr<QXmlStreamWriter> &xml, PartInfo * partInfo, int counter);
    bool createXML();
    void fillMachines();
    QStringList getItemsFromFile(QString fileName);
    void generatePartList();
    void setProcessing(bool isEnabled);
    bool processing{false};
};

#endif // MAINWINDOW_H
