#ifndef PHONEADDRESSBOOKMODEL_H
#define PHONEADDRESSBOOKMODEL_H

#include <QAbstractTableModel>
#include <vector>

class PhoneAddressBookModel: public QAbstractTableModel
{
public:
    PhoneAddressBookModel(QObject* parent);
    std::vector<QString> firstNames;
    std::vector<QString> lastNames;
    std::vector<QString> phoneNumbers_1;

    // QAbstractItemModel interface
public:
    int rowCount(const QModelIndex &parent) const;
    int columnCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;
    void openFile(QString filePath);
    QString getPhoneNumber(int index);
};

#endif // PHONEADDRESSBOOKMODEL_H
