#ifndef CICLISMO_H
#define CICLISMO_H

#include "allenamento.h"
#include <memory>
#include "data.h"

class Ciclismo : virtual public Allenamento {
    unsigned int kmSalita, kmPianura, kmDiscesa;
public:
    Ciclismo(std::shared_ptr<Persona>, unsigned int, Data, double,
             unsigned int, unsigned int, unsigned int);
    Ciclismo* clone() const override;
    std::string tipo() const override;
    unsigned int calorie() const override;
    virtual double grassoPerso() const override;
    double saliMinerali() const override;
    bool operator==(const Allenamento&) const override;

    unsigned int getKmSalita() const;
    unsigned int getKmDiscesa() const;
    unsigned int getKmPianura() const;
};

#endif // CICLISMO_H
