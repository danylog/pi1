/**
 * @file mapionrw.h
 * @brief Definiert die Klasse MapIoNrw für eine fest kodierte Beispielkarte.
 */

#ifndef MAPIONRW_H
#define MAPIONRW_H

#include "mapio.h"

/**
 * @brief Diese Klasse stellt eine fest kodierte Beispielkarte bereit.
 */
class MapIoNrw : public MapIo
{
public:
    MapIoNrw();
    virtual ~MapIoNrw();

    /**
     * @brief Fügt der Karte Städte und Straßen hinzu.
     * @param map Referenz auf die zu füllende Karte
     */
    virtual void fillMap(AbstractMap &map);
};

#endif // MAPIONRW_H
