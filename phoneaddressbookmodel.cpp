#include "phoneaddressbookmodel.h"
#include <iostream>
#include <QFile>
#include <QMessageBox>
#include <QTextStream>

PhoneAddressBookModel::PhoneAddressBookModel(QObject* parent)
{

}

int PhoneAddressBookModel::rowCount(const QModelIndex &parent) const
{
    return 2;
}

int PhoneAddressBookModel::columnCount(const QModelIndex &parent) const
{
    return 3;
}

QVariant PhoneAddressBookModel::data(const QModelIndex &index, int role) const
{
    if(role == Qt::DisplayRole){
        return QString("Row%1, Row%2")
                .arg(index.row())
                .arg(index.column());
    }
    return QVariant();
}

void PhoneAddressBookModel::openFile(QString filePath)
{
    QFile file(filePath);
    if(!file.open(QIODevice::ReadOnly)){
        QMessageBox::information(0, "error", file.errorString);
        return;
    }

    QTextStream in(&file);

    while(!in.atEnd()){
        QString line = in.readLine();
        QStringList fields = line.split(",");
    }
}
