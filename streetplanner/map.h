#ifndef MAP_H
#define MAP_H

#include <QVector>
#include <QDebug>
#include "city.h"
#include "street.h"
#include "abstractmap.h"

class Map : public AbstractMap
{
public:
    Map();

    void addCity(City *city) override;
    bool addStreet(Street *street) override;
    void draw(QGraphicsScene &scene);

    // Neue Methoden aus AbstractMap:
    City *findCity(const QString cityName) const override;
    QVector<Street *> getStreetList(const City *city) const override;
    City *getOppositeCity(const Street *street, const City *city) const override;
    double getLength(const Street *street) const override;
    QVector<City *> getCities() const { return cities; }

private:
    QVector<City *> cities;
    QVector<Street *> streets;
};

#endif // MAP_H
