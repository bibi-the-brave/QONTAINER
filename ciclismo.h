#ifndef CICLISMO_H
#define CICLISMO_H

#include "allenamento.h"
#include <memory>
#include "data.h"

class Ciclismo : virtual public Allenamento {
    unsigned int kmSalita, kmPianura, kmDiscesa;
public:
    Ciclismo(std::shared_ptr<Persona>, unsigned int, Data, unsigned int,
             unsigned int, unsigned int, unsigned int);
    Ciclismo* clone() const override;
    std::string tipo() const override;
    unsigned int calorie() const override;
    unsigned int grassoPerso() const override;
    unsigned int saliMinerali() const override;
    bool operator==(const Allenamento&) const override;
    bool operator>=(const Allenamento&) const override;
    bool operator<=(const Allenamento&) const override;

    unsigned int getKmSalita() const;
    unsigned int getKmDiscesa() const;
    unsigned int getKmPianura() const;
    void setKmSalita(unsigned int);
    void setKmDiscesa(unsigned int);
    void setKmPianura(unsigned int);
};

#endif // CICLISMO_H
