#ifndef ADDSTREETDIALOG_H
#define ADDSTREETDIALOG_H

#include <QDialog>

namespace Ui
{
    class addstreetdialog;
}

class addstreetdialog : public QDialog
{
    Q_OBJECT

public:
    explicit addstreetdialog(QWidget *parent = nullptr);
    ~addstreetdialog();

    QString getCityAName() const;
    QString getCityBName() const;
    void setCityList(const QStringList &cityNames); // Neu!

private:
    Ui::addstreetdialog *ui;
};

#endif // ADDSTREETDIALOG_H
