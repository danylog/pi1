#include "mapionrw.h"
#include "city.h"
#include "street.h"

MapIoNrw::MapIoNrw() {}
MapIoNrw::~MapIoNrw() {}

void MapIoNrw::fillMap(AbstractMap &map)
{
    City *c1 = new City("Köln", 250, 300);
    City *c2 = new City("Düsseldorf", 220, 200);
    City *c3 = new City("Essen", 320, 180);
    City *c4 = new City("Aachen", 50, 320);
    City *c5 = new City("Bonn", 260, 400);
    City *c6 = new City("Dortmund", 400, 150);
    City *c7 = new City("Wuppertal", 280, 220);
    City *c8 = new City("Mönchengladbach", 120, 240);
    City *c9 = new City("Siegen", 360, 470);
    City *c10 = new City("Bielefeld", 500, 100);
    City *c11 = new City("Paderborn", 520, 160);
    City *c12 = new City("Gelsenkirchen", 350, 170);
    City *c13 = new City("Oberhausen", 300, 160);
    City *c14 = new City("Leverkusen", 240, 280);
    City *c15 = new City("Krefeld", 180, 180);

    map.addCity(c1);
    map.addCity(c2);
    map.addCity(c3);
    map.addCity(c4);
    map.addCity(c5);
    map.addCity(c6);
    map.addCity(c7);
    map.addCity(c8);
    map.addCity(c9);
    map.addCity(c10);
    map.addCity(c11);
    map.addCity(c12);
    map.addCity(c13);
    map.addCity(c14);
    map.addCity(c15);

    // Streets
    map.addStreet(new Street(c1, c2));
    map.addStreet(new Street(c1, c5));
    map.addStreet(new Street(c1, c4));
    map.addStreet(new Street(c1, c7));
    map.addStreet(new Street(c1, c14));
    map.addStreet(new Street(c2, c3));
    map.addStreet(new Street(c2, c7));
    map.addStreet(new Street(c2, c8));
    map.addStreet(new Street(c2, c15));
    map.addStreet(new Street(c3, c6));
    map.addStreet(new Street(c3, c12));
    map.addStreet(new Street(c3, c13));
    map.addStreet(new Street(c6, c10));
    map.addStreet(new Street(c10, c11));
    map.addStreet(new Street(c5, c9));
    map.addStreet(new Street(c9, c11));
    map.addStreet(new Street(c6, c9));
    map.addStreet(new Street(c13, c7));
    map.addStreet(new Street(c12, c6));
    map.addStreet(new Street(c14, c5));
    map.addStreet(new Street(c8, c4));
}