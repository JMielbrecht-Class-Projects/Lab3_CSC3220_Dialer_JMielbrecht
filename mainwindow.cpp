#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFileDialog>
#include <iostream>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , myModel(new PhoneAddressBookModel(this))
{
    ui->setupUi(this);
    ui->tableView->setModel(myModel);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionOpen_Address_Book_triggered()
{
    QString filename = QFileDialog::getOpenFileName(this,
                                                    tr("Open Address Book"), "",
                                                    tr("Address Book (*.csv);;All Files (*)"));
    std::cout << filename.toStdString() << std::endl;

    myModel->openFile(filename);
}
