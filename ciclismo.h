#ifndef CICLISMO_H
#define CICLISMO_H

#include "allenamento.h"

class Ciclismo : virtual public Allenamento {
    unsigned int kmSalita, kmDiscesa, kmPianura;
public:
    Ciclismo(std::string, std::string, unsigned int, double,
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
