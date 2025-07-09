#ifndef ADDCITYDIALOG_H
#define ADDCITYDIALOG_H

#include <QDialog>
#include "city.h"

namespace Ui
{
    class addcitydialog;
}

class addcitydialog : public QDialog
{
    Q_OBJECT

public:
    explicit addcitydialog(QWidget *parent = nullptr);
    ~addcitydialog();

    City *createCityFromInput(QStringList &connections) const;

private:
    Ui::addcitydialog *ui;
};

#endif
