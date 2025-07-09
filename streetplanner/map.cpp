#include "map.h"

Map::Map()
{
}

void Map::addCity(City* city)
{
    cities.append(city);
    qDebug() << "Stadt hinzugefügt:" << city->getName();
}

bool Map::addStreet(Street* street)
{
    // Prüfen, ob beide Städte in der Map sind
    if (cities.contains(street->getCityA()) && cities.contains(street->getCityB())) {
        streets.append(street);
        qDebug() << "Straße hinzugefügt zwischen:" << street->getCityA()->getName() << "und" << street->getCityB()->getName();
        return true;
    } else {
        qDebug() << "Straße konnte nicht hinzugefügt werden (eine oder beide Städte fehlen).";
        return false;
    }
}

void Map::draw(QGraphicsScene& scene)
{
    for (Street* street : streets) {
        street->draw(scene);
    }
    for (City* city : cities) {
        city->draw(scene);
    }
}

City* Map::findCity(const QString cityName) const
{
    for (City* city : cities)
        if (city->getName() == cityName)
            return city;
    return nullptr;
}

QVector<Street*> Map::getStreetList(const City* city) const
{
    QVector<Street*> result;
    for (Street* street : streets)
        if (street->getCityA() == city || street->getCityB() == city)
            result.append(street);
    return result;
}

City* Map::getOppositeCity(const Street* street, const City* city) const
{
    if (street->getCityA() == city)
        return street->getCityB();
    if (street->getCityB() == city)
        return street->getCityA();
    return nullptr;
}

double Map::getLength(const Street* street) const
{
    int dx = street->getCityA()->getX() - street->getCityB()->getX();
    int dy = street->getCityA()->getY() - street->getCityB()->getY();
    return std::sqrt(dx*dx + dy*dy);
}
