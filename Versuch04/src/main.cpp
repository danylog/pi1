

#include <iostream>
#include <iomanip>
#include "Vektor.h"
#include <cmath>

int main()
{
    const double erdRadius = 6371000.0;                      // Meter
    const double plattformHoehe = 555.7;                     // Meter
    const double koerperHoehe = 1.7;                         // Meter
    const double sichtHoehe = plattformHoehe + koerperHoehe; // Meter

    Vektor erdMittelpunkt(0, 0, 0);
    Vektor aussichtsPunkt(0, 0, erdRadius + sichtHoehe);

    double schrittweite = 0.1; // Meter
    double x = 0.0;
    double z = erdRadius;
    int schritte = 0;

    Vektor sicht(0, 0, 0);
    Vektor punktAufErde(0, 0, 0);

    while (x < erdRadius)
    {
        z = sqrt(erdRadius * erdRadius - x * x);
        punktAufErde = Vektor(x, 0, z);
        sicht = punktAufErde.sub(aussichtsPunkt);

        double skalar = punktAufErde.skalarProd(sicht);

        schritte++;

        // Abbruchbedingung: Skalarprodukt >= 0 (Tangente erreicht)
        if (skalar >= 0.0)
            break;

        x += schrittweite;
    }

    double distanz = sicht.laenge() / 1000.0;

    double beta = punktAufErde.winkel(aussichtsPunkt) * 180.0 / M_PI;

    std::cout << std::fixed << "Sie können " << std::setprecision(4) << distanz << " Km weit sehen." << std::endl;
    std::cout << std::fixed << "Sie sind " << std::setprecision(4) << sichtHoehe << " Meter hoch." << std::endl;
    std::cout << "Der Winkel beträgt " << std::setprecision(4) << beta << " Grad." << std::endl;
    std::cout << "Anzahl Schritte: " << schritte << std::endl;

    return 0;
}
