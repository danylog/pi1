#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QDebug>
#include <QString>
#include <QGraphicsScene>
#include <QRandomGenerator>
#include <QMessageBox>
#include "city.h"
#include "street.h"
#include "map.h"
#include "addcitydialog.h"
#include "addstreetdialog.h"
#include "mapionrw.h"
#include "dijkstra.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);
    mapIo = new MapIoNrw();
}

void MainWindow::testAbstractMap()
{
    Map testMap;
    City *a = new City("a", 0, 0);
    City *b = new City("b", 0, 100);
    City *c = new City("c", 100, 300);
    Street *s = new Street(a, b);
    Street *s2 = new Street(b, c);

    qDebug() << "MapTest: Start Test of the Map";
    {
        bool t1 = testMap.addStreet(s);
        if (t1)
            qDebug() << "-Error: Street should not bee added, if cities have not been added.";
    }
    {
        testMap.addCity(a);
        testMap.addCity(b);
        bool t1 = testMap.addStreet(s);
        if (!t1)
            qDebug() << "-Error: It should be possible to add this street.";
    }
    {
        City *city = testMap.findCity("a");
        if (city != a)
            qDebug() << "-Error: City a could not be found.";
        city = testMap.findCity("b");
        if (city != b)
            qDebug() << "-Error: City b could not be found.";
        city = testMap.findCity("c");
        if (city != nullptr)
            qDebug() << "-Error: If city could not be found 0 should be returned.";
    }
    testMap.addCity(c);
    testMap.addStreet(s2);
    {
        const City *city = testMap.getOppositeCity(s, a);
        if (city != b)
            qDebug() << "-Error: Opposite city should be b.";
        city = map.getOppositeCity(s, c);
        if (city != nullptr)
            qDebug() << "-Error: Opposite city for a city which is not linked by given street should be 0.";
    }
    {
        double l = testMap.getLength(s2);
        double expectedLength = 223.6;
        if (l < expectedLength * 0.95 || l > expectedLength * 1.05)
            qDebug() << "-Error: Street Length is not equal to the expected.";
    }
    {
        QVector<Street *> streetList1 = testMap.getStreetList(a);
        QVector<Street *> streetList2 = testMap.getStreetList(b);
        if (streetList1.size() != 1)
            qDebug() << "-Error: One street should be found for city a.";
        else if (*streetList1.begin() != s)
            qDebug() << "-Error: The wrong street has been found for city a.";
        if (streetList2.size() != 2)
            qDebug() << "-Error: Two streets should be found for city b.";
    }
    qDebug() << "MapTest: End Test of the Map.";
}

MainWindow::~MainWindow()
{
    delete mapIo;
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QString eingabe = ui->lineEdit_eingabe->text();
    qDebug() << QString("Button clicked! Eingabe: %1").arg(eingabe);

    bool ok;
    int zahl = eingabe.toInt(&ok);
    if (ok)
    {
        int erhoeht = zahl + 4;
        qDebug() << QString("Die Zahl %1 erhöht um 4 ist %2").arg(zahl).arg(erhoeht);
    }

    int x = QRandomGenerator::global()->bounded(550);
    int y = QRandomGenerator::global()->bounded(550);
    scene->addRect(x, y, 50, 50);
}

void MainWindow::on_lineEdit_eingabe_editingFinished()
{
}

void MainWindow::on_actionExit_triggered()
{
    close();
}

void MainWindow::on_actionClear_Scene_triggered()
{
    scene->clear();
}

void MainWindow::on_actionUeber_uns_triggered()
{
    QMessageBox::about(this, "Über StreetPlanner", "StreetPlanner\nEin einfaches Qt-Programm zur Szenenplanung.");
}

void MainWindow::on_pushButton_2_clicked()
{
    City city1("Teststadt 1", 100, 100);
    City city2("Teststadt 2", 200, 150);
    city1.draw(*scene);
    city2.draw(*scene);
    qDebug() << "Zwei Städte wurden gezeichnet.";
}

void MainWindow::on_pushButton_3_clicked()
{
    City *cityA = new City("Alpha", 100, 100);
    City *cityB = new City("Beta", 200, 150);
    cityA->draw(*scene);
    cityB->draw(*scene);
    Street *street = new Street(cityA, cityB);
    street->draw(*scene);
    qDebug() << "Test: Zwei Städte und eine Straße wurden gezeichnet.";
}

void MainWindow::on_pushButton_4_clicked()
{
    Map testMap;
    City *cityA = new City("Alpha", 100, 100);
    City *cityB = new City("Beta", 200, 150);
    City *cityC = new City("Gamma", 300, 200);
    testMap.addCity(cityA);
    testMap.addCity(cityB);
    Street *street1 = new Street(cityA, cityB);
    bool added1 = testMap.addStreet(street1);
    qDebug() << "Straße Alpha-Beta hinzugefügt:" << (added1 ? "ja" : "nein");
    Street *street2 = new Street(cityA, cityC);
    bool added2 = testMap.addStreet(street2);
    qDebug() << "Straße Alpha-Gamma hinzugefügt:" << (added2 ? "ja" : "nein");
    testMap.draw(*scene);
}

void MainWindow::on_checkBox_clicked(bool checked)
{
    ui->pushButton_2->setVisible(checked);
    ui->pushButton_3->setVisible(checked);
    ui->pushButton_4->setVisible(checked);
    ui->pushButton_testAbstractMap->setVisible(checked);
    ui->pushButton_testDijkstra->setVisible(checked);
}

void MainWindow::on_pushButton_newCity_clicked()
{
    while (true)
    {
        addcitydialog dlg(this);
        if (dlg.exec() != QDialog::Accepted)
            return;

        QStringList connections;
        City *city = dlg.createCityFromInput(connections);

        bool nameExists = (map.findCity(city->getName()) != nullptr);
        bool coordsExist = false;
        for (City *c : map.getCities())
        {
            if (c->getX() == city->getX() && c->getY() == city->getY())
            {
                coordsExist = true;
                break;
            }
        }

        if (nameExists)
        {
            QMessageBox::warning(this, "Fehler", "Eine Stadt mit diesem Namen existiert bereits!");
            delete city;
            continue;
        }
        if (coordsExist)
        {
            QMessageBox::warning(this, "Fehler", "An diesen Koordinaten existiert bereits eine Stadt!");
            delete city;
            continue;
        }

        map.addCity(city);

        // Verbindungen zu anderen Städten anlegen
        for (const QString &connName : connections)
        {
            City *target = map.findCity(connName);
            if (target)
            {
                map.addStreet(new Street(city, target));
            }
        }
        map.draw(*scene);
        updateCityComboBoxes();
        break;
    }
}

void MainWindow::on_fillMap_clicked()
{
    if (mapIo)
    {
        mapIo->fillMap(map);
        map.draw(*scene);
        updateCityComboBoxes();
    }
}

void MainWindow::on_pushButton_testAbstractMap_clicked()
{
    testAbstractMap();
}

void MainWindow::on_pushButton_testDijkstra_clicked()
{
    QVector<Street *> weg = Dijkstra::search(map, "Aachen", "Essen");
    qDebug() << "Gefundener Weg:";
    for (Street *s : weg)
    {
        qDebug() << s->getCityA()->getName() << "->" << s->getCityB()->getName();
        s->drawRed(*scene);
    }
}

void MainWindow::on_pushButton_6_clicked()
{
    QString start = ui->comboBoxStart->currentText();
    QString ziel = ui->comboBoxZiel->currentText();
    QVector<Street *> weg = Dijkstra::search(map, start, ziel);

    scene->clear();
    map.draw(*scene);
    for (Street *s : weg)
        s->drawRed(*scene);

    qDebug() << "Weg von" << start << "nach" << ziel << ":";
    for (Street *s : weg)
        qDebug() << s->getCityA()->getName() << "->" << s->getCityB()->getName();
}

void MainWindow::on_pushButton_newStreet_clicked()
{
    while (true)
    {
        addstreetdialog dlg(this);

        QStringList cityNames;
        for (City *city : map.getCities())
            cityNames << city->getName();
        dlg.setCityList(cityNames);

        if (dlg.exec() != QDialog::Accepted)
            return;

        QString nameA = dlg.getCityAName();
        QString nameB = dlg.getCityBName();
        City *cityA = map.findCity(nameA);
        City *cityB = map.findCity(nameB);

        // Prüfe, ob die Verbindung schon existiert
        bool streetExists = false;
        for (Street *s : map.getStreetList(cityA))
        {
            if ((s->getCityA() == cityA && s->getCityB() == cityB) ||
                (s->getCityA() == cityB && s->getCityB() == cityA))
            {
                streetExists = true;
                break;
            }
        }

        if (!cityA || !cityB)
        {
            QMessageBox::warning(this, "Fehler", "Eine oder beide Städte existieren nicht!");
            continue;
        }
        if (cityA == cityB)
        {
            QMessageBox::warning(this, "Fehler", "Eine Straße muss zwei verschiedene Städte verbinden!");
            continue;
        }
        if (streetExists)
        {
            QMessageBox::warning(this, "Fehler", "Diese Verbindung existiert bereits!");
            continue;
        }

        map.addStreet(new Street(cityA, cityB));
        map.draw(*scene);
        break;
    }
}

void MainWindow::updateCityComboBoxes()
{
    QStringList cityNames;
    for (City *city : map.getCities())
        cityNames << city->getName();

    ui->comboBoxStart->clear();
    ui->comboBoxStart->addItems(cityNames);
    ui->comboBoxZiel->clear();
    ui->comboBoxZiel->addItems(cityNames);
}
