/*!
 * @file DVD.h
 * @brief Deklaration der Klasse DVD
 */

#ifndef SRC_DVD_H_
#define SRC_DVD_H_

#include "Medium.h"
#include <string>

/*!
 * @brief Klasse DVD, abgeleitet von Medium
 *
 * Speichert zusätzlich zum Titel die Altersfreigabe und das Genre.
 */
class DVD : public Medium
{
public:
    /*!
     * @brief Konstruktor
     * @param initTitel Titel der DVD
     * @param initAltersfreigabe Altersfreigabe der DVD
     * @param initGenre Genre der DVD
     */
    DVD(std::string initTitel, int initAltersfreigabe, std::string initGenre);

    /*!
     * @brief Destruktor
     */
    virtual ~DVD();

    /*!
     * @brief Gibt alle Informationen der DVD aus
     */
    virtual void ausgabe() const override;

    /*!
     * @brief Prüft, ob die DVD ausgeliehen werden darf
     * @param person Die ausleihende Person
     * @param ausleihdatum Das Ausleihdatum
     * @return true, wenn die Altersfreigabe erfüllt ist, sonst false
     */
    virtual bool ausleihen(Person person, Datum ausleihdatum) override;

private:
    int altersfreigabe; ///< Altersfreigabe der DVD
    std::string genre;  ///< Genre der DVD
};

#endif /* SRC_DVD_H_ */
