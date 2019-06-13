#include "corsa.h"
#include "errori.h"
#include <typeinfo>

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

std::string Corsa::tipo() const {
    return "Corsa";
}

Corsa* Corsa::clone() const {
    return new Corsa(*this);
}

unsigned int Corsa::calorie() const {
    unsigned int kmTot = kmSterrato + kmStrada;
    return(800 * kmTot * kmTot) / getDurata() + kmSterrato / 2;
}

double Corsa::grassoPerso() const {
    return (calorie() / 7500) + ((90 * kmStrada) / 7500)
            + ((110 * kmSterrato)/7500);
}

double Corsa::saliMinerali() const {
    return 90.0 * kmStrada + 95.0 * kmSterrato;
}

bool Corsa::operator==(const Allenamento& al) const {
    try {
        const Corsa& t = dynamic_cast<const Corsa&>(al); //se ok non viene lanciata eccezione
        return Allenamento::operator==(al) &&
                kmStrada == (dynamic_cast<const Corsa&>(al)).kmStrada &&
                kmSterrato == (dynamic_cast<const Corsa&>(al)).kmSterrato;
    } catch (std::bad_cast e) {
        return false;
    }

}

unsigned int Corsa::getKmSterrato() const {
    return kmSterrato;
}

unsigned int Corsa::getKmStrada() const {
    return kmStrada;
}
