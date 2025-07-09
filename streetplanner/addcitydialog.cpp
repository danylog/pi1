#include "addcitydialog.h"
#include "ui_addcitydialog.h"
#include "city.h"
#include <QDebug>

addcitydialog::addcitydialog(QWidget *parent)
    : QDialog(parent), ui(new Ui::addcitydialog)
{
    ui->setupUi(this);
}

addcitydialog::~addcitydialog()
{
    delete ui;
}

City *addcitydialog::createCityFromInput(QStringList &connections) const
{
    QString name = ui->lineEditName->text();
    int x = ui->spinBoxX->value();
    int y = ui->spinBoxY->value();
    QString connStr = ui->lineEditConnections->text();
    connections = connStr.split(",", Qt::SkipEmptyParts);
    for (QString &c : connections)
        c = c.trimmed();
    qDebug() << "Eingegeben:" << name << x << y << "Verbindungen:" << connections;
    return new City(name, x, y);
}
