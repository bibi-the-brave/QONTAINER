#ifndef PALLAVOLO_H
#define PALLAVOLO_H

#include "allenamento.h"

class Pallavolo : public Allenamento {
    unsigned int schiacciate, battute, bagher;
public:
    Pallavolo(std::shared_ptr<Persona>, unsigned int, double,
              unsigned int, unsigned int, unsigned int);
    Pallavolo* clone() const override;
    unsigned int calorie() const override;
    virtual unsigned int massaMuscolare() const override;
    virtual double grassoPerso() const override;
    double saliMinerali() const override;

    unsigned int getSchiacciate() const;
    unsigned int getBattute() const;
    unsigned int getBagher() const;
};

#endif // PALLAVOLO_H
