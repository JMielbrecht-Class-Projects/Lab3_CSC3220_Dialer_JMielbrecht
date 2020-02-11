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
    ui->numDisplay->setText(myModel->getPhoneNumber(index.row()));
}

void MainWindow::loadImage(){
    QString phoneImageFile = ":/Images/oldPhoneIcon4.jpg";

    if(imagePhone.load(phoneImageFile)) {
        std::cout << "Image Loaded" << std::endl;
        imagePhone = imagePhone.scaled(ui->phoneIcon->size(), Qt::KeepAspectRatio);
    }
    ui->phoneIcon->setPixmap(imagePhone);
}

void MainWindow::formatNumber(QString &phoneNumber)
{
    if(phoneNumber.length() == 4){
        phoneNumber.insert(3, "-"); //Add dash -> xxx-x
    }else if(phoneNumber.length() == 8){
        phoneNumber.insert(7, "-"); //Number: xxx-xxx-x...
    }
    //Final number should look like this: xxx-xxx-xxxx
}

void MainWindow::on_zeroButton_clicked()
{
    if(phoneNumber.length() <= 11){
        phoneNumber.append("0");
        ui->numDisplay->setText(phoneNumber);
    }
}

void MainWindow::on_nineButton_clicked()
{
    if(phoneNumber.length() <= 11){
        phoneNumber.append("9");
        formatNumber(phoneNumber);
        ui->numDisplay->setText(phoneNumber);
    }
}

void MainWindow::on_eightButton_clicked()
{
    if(phoneNumber.length() <= 11){
        phoneNumber.append("8");
        formatNumber(phoneNumber);
        ui->numDisplay->setText(phoneNumber);
    }
}

void MainWindow::on_sevenButton_clicked()
{
    if(phoneNumber.length() <= 11){
        phoneNumber.append("7");
        formatNumber(phoneNumber);
        ui->numDisplay->setText(phoneNumber);
    }
}

void MainWindow::on_sixButton_clicked()
{
    if(phoneNumber.length() <= 11){
        phoneNumber.append("6");
        formatNumber(phoneNumber);
        ui->numDisplay->setText(phoneNumber);
    }
}

void MainWindow::on_fiveButton_clicked()
{
    if(phoneNumber.length() <= 11){
        phoneNumber.append("5");
        formatNumber(phoneNumber);
        ui->numDisplay->setText(phoneNumber);
    }
}

void MainWindow::on_fourButton_clicked()
{
    if(phoneNumber.length() <= 11){
        phoneNumber.append("4");
        formatNumber(phoneNumber);
        ui->numDisplay->setText(phoneNumber);
    }
}

void MainWindow::on_threeButton_clicked()
{
    if(phoneNumber.length() <= 11){
        phoneNumber.append("3");
        formatNumber(phoneNumber);
        ui->numDisplay->setText(phoneNumber);
    }
}

void MainWindow::on_twoButton_clicked()
{
    if(phoneNumber.length() <= 11){
        phoneNumber.append("2");
        formatNumber(phoneNumber);
        ui->numDisplay->setText(phoneNumber);
    }
}

void MainWindow::on_oneButton_clicked()
{
    if(phoneNumber.length() <= 11){
        phoneNumber.append("1");
        formatNumber(phoneNumber);
        ui->numDisplay->setText(phoneNumber);
    }
}
