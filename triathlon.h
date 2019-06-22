#ifndef TRIATHLON_H
#define TRIATHLON_H

#include "nuoto.h"
#include "ciclismo.h"
#include "corsa.h"
#include <memory>
#include "data.h"

class Triathlon : public Nuoto, Ciclismo, Corsa {
public:
    Triathlon(std::shared_ptr<Persona>, unsigned int, Data data, double,
              unsigned int, unsigned int, unsigned int, unsigned int,
              unsigned int, unsigned int, unsigned int, unsigned int);
    Triathlon* clone() const override;
    virtual std::string tipo() const override;
    unsigned int calorie() const override;
    virtual double grassoPerso() const override;
    double saliMinerali() const override;
    bool operator==(const Allenamento&) const override;
};

#endif // TRIATHLON_H
