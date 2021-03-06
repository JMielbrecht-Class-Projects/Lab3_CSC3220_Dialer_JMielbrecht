#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dialog.h"
#include <QFileDialog>
#include <iostream>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , myModel(new PhoneAddressBookModel(this))
{
    ui->setupUi(this);
    ui->tableView->setModel(myModel);
    ui->numDisplay->setText("");

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
    dialedNumber = myModel->getPhoneNumber(index.row());
    ui->numDisplay->setText(dialedNumber); //Number shows up on screen
    myModel->setFilterString(dialedNumber); //Number used to filter address book

}

void MainWindow::loadImage(){
    QString phoneImageFile = ":/Images/oldPhoneIcon4.jpg";

    if(imagePhone.load(phoneImageFile)) {
        std::cout << "Image Loaded" << std::endl;
        imagePhone = imagePhone.scaled(ui->phoneIcon->size(), Qt::KeepAspectRatio); //Loads iamge of phone.
    }
    ui->phoneIcon->setPixmap(imagePhone);
}

void MainWindow::formatNumber(QString &phoneNumber)
{
    //"Clean" number of formatting
    for(int i = 0; i < phoneNumber.length(); i++){
        if(phoneNumber.at(i) == "-"){
            phoneNumber.remove(i, 1);
        }
    }

    for(int j = 0; j < phoneNumber.length(); j++){
        if(j == 4){
            phoneNumber.insert(j-1, "-"); //Add dash -> xxx-x
        }else if(j == 8){
            phoneNumber.insert(j-1, "-"); //Number: xxx-xxx-x...
        }
    }

    //Final number should look like this: xxx-xxx-xxxx
}

void MainWindow::on_zeroButton_clicked()
{
    if(dialedNumber.length() <= 11){
        dialedNumber.append("0");
        ui->numDisplay->setText(dialedNumber);
        myModel->setFilterString(dialedNumber); //Number used to filter address book
    }
}

void MainWindow::on_nineButton_clicked()
{
    if(dialedNumber.length() <= 11){
        dialedNumber.append("9");
        formatNumber(dialedNumber);
        ui->numDisplay->setText(dialedNumber);
        myModel->setFilterString(dialedNumber); //Number used to filter address book
    }
}

void MainWindow::on_eightButton_clicked()
{
    if(dialedNumber.length() <= 11){
        dialedNumber.append("8");
        formatNumber(dialedNumber);
        ui->numDisplay->setText(dialedNumber);
        myModel->setFilterString(dialedNumber); //Number used to filter address book
    }
}

void MainWindow::on_sevenButton_clicked()
{
    if(dialedNumber.length() <= 11){
        dialedNumber.append("7");
        formatNumber(dialedNumber);
        ui->numDisplay->setText(dialedNumber);
        myModel->setFilterString(dialedNumber); //Number used to filter address book
    }
}

void MainWindow::on_sixButton_clicked()
{
    if(dialedNumber.length() <= 11){
        dialedNumber.append("6");
        formatNumber(dialedNumber);
        ui->numDisplay->setText(dialedNumber);
        myModel->setFilterString(dialedNumber); //Number used to filter address book
    }
}

void MainWindow::on_fiveButton_clicked()
{
    if(dialedNumber.length() <= 11){
        dialedNumber.append("5");
        formatNumber(dialedNumber);
        ui->numDisplay->setText(dialedNumber);
        myModel->setFilterString(dialedNumber); //Number used to filter address book
    }
}

void MainWindow::on_fourButton_clicked()
{
    if(dialedNumber.length() <= 11){
        dialedNumber.append("4");
        formatNumber(dialedNumber);
        ui->numDisplay->setText(dialedNumber);
        myModel->setFilterString(dialedNumber); //Number used to filter address book
    }
}

void MainWindow::on_threeButton_clicked()
{
    if(dialedNumber.length() <= 11){
        dialedNumber.append("3");
        formatNumber(dialedNumber);
        ui->numDisplay->setText(dialedNumber);
        myModel->setFilterString(dialedNumber); //Number used to filter address book
    }
}

void MainWindow::on_twoButton_clicked()
{
    if(dialedNumber.length() <= 11){
        dialedNumber.append("2");
        formatNumber(dialedNumber);
        ui->numDisplay->setText(dialedNumber);
        myModel->setFilterString(dialedNumber); //Number used to filter address book
    }
}

void MainWindow::on_oneButton_clicked()
{
    if(dialedNumber.length() <= 11){
        dialedNumber.append("1");
        formatNumber(dialedNumber);
        ui->numDisplay->setText(dialedNumber);
        myModel->setFilterString(dialedNumber); //Number used to filter address book
    }
}



void MainWindow::on_actionExit_3_triggered()
{
    exit(0); //Exit application
}

void MainWindow::on_asteriskButton_clicked()
{
    if(dialedNumber.length() <= 11){
        dialedNumber.append("*");
        formatNumber(dialedNumber);
        ui->numDisplay->setText(dialedNumber);
        myModel->setFilterString(dialedNumber); //Number used to filter address book
}
}
void MainWindow::on_poundButton_clicked()
{
    if(dialedNumber.length() <= 11){
        dialedNumber.append("#");
        formatNumber(dialedNumber);
        ui->numDisplay->setText(dialedNumber);
        myModel->setFilterString(dialedNumber); //Number used to filter address book
}
}

void MainWindow::on_callButton_clicked()
{
    std::cout << "Works" << std::endl;

    //Open up dialog box
    dialMessage = new Dialog(this);
    dialMessage->setModal(true);
    dialMessage->setMessageText(dialedNumber);
    dialMessage->show();

    //Erase number from dialpad
    dialedNumber = "";
    ui->numDisplay->setText(dialedNumber);
}



void MainWindow::on_backSpaceButton_clicked()
{
    dialedNumber = dialedNumber.remove(dialedNumber.length()-1, 1);
    formatNumber(dialedNumber);
    ui->numDisplay->setText(dialedNumber);
    myModel->setFilterString(dialedNumber); //Number used to filter address book
    std::cout << "Works" << std::endl;
}

void MainWindow::on_backButton_clicked()
{
    dialedNumber = dialedNumber.remove(dialedNumber.length()-1, 1);
    formatNumber(dialedNumber);
    ui->numDisplay->setText(dialedNumber);
    myModel->setFilterString(dialedNumber); //Number used to filter address book
}
