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
    return filteredIndex.size();
}

int PhoneAddressBookModel::columnCount(const QModelIndex &parent) const
{
    return 3;
}

QVariant PhoneAddressBookModel::data(const QModelIndex &index, int role) const
{
    if(role == Qt::DisplayRole){
        switch(index.column()){
        case 0:
            return firstNames.at(filteredIndex[index.row()]);
        case 1:
            return lastNames.at(filteredIndex[index.row()]);
        case 2:
            return phoneNumbers_1.at(filteredIndex[index.row()]);
        }

//        return QString("Row%1, Row%2")
//                .arg(index.row())
//                .arg(index.column());
    }
    return QVariant();
}

void PhoneAddressBookModel::openFile(QString filePath)
{
    QFile file(filePath);
    if(!file.open(QIODevice::ReadOnly)){
        QMessageBox::information(0, "error", file.errorString());
        return;
    }

    QTextStream in(&file);

    firstNames.clear();
    lastNames.clear();
    phoneNumbers_1.clear();

    for(int i = 0; !in.atEnd(); i++){
        QString line = in.readLine();
        QStringList fields = line.split(",");

        if(i == 0) continue;

        for(int j = 0; j < fields.length(); j++){
            std::cout << "[" << j << "]" << fields[j].toStdString();
        }
        std::cout  << std::endl;

        firstNames.push_back(fields[0]);
        lastNames.push_back(fields[1]);
        phoneNumbers_1.push_back(fields[7]);

        filteredIndex.push_back(i);
    }
    file.close();

    emit layoutChanged();

}

QString PhoneAddressBookModel::getPhoneNumber(int index)
{
    return phoneNumbers_1.at(filteredIndex[index]);
}

void PhoneAddressBookModel::setFilterString(QString fstr)
{
    filteredIndex.clear();

    //Check if phone numbers are starting with fstr
    for(unsigned int i = 0; i < phoneNumbers_1.size(); i++){
        if(phoneNumbers_1[i].startsWith(fstr)){
            filteredIndex.push_back(i);
           // std::cout << phoneNumbers_1[i].toStdString() << std::endl;
        }
    }

    emit layoutChanged();
}
