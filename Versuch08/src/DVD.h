#ifndef SRC_DVD_H_
#define SRC_DVD_H_

#include "Medium.h"
#include <string>

class DVD : public Medium
{
public:
    DVD(std::string initTitel, int initAltersfreigabe, std::string initGenre);
    virtual ~DVD();
    virtual void ausgabe() const override;
    virtual bool ausleihen(Person person, Datum ausleihdatum) override;

private:
    int altersfreigabe;
    std::string genre;
};

#endif /* SRC_DVD_H_ */
