#ifndef CITY_H
#define CITY_H

#include <QString>
#include <QGraphicsScene>

class City
{
public:
    City(QString name, int x, int y);
    void draw(QGraphicsScene &scene);
    QString getName() const { return name; }
    int getX() const { return x; }
    int getY() const { return y; }

private:
    QString name;
    int x;
    int y;
};

#endif // CITY_H
