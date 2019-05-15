/*
 * Andrea Favero
 * 1125545
 * andrea.favero.8@studenti.unipd.it
 */
#ifndef ALLENAMENTO_H
#define ALLENAMENTO_H

#include "persona.h"

class Allenamento {
    Persona atleta; /*Vedere se metterlo come puntatore un atleta*/
    unsigned int durata; //>0
    double mgMagnesioAssunti; //prima o durante l'allenamento
public:
    Allenamento(std::string, std::string, unsigned int, double = 0.0);
    virtual ~Allenamento() = default;
    virtual Allenamento* clone() const = 0;
    virtual unsigned int calorie() const = 0; //#calorie consumate
//************************************************************************************
//massaMuscolare da implementare in tutte le sottoclassi, per ora ritorna 1 alla cazzo
//************************************************************************************
    virtual unsigned int massaMuscolare() const = 0; //aumento massa muscolare
    virtual double grassoPerso() const = 0;//in kg
    virtual double saliMinerali() const = 0; //mg di sali minerali consumati, >= 0
    //virtual double stanchezza() const; // double 0 <= x <= 1
    // stanchezza tiene conto dei sali minerali consumati e del magnesio assunto
    //felicità \in {1,...,10}

    Persona getAtleta() const;
    double getMgMagnesioAssunti() const;
    unsigned int getDurata() const;
};

#endif // ALLENAMENTO_H
