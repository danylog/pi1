/**
 * @file addcitydialog.h
 * @brief Dialog zum Hinzufügen einer neuen Stadt.
 */

#ifndef ADDCITYDIALOG_H
#define ADDCITYDIALOG_H

#include <QDialog>
#include "city.h"

namespace Ui
{
    class addcitydialog;
}

/**
 * @brief Dialogfenster zum Hinzufügen einer Stadt.
 */
class addcitydialog : public QDialog
{
    Q_OBJECT

public:
    explicit addcitydialog(QWidget *parent = nullptr);
    ~addcitydialog();

    /**
     * @brief Liest die Eingaben aus und erzeugt eine neue Stadt.
     * @param connections Liste der verbundenen Städte (wird befüllt)
     * @return Zeiger auf die neue Stadt
     */
    City *createCityFromInput(QStringList &connections) const;

private:
    Ui::addcitydialog *ui;
};

#endif
