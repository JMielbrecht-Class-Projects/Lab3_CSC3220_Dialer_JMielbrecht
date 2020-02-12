#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();
    void setMessageText(const QString& number);

private:
    Ui::Dialog *ui;
    QString dialogMessage;
};

#endif // DIALOG_H
