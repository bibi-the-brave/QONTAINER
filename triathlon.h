#ifndef TRIATHLON_H
#define TRIATHLON_H

#include "nuoto.h"
#include "ciclismo.h"
#include "corsa.h"

class Triathlon : public Nuoto, Ciclismo, Corsa {
    unsigned int durataNuoto, durataCiclismo, durataCorsa;
public:
    Triathlon(std::string, std::string, double, unsigned int,
              unsigned int, unsigned int, unsigned int, unsigned int,
              unsigned int, unsigned int, unsigned int, unsigned int,
              unsigned int, unsigned int);
    Triathlon* clone() const override;
    unsigned int calorie() const override;
    virtual unsigned int massaMuscolare() const override;
    virtual double grassoPerso() const override;
    double saliMinerali() const override;

    unsigned int getDurataNuoto() const;
    unsigned int getDurataCiclismo() const;
    unsigned int getDurataCorsa() const;
};

#endif // TRIATHLON_H
