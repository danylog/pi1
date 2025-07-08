#include "DVD.h"
#include <iostream>

DVD::DVD(std::string initTitel, int initAltersfreigabe, std::string initGenre)
    : Medium(initTitel), altersfreigabe(initAltersfreigabe), genre(initGenre)
{
}

DVD::~DVD() {}

void DVD::ausgabe() const
{
    Medium::ausgabe();
    std::cout << "Altersfreigabe: " << altersfreigabe << std::endl;
    std::cout << "Genre: " << genre << std::endl;
}

bool DVD::ausleihen(Person person, Datum ausleihdatum)
{
    Datum geburt = person.getGeburtsdatum();
    int alter = ausleihdatum.getJahr() - geburt.getJahr();
    if (ausleihdatum.getMonat() < geburt.getMonat() ||
        (ausleihdatum.getMonat() == geburt.getMonat() && ausleihdatum.getTag() < geburt.getTag()))
    {
        alter--;
    }

    if (alter < altersfreigabe)
    {
        std::cout << "Diese DVD darf nur von Personen mit Mindestalter " << altersfreigabe << " ausgeliehen werden." << std::endl;
        return false;
    }
    return Medium::ausleihen(person, ausleihdatum);
}