#include "addstreetdialog.h"
#include "ui_addstreetdialog.h"

addstreetdialog::addstreetdialog(QWidget *parent)
    : QDialog(parent), ui(new Ui::addstreetdialog)
{
    ui->setupUi(this);
}

addstreetdialog::~addstreetdialog()
{
    delete ui;
}

QString addstreetdialog::getCityAName() const
{
    return ui->comboBoxCityA->currentText();
}

QString addstreetdialog::getCityBName() const
{
    return ui->comboBoxCityB->currentText();
}

void addstreetdialog::setCityList(const QStringList &cityNames)
{
    ui->comboBoxCityA->clear();
    ui->comboBoxCityA->addItems(cityNames);
    ui->comboBoxCityB->clear();
    ui->comboBoxCityB->addItems(cityNames);
}
