#include "city.h"
#include <QDebug>
#include <QBrush>
#include <QPen>
#include <QGraphicsTextItem>

City::City(QString name, int x, int y)
    : name(name), x(x), y(y)
{
}

void City::draw(QGraphicsScene &scene)
{
    scene.addEllipse(x - 5, y - 5, 10, 10, QPen(Qt::red), QBrush(Qt::red));
    QGraphicsTextItem *textItem = scene.addText(name);
    textItem->setPos(x - textItem->boundingRect().width() / 2, y - 23);
    qDebug() << QString("City '%1' drawn at (%2, %3)").arg(name).arg(x).arg(y);
}
