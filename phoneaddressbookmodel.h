#ifndef PHONEADDRESSBOOKMODEL_H
#define PHONEADDRESSBOOKMODEL_H

#include <QAbstractTableModel>

class PhoneAddressBookModel: public QAbstractTableModel
{
public:
    PhoneAddressBookModel(QObject* parent);

    // QAbstractItemModel interface
public:
    int rowCount(const QModelIndex &parent) const;
    int columnCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;
    void openFile(QString filePath);
};

#endif // PHONEADDRESSBOOKMODEL_H
