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
    //ui->zeroButton->textArea.readOnly = true;
    loadImage();
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

void MainWindow::on_tableView_clicked(const QModelIndex &index)
{
    std::cout << index.row() << "," << index.column() << std::endl;
    ui->label->setText(myModel->getPhoneNumber(index.row()));
}

void MainWindow::loadImage(){
    QString phoneImageFile = ":/Images/oldPhoneIcon4.jpg";

    if(imagePhone.load(phoneImageFile)) {
        std::cout << "Image Loaded" << std::endl;
        imagePhone = imagePhone.scaled(ui->phoneIcon->size(), Qt::KeepAspectRatio);
    }
    ui->phoneIcon->setPixmap(imagePhone);
}

void MainWindow::on_zeroButton_clicked()
{
    while(phoneNumber.length() <= 9){
        phoneNumber.append("0");
    }
}

void MainWindow::on_nineButton_clicked()
{
    while(phoneNumber.length() <= 9){
        phoneNumber.append("9");
    }
}

void MainWindow::on_eightButton_clicked()
{
    while(phoneNumber.length() <= 9){
        phoneNumber.append("8");
    }
}

void MainWindow::on_sevenButton_clicked()
{
    while(phoneNumber.length() <= 9){
        phoneNumber.append("7");
    }
}

void MainWindow::on_sixButton_clicked()
{
    while(phoneNumber.length() <= 9){
        phoneNumber.append("6");
    }
}

void MainWindow::on_fiveButton_clicked()
{
    while(phoneNumber.length() <= 9){
        phoneNumber.append("5");
    }
}

void MainWindow::on_fourButton_clicked()
{
    while(phoneNumber.length() <= 9){
        phoneNumber.append("4");
    }
}

void MainWindow::on_threeButton_clicked()
{
    while(phoneNumber.length() <= 9){
        phoneNumber.append("3");
    }
}

void MainWindow::on_twoButton_clicked()
{
    while(phoneNumber.length() <= 9){
        phoneNumber.append("2");
    }
}

void MainWindow::on_oneButton_clicked()
{
    while(phoneNumber.length() <= 9){
        phoneNumber.append("1");
    }
}
