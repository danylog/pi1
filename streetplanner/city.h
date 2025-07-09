/**
 * @file city.h
 * @brief Definiert die Klasse City zur Darstellung einer Stadt im StreetPlanner.
 */

#ifndef CITY_H
#define CITY_H

#include <QString>
#include <QGraphicsScene>

/**
 * @brief Die Klasse City repräsentiert eine Stadt mit Namen und Koordinaten.
 */
class City
{
public:
    /**
     * @brief Konstruktor für eine Stadt.
     * @param name Name der Stadt
     * @param x X-Koordinate
     * @param y Y-Koordinate
     */
    City(QString name, int x, int y);

    /**
     * @brief Zeichnet die Stadt als Punkt und Namen in die Szene.
     * @param scene Die QGraphicsScene, in die gezeichnet wird
     */
    void draw(QGraphicsScene &scene);

    /**
     * @brief Gibt den Namen der Stadt zurück.
     */
    QString getName() const { return name; }

    /**
     * @brief Gibt die X-Koordinate zurück.
     */
    int getX() const { return x; }

    /**
     * @brief Gibt die Y-Koordinate zurück.
     */
    int getY() const { return y; }

private:
    QString name; ///< Name der Stadt
    int x;        ///< X-Koordinate
    int y;        ///< Y-Koordinate
};

#endif // CITY_H
