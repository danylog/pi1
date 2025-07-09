/**
 * @file street.h
 * @brief Definiert die Klasse Street zur Darstellung einer Straße zwischen zwei Städten.
 */

#ifndef STREET_H
#define STREET_H

#include "city.h"
#include <QGraphicsScene>

/**
 * @brief Die Klasse Street repräsentiert eine Straße zwischen zwei Städten.
 */
class Street
{
public:
    /**
     * @brief Konstruktor für eine Straße.
     * @param cityA Zeiger auf die erste Stadt
     * @param cityB Zeiger auf die zweite Stadt
     */
    Street(City *cityA, City *cityB);

    /**
     * @brief Zeichnet die Straße als Linie in die Szene.
     * @param scene Die QGraphicsScene, in die gezeichnet wird
     */
    void draw(QGraphicsScene &scene);

    /**
     * @brief Gibt die erste Stadt zurück.
     */
    City *getCityA() const { return cityA; }

    /**
     * @brief Gibt die zweite Stadt zurück.
     */
    City *getCityB() const { return cityB; }

    /**
     * @brief Zeichnet die Straße als rote, breite Linie (z.B. für Dijkstra-Pfad).
     * @param scene Die QGraphicsScene, in die gezeichnet wird
     */
    void drawRed(QGraphicsScene &scene);

private:
    City *cityA; ///< Zeiger auf die erste Stadt
    City *cityB; ///< Zeiger auf die zweite Stadt
};

#endif // STREET_H
