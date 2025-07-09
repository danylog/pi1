#include "newcitydialog.h"
#include "./ui_newcitydialog.h"
#include <QDebug>

NewCityDialog::NewCityDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewCityDialog)
{
    ui->setupUi(this);
}

NewCityDialog::~NewCityDialog()
{
    delete ui;
}

City* NewCityDialog::createCityFromInput() const
{
    QString name = ui->lineEditName->text();
    int x = ui->lineEditX->text().toInt();
    int y = ui->lineEditY->text().toInt();
    qDebug() << "Eingegeben:" << name << x << y;
    return new City(name, x, y);
}
