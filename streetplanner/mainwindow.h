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

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
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
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    Map map;
    City *lastCity = nullptr;
    MapIo *mapIo = nullptr; // <--- MapIo-Zeiger als Attribut
};
#endif // MAINWINDOW_H
