/**
 * @file map.h
 * @brief Definiert die Klasse Map zur Verwaltung von Städten und Straßen.
 */

#ifndef MAP_H
#define MAP_H

#include <QVector>
#include <QDebug>
#include "city.h"
#include "street.h"
#include "abstractmap.h"

/**
 * @brief Die Klasse Map verwaltet eine Sammlung von Städten und Straßen.
 */
class Map : public AbstractMap
{
public:
    /**
     * @brief Konstruktor für die Map.
     */
    Map();

    void addCity(City *city) override;
    bool addStreet(Street *street) override;
    void draw(QGraphicsScene &scene);

    City *findCity(const QString cityName) const override;
    QVector<Street *> getStreetList(const City *city) const override;
    City *getOppositeCity(const Street *street, const City *city) const override;
    double getLength(const Street *street) const override;

    /**
     * @brief Gibt eine Liste aller Städte zurück.
     */
    QVector<City *> getCities() const { return cities; }

private:
    QVector<City *> cities;   ///< Liste der Städte
    QVector<Street *> streets;///< Liste der Straßen
};

#endif // MAP_H
