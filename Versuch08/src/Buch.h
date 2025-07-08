/*
 * Buch.h
 *
 *  Created on: Jul 7, 2025
 *      Author: danylo
 */

#ifndef SRC_BUCH_H_
#define SRC_BUCH_H_

#include "Medium.h"
#include <string>

class Buch : public Medium {
public:
    Buch(std::string initTitel, std::string initAutor);
    virtual ~Buch();
    virtual void ausgabe() const override;

private:
    std::string autor;
};

#endif /* SRC_BUCH_H_ */
