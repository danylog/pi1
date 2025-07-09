#include "street.h"
#include <QPen>
#include <QDebug>

Street::Street(City *cityA, City *cityB)
    : cityA(cityA), cityB(cityB)
{
}

void Street::draw(QGraphicsScene &scene)
{
    if (cityA && cityB)
    {
        scene.addLine(cityA->getX(), cityA->getY(), cityB->getX(), cityB->getY(), QPen(Qt::black, 2));
        qDebug() << "Street drawn between" << cityA->getName() << "and" << cityB->getName();
    }
}

void Street::drawRed(QGraphicsScene &scene)
{
    scene.addLine(
        cityA->getX(), cityA->getY(),
        cityB->getX(), cityB->getY(),
        QPen(Qt::red, 4));
}
