#ifndef CICLISMO_H
#define CICLISMO_H

#include "allenamento.h"
#include <memory>

class Ciclismo : virtual public Allenamento {
    unsigned int kmSalita, kmDiscesa, kmPianura;
public:
    Ciclismo(std::shared_ptr<Persona>, unsigned int, double,
             unsigned int, unsigned int, unsigned int);
    Ciclismo* clone() const override;
    unsigned int calorie() const override;
    virtual unsigned int massaMuscolare() const override;
    virtual double grassoPerso() const override;
    double saliMinerali() const override;

    unsigned int getKmSalita() const;
    unsigned int getKmDiscesa() const;
    unsigned int getKmPianura() const;
};

#endif // CICLISMO_H
