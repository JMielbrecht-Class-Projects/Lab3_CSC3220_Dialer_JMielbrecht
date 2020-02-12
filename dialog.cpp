#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::setMessageText(const QString &number)
{
    dialogMessage = "Dialing " + number + "...";
    ui->dialingConfirm->setText(dialogMessage);
}
