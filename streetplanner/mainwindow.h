/**
 * @file mainwindow.h
 * @brief Definiert das Hauptfenster der Anwendung StreetPlanner.
 */

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include "map.h"
#include "mapionrw.h"

QT_BEGIN_NAMESPACE
namespace Ui
{
    class MainWindow;
}
QT_END_NAMESPACE

/**
 * @brief Die Klasse MainWindow stellt das Hauptfenster der Anwendung dar.
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    /**
     * @brief Konstruktor für das Hauptfenster.
     */
    MainWindow(QWidget *parent = nullptr);

    /**
     * @brief Destruktor.
     */
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_lineEdit_eingabe_editingFinished();

    void on_actionExit_triggered();

    void on_actionClear_Scene_triggered();

    void on_actionUeber_uns_triggered();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void testAbstractMap();

    void on_checkBox_clicked(bool checked);

    void on_pushButton_newCity_clicked();

    void on_fillMap_clicked();

    void on_pushButton_testAbstractMap_clicked();

    void on_pushButton_testDijkstra_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_newStreet_clicked();

    void updateCityComboBoxes();

private:
    Ui::MainWindow *ui;       ///< Benutzeroberfläche
    QGraphicsScene *scene;    ///< Szene für die grafische Darstellung
    Map map;                  ///< Die Karte mit Städten und Straßen
    City *lastCity = nullptr; ///< Letzte hinzugefügte Stadt
    MapIo *mapIo = nullptr;   ///< Datenquelle für Karten
};
#endif // MAINWINDOW_H
