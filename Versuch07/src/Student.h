#pragma once
#include <string>
#include <ostream>

class Student
{
public:
    std::string matrikelnummer;
    std::string name;
    std::string geburtsdatum;
    std::string adresse;

    // Operatorüberladungen
    bool operator<(const Student& other) const
    {
        return matrikelnummer < other.matrikelnummer;
    }

    bool operator>(const Student& other) const
    {
        return matrikelnummer > other.matrikelnummer;
    }

    bool operator==(const Student& other) const
    {
        return matrikelnummer == other.matrikelnummer;
    }

    // Ausgabeoperator
    friend std::ostream& operator<<(std::ostream& os, const Student& s);
};