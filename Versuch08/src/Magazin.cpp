#include "Magazin.h"
#include <iostream>

Magazin::Magazin(std::string initTitel, Datum initDatumAusgabe, std::string initSparte)
    : Medium(initTitel), datumAusgabe(initDatumAusgabe), sparte(initSparte)
{
}

Magazin::~Magazin() {}

void Magazin::ausgabe() const
{
    Medium::ausgabe();
    std::cout << "Erscheinungsdatum: ";
    datumAusgabe.ausgabe(std::cout); // <-- Korrektur hier
    std::cout << std::endl;
    std::cout << "Sparte: " << sparte << std::endl;
}

bool Magazin::ausleihen(Person person, Datum ausleihdatum)
{
    // Prüfe, ob das Magazin die neueste Ausgabe ist
    // Annahme: neueste Ausgabe = Ausleihmonat und Jahr gleich Erscheinungsmonat und Jahr
    if (ausleihdatum.getMonat() == datumAusgabe.getMonat() &&
        ausleihdatum.getJahr() == datumAusgabe.getJahr())
    {
        std::cout << "Das Magazin ist die neueste Ausgabe und darf nicht ausgeliehen werden." << std::endl;
        return false;
    }
    // Sonst Standardverhalten der Basisklasse
    return Medium::ausleihen(person, ausleihdatum);
}