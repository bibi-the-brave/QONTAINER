#ifndef CALCIO_H
#define CALCIO_H

#include "allenamento.h"

class Calcio : public Allenamento {
    unsigned int kmPercorsi;
    unsigned int passaggiFiltranti;
    unsigned int passaggiDiCollo;
    unsigned int rimesseLaterali;
    unsigned int rimesseDalFondo;
    unsigned int tiriPorta;
public:
    Calcio(std::shared_ptr<Persona>, unsigned int, double,
             unsigned int, unsigned int = 0, unsigned int = 0,
             unsigned int = 0, unsigned int = 0, unsigned int = 0);
    Calcio* clone() const override;
    unsigned int calorie() const override;
    virtual unsigned int massaMuscolare() const override;
    virtual double grassoPerso() const override;
    double saliMinerali() const override;
};

#endif // CALCIO_H
