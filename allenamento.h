/*
 * Andrea Favero
 * 1125545
 * andrea.favero.8@studenti.unipd.it
 */
#ifndef ALLENAMENTO_H
#define ALLENAMENTO_H

#include "persona.h"
#include <memory>
#include "data.h"

class Allenamento {
    std::shared_ptr<Persona> atleta;
    unsigned int durata; // >0
    Data data;
    double mgMagnesioAssunti; // prima o durante l'allenamento
public:
    Allenamento(std::shared_ptr<Persona>, unsigned int, Data, double = 0.0);
    virtual ~Allenamento() = default;
    virtual std::string tipo() const = 0;
    virtual Allenamento* clone() const = 0;
    virtual unsigned int calorie() const = 0; // #calorie consumate
    virtual double grassoPerso() const = 0;// in grammi
    virtual double saliMinerali() const = 0; // mg di sali minerali consumati, >= 0
    virtual bool operator==(const Allenamento&) const;

    Persona getAtleta() const;
    double getMgMagnesioAssunti() const;
    unsigned int getDurata() const;
    Data getData() const;

};

#endif // ALLENAMENTO_H
