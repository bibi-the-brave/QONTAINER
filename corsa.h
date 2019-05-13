#ifndef CORSA_H
#define CORSA_H

#include "allenamento.h"

class Corsa : virtual public Allenamento {
    // INV-istanza: kmSterrato >= 0 & kmStrada >=0 & (kmStrada + kmSterrato) > 0
    unsigned int kmSterrato;
    unsigned int kmStrada;
public:
    Corsa(std::string, std::string, unsigned int, double, unsigned int, unsigned int);
    Corsa* clone() const override;
    unsigned int calorie() const override;
    virtual unsigned int massaMuscolare() const override;
    virtual double grassoPerso() const override;
    double saliMinerali() const override;

    unsigned int getKmSterrato() const;
    unsigned int getKmStrada() const;

};

#endif // CORSA_H
