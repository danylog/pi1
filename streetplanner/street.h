#ifndef STREET_H
#define STREET_H

#include "city.h"
#include <QGraphicsScene>

class Street
{
public:
    Street(City *cityA, City *cityB);

    void draw(QGraphicsScene &scene);

    City *getCityA() const { return cityA; }
    City *getCityB() const { return cityB; }
    void drawRed(QGraphicsScene &scene);

private:
    City *cityA;
    City *cityB;
};

#endif // STREET_H
