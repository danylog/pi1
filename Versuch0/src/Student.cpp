#include "Student.h"

std::ostream& operator<<(std::ostream& os, const Student& s)
{
    os << s.matrikelnummer << ", " << s.name << ", " << s.geburtsdatum << ", " << s.adresse;
    return os;
}