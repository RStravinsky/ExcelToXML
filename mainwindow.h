#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QDebug>
#include <QMessageBox>
#include <QtXml>
#include <iostream>
#include <memory>

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

private:
    Ui::MainWindow *ui;
    QXmlStreamWriter xml;
    void createCommandTag(std::unique_ptr<QXmlStreamWriter> &xml);
    bool createXML();
    QXmlStreamWriter * xmlWriter;
};

#endif // MAINWINDOW_H
