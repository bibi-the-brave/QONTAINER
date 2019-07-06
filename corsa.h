#ifndef CORSA_H
#define CORSA_H

#include "allenamento.h"
#include <memory>
#include "data.h"

class Corsa : virtual public Allenamento {
    // INV-istanza: kmSterrato >= 0 & kmStrada >=0 & (kmStrada + kmSterrato) > 0
    unsigned int kmSterrato;
    unsigned int kmStrada;
public:
    Corsa(std::shared_ptr<Persona>, unsigned int, Data, unsigned int, unsigned int, unsigned int);
    Corsa* clone() const override;
    std::string tipo() const override;
    unsigned int calorie() const override;
    unsigned int grassoPerso() const override;
    unsigned int saliMinerali() const override;
    bool operator==(const Allenamento&) const override;
    bool operator>=(const Allenamento&) const override;
    bool operator<=(const Allenamento&) const override;

    unsigned int getKmSterrato() const;
    unsigned int getKmStrada() const;
    void setKmSterrato(unsigned int);
    void setKmStrada(unsigned int);
};

#endif // CORSA_H
