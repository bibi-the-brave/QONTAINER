/*
 * Andrea Favero
 * 1125545
 * andrea.favero.8@studenti.unipd.it
 */
#ifndef TRIATHLON_H
#define TRIATHLON_H

#include "nuoto.h"
#include "ciclismo.h"
#include "corsa.h"
#include <memory>
#include "data.h"

class Triathlon : public Nuoto, public Ciclismo, public Corsa {
public:
    Triathlon(std::shared_ptr<Persona>, unsigned int, Data data, unsigned int,
              unsigned int, unsigned int, unsigned int, unsigned int,
              unsigned int, unsigned int, unsigned int, unsigned int);
    Triathlon* clone() const override;
    std::string tipo() const override;
    unsigned int calorie() const override;
    unsigned int grassoPerso() const override;
    unsigned int saliMinerali() const override;
    bool operator==(const Allenamento&) const override;
    bool operator>=(const Allenamento&) const override;
    bool operator<=(const Allenamento&) const override;
};

#endif // TRIATHLON_H
