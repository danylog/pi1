/**
 * @file addstreetdialog.h
 * @brief Dialog zum Hinzufügen einer Straße zwischen zwei Städten.
 */

#ifndef ADDSTREETDIALOG_H
#define ADDSTREETDIALOG_H

#include <QDialog>

namespace Ui
{
    class addstreetdialog;
}

/**
 * @brief Dialogfenster zum Hinzufügen einer Straße.
 */
class addstreetdialog : public QDialog
{
    Q_OBJECT

public:
    explicit addstreetdialog(QWidget *parent = nullptr);
    ~addstreetdialog();

    /**
     * @brief Gibt den Namen der ersten Stadt zurück.
     */
    QString getCityAName() const;

    /**
     * @brief Gibt den Namen der zweiten Stadt zurück.
     */
    QString getCityBName() const;

    /**
     * @brief Setzt die Liste der Städtenamen für die Auswahl.
     */
    void setCityList(const QStringList &cityNames);

private:
    Ui::addstreetdialog *ui;
};

#endif // ADDSTREETDIALOG_H
