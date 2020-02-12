#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "phoneaddressbookmodel.h"
#include "dialog.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionOpen_Address_Book_triggered();

    void on_tableView_clicked(const QModelIndex &index);

    void on_zeroButton_clicked();

    void on_nineButton_clicked();

    void on_eightButton_clicked();

    void on_sevenButton_clicked();

    void on_sixButton_clicked();

    void on_fiveButton_clicked();

    void on_fourButton_clicked();

    void on_threeButton_clicked();

    void on_twoButton_clicked();

    void on_oneButton_clicked();

    void on_pushButton_clicked();

    void on_actionExit_3_triggered();

    void on_asteriskButton_clicked();

    void on_poundButton_clicked();

    void on_callButton_clicked();

    void on_backSpaceButton_clicked();

    void on_backButton_clicked();

private:
    Ui::MainWindow *ui;
    PhoneAddressBookModel *myModel;
    Dialog* dialMessage;
    QPixmap imagePhone;
    QString dialedNumber;

    void loadImage();
    void formatNumber(QString& phoneNumber); //Format dialed number as (xxx)-xxx-xxxx
};
#endif // MAINWINDOW_H
