#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_excelBtn_released()
{
    ui->excelPathLe->setText(QFileDialog::getOpenFileName(this, tr("Wybierz harmonogram"), tr(""), tr("Pliki XLSX (*.xlsx)")));
}

void MainWindow::on_loadListButton_released()
{
    Finder f(this, ui->excelPathLe->text());

    f.loadFileList();
    f.showPartList();

}
