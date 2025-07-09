#ifndef NEWCITYDIALOG_H
#define NEWCITYDIALOG_H

#include <QDialog>
#include "city.h"

QT_BEGIN_NAMESPACE
namespace Ui
{
    class NewCityDialog;
}
QT_END_NAMESPACE

class NewCityDialog : public QDialog
{
    Q_OBJECT

public:
    explicit NewCityDialog(QWidget *parent = nullptr);
    ~NewCityDialog();

    City *createCityFromInput() const;

private:
    Ui::NewCityDialog *ui;
};

#endif // NEWCITYDIALOG_H
