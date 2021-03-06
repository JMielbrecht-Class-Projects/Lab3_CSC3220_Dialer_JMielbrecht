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

    QString nameNumber;

    //Check if phone numbers are starting with fstr

    for(unsigned int i = 0; i < phoneNumbers_1.size(); i++){

        //Convert name to a phone number for use in filtering
        nameNumber = convertName(firstNames[i]);

        //Filter address book entries
        if(phoneNumbers_1[i].startsWith(fstr) || nameNumber.startsWith(fstr)){
            filteredIndex.push_back(i);
        }
    }

    //Removing duplicate
    emit layoutChanged();
}

QString PhoneAddressBookModel::convertName(const QString &name)
{
    //Converting a name to a number
    QString retNum = "";
    for(int j = 0; j < name.length(); j++){
        if(name.at(j) == 'A'||name.at(j) == 'a' ||name.at(j) == 'B' ||name.at(j) == 'b' ||name.at(j) == 'C' ||name.at(j) == 'c'){
            retNum.append("2");
        }else if(name.at(j) == 'D'|| name.at(j) == 'd' || name.at(j) =='E' || name.at(j) =='e' || name.at(j) =='F' || name.at(j) =='f'){
            retNum.append("3");
        }else if(name.at(j) == 'G'||name.at(j) == 'g' ||name.at(j) == 'H' ||name.at(j) == 'h' ||name.at(j) == 'I' ||name.at(j) == 'i'){
            retNum.append("4");
        }else if(name.at(j) == 'J'||name.at(j) == 'j' ||name.at(j) == 'K' ||name.at(j) == 'k' || name.at(j) =='L' ||name.at(j) == 'l'){
            retNum.append("5");
        }else if(name.at(j) == 'M'||name.at(j) == 'm' ||name.at(j) == 'N' || name.at(j) =='n' ||name.at(j) == 'O' ||name.at(j) == 'o'){
            retNum.append("6");
        }else if(name.at(j) == 'P'||name.at(j) == 'p' ||name.at(j) == 'Q' ||name.at(j) == 'q' ||name.at(j) == 'R' ||name.at(j) == 'r' || name.at(j) =='S' ||name.at(j) == 's'){
            retNum.append("7");
        }else if(name.at(j) == 'T'|| name.at(j) =='t' ||name.at(j) == 'U' ||name.at(j) == 'u' || name.at(j) =='V' || name.at(j) =='v'){
            retNum.append("8");
        }else if(name.at(j) == 'W'|| name.at(j) =='w' || name.at(j) =='X' || name.at(j) =='x' || name.at(j) =='Y' || name.at(j) =='y' || name.at(j) =='Z' ||name.at(j) == 'z'){
            retNum.append("9");
        }
    }
    formatNumber(retNum);
    std::cout << retNum.toStdString() << std::endl;
    return retNum;
}

void PhoneAddressBookModel::formatNumber(QString& phoneNumber)
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
