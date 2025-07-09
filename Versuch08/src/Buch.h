/*!
 * @file Buch.h
 * @brief Deklaration der Klasse Buch
 */

#ifndef SRC_BUCH_H_
#define SRC_BUCH_H_

#include "Medium.h"
#include <string>

/*!
 * @brief Klasse Buch, abgeleitet von Medium
 *
 * Speichert zusätzlich zum Titel den Autor des Buches.
 */
class Buch : public Medium
{
public:
    /*!
     * @brief Konstruktor
     * @param initTitel Titel des Buches
     * @param initAutor Autor des Buches
     */
    Buch(std::string initTitel, std::string initAutor);

    /*!
     * @brief Destruktor
     */
    virtual ~Buch();

    /*!
     * @brief Gibt alle Informationen des Buches aus
     */
    virtual void ausgabe() const override;

private:
    std::string autor; ///< Autor des Buches
};

#endif /* SRC_BUCH_H_ */
