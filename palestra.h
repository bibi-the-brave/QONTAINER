#ifndef PALESTRA_H
#define PALESTRA_H

#include "allenamento.h"

class Palestra : public Allenamento {
    unsigned int addominali, flessioni, numeroPesi, kgPesi;
public:
    Palestra(std::string, std::string, unsigned int, double,
             unsigned int, unsigned int, unsigned int, unsigned int);
    Palestra* clone() const override;
    unsigned int calorie() const override;
    virtual unsigned int massaMuscolare() const override;
    virtual double grassoPerso() const override;
    double saliMinerali() const override;

    unsigned int getAddominali() const;
    unsigned int getFlessioni() const;
    unsigned int getNumeroPesi() const;
    unsigned int getKgPesi() const;
};

#endif // PALESTRA_H
