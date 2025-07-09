/*!
 * Praktikum Informatik 1
 *
 *
 * @file Person.h
 * @brief Deklaration der Klasse Person
 */

#ifndef Person_H_
#define Person_H_

#include "Datum.h"
#include <string>

/*!
 * @brief Klasse Person
 *
 * Speichert Name und Geburtsdatum einer Person.
 */
class Person
{
public:
    /*!
     * @brief Konstruktor
     * @param initName Name der Person (optional)
     * @param initGeburtsdatum Geburtsdatum der Person (optional)
     */
    Person(std::string initName = "", Datum initGeburtsdatum = Datum());

    /*!
     * @brief Destruktor
     */
    ~Person();

    /*!
     * @brief Gibt den Namen der Person zurück
     * @return Name der Person
     */
    std::string getName() const;

    /*!
     * @brief Gibt das Geburtsdatum der Person zurück
     * @return Geburtsdatum der Person
     */
    Datum getGeburtsdatum() const;

private:
    std::string name;   ///< Name der Person
    Datum geburtsdatum; ///< Geburtsdatum der Person
};

#endif
