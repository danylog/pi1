#pragma once
#include <string>
#include <ostream>

/**
 * @class Student
 * @brief Repräsentiert einen Studenten mit Matrikelnummer, Name, Geburtsdatum und Adresse.
 */
class Student
{
public:
    /**
     * @brief Die Matrikelnummer des Studenten.
     */
    std::string matrikelnummer;

    /**
     * @brief Der Name des Studenten.
     */
    std::string name;

    /**
     * @brief Das Geburtsdatum des Studenten.
     */
    std::string geburtsdatum;

    /**
     * @brief Die Adresse des Studenten.
     */
    std::string adresse;

    /**
     * @brief Vergleicht zwei Studenten anhand ihrer Matrikelnummer.
     * @param other Der andere Student.
     * @return true, wenn die Matrikelnummer kleiner ist.
     */
    bool operator<(const Student& other) const
    {
        return matrikelnummer < other.matrikelnummer;
    }

    /**
     * @brief Vergleicht zwei Studenten anhand ihrer Matrikelnummer.
     * @param other Der andere Student.
     * @return true, wenn die Matrikelnummer größer ist.
     */
    bool operator>(const Student& other) const
    {
        return matrikelnummer > other.matrikelnummer;
    }

    /**
     * @brief Prüft, ob zwei Studenten die gleiche Matrikelnummer haben.
     * @param other Der andere Student.
     * @return true, wenn die Matrikelnummern gleich sind.
     */
    bool operator==(const Student& other) const
    {
        return matrikelnummer == other.matrikelnummer;
    }

    /**
     * @brief Ausgabeoperator für einen Studenten.
     * @param os Der Ausgabestream.
     * @param s Der Student, der ausgegeben werden soll.
     * @return Referenz auf den Ausgabestream.
     */
    friend std::ostream& operator<<(std::ostream& os, const Student& s);
};