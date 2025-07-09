/*!
 * @file Magazin.h
 * @brief Deklaration der Klasse Magazin
 */

#ifndef SRC_MAGAZIN_H_
#define SRC_MAGAZIN_H_

#include "Medium.h"
#include "Datum.h"
#include <string>

/*!
 * @brief Klasse Magazin, abgeleitet von Medium
 *
 * Speichert zusätzlich zum Titel das Erscheinungsdatum und die Sparte.
 */
class Magazin : public Medium
{
public:
    /*!
     * @brief Konstruktor
     * @param initTitel Titel des Magazins
     * @param initDatumAusgabe Erscheinungsdatum der Ausgabe
     * @param initSparte Sparte des Magazins
     */
    Magazin(std::string initTitel, Datum initDatumAusgabe, std::string initSparte);

    /*!
     * @brief Destruktor
     */
    virtual ~Magazin();

    /*!
     * @brief Gibt alle Informationen des Magazins aus
     */
    virtual void ausgabe() const override;

    /*!
     * @brief Prüft, ob das Magazin ausgeliehen werden darf
     * @param person Die ausleihende Person
     * @param ausleihdatum Das Ausleihdatum
     * @return true, wenn das Magazin nicht die neueste Ausgabe ist, sonst false
     */
    virtual bool ausleihen(Person person, Datum ausleihdatum) override;

private:
    Datum datumAusgabe; ///< Erscheinungsdatum der Ausgabe
    std::string sparte; ///< Sparte des Magazins
};

#endif /* SRC_MAGAZIN_H_ */
