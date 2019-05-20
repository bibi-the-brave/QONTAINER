#include "corsa.h"
#include "errori.h"

Corsa::Corsa(std::shared_ptr<Persona> atleta, unsigned int durata,
             double mgMagnesio, unsigned int sterrato, unsigned int strada)
try: Allenamento (atleta, durata, mgMagnesio), kmSterrato(sterrato),
    kmStrada(strada)
{
    //if(kmStrada + kmSterrato == 0)
    //    throw ErrCorsa();
} catch(ErrAllenamento) {
    throw;
}


Corsa* Corsa::clone() const {
    return new Corsa(*this);
}

unsigned int Corsa::calorie() const {
    unsigned int kmTot = kmSterrato + kmStrada;
    return(800 * kmTot * kmTot) / getDurata() + kmSterrato / 2;
}

unsigned int Corsa::massaMuscolare() const  {
    return 1;
}

double Corsa::grassoPerso() const {
    return (calorie() / 7500) + ((90 * kmStrada) / 7500)
            + ((110 * kmSterrato)/7500);
}

double Corsa::saliMinerali() const {
    return 90.0 * kmStrada + 95.0 * kmSterrato;
}

unsigned int Corsa::getKmSterrato() const {
    return kmSterrato;
}

unsigned int Corsa::getKmStrada() const {
    return kmStrada;
}
