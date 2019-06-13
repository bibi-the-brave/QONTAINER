#ifndef NUOTO_H
#define NUOTO_H

#include <string>

#include "allenamento.h"
#include <memory>

class Nuoto : virtual public Allenamento {
    unsigned int vascheStileLibero, vascheRana, vascheDorso;
public:
    Nuoto(std::shared_ptr<Persona>, unsigned int, double,
          unsigned int, unsigned int, unsigned int);
    Nuoto* clone() const override;
    std::string tipo() const override;
    unsigned int calorie() const override;
    virtual double grassoPerso() const override;
    double saliMinerali() const override;
    bool operator==(const Allenamento&) const override;

    unsigned int getVascheStileLibero() const;
    unsigned int getVascheRana() const;
    unsigned int getVascheDorso() const;
};

#endif // NUOTO_H
