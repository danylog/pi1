#ifndef SRC_MAGAZIN_H_
#define SRC_MAGAZIN_H_

#include "Medium.h"
#include "Datum.h"
#include <string>

class Magazin : public Medium
{
public:
    Magazin(std::string initTitel, Datum initDatumAusgabe, std::string initSparte);
    virtual ~Magazin();
    virtual void ausgabe() const override;
    virtual bool ausleihen(Person person, Datum ausleihdatum) override;

private:
    Datum datumAusgabe;
    std::string sparte;
};

#endif /* SRC_MAGAZIN_H_ */
