///////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXV
// Versuch 9
//////////////////////////////////////////////////////////////////////////////

/**
 * @file dijkstra.h
 * @brief Definiert die Klasse Dijkstra zur Berechnung des kürzesten Weges.
 */

#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#include "abstractmap.h"

/**
 * @brief Stellt den Dijkstra-Algorithmus zur Wegsuche bereit.
 */
class Dijkstra
{
public:
    /**
     * @brief Sucht den kürzesten Weg zwischen zwei Städten.
     * @param map Die Karte
     * @param start Name der Startstadt
     * @param target Name der Zielstadt
     * @return Liste der Straßen auf dem kürzesten Weg
     */
    static QVector<Street*> search(const AbstractMap &map, QString start, QString target);
private:
    Dijkstra();
};

#endif // DIJKSTRA_H
