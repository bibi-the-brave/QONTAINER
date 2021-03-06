/*
 * Andrea Favero
 * 1125545
 * andrea.favero.8@studenti.unipd.it
 */
#include "corsa.h"
#include "errori.h"
#include <typeinfo>
#include "data.h"

Corsa::Corsa(std::shared_ptr<Persona> atleta, unsigned int durata, Data data,
             unsigned int mgMagnesio, unsigned int sterrato, unsigned int strada)
try: Allenamento (atleta, durata, data, mgMagnesio), kmSterrato(sterrato),
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
    return(900 * kmTot) / getDurata() + kmSterrato / 2;
}

unsigned int Corsa::grassoPerso() const {
    return (calorie() / 1000) + ((90 * kmStrada) / 1000)
            + ((110 * kmSterrato)/1000);
}

unsigned int Corsa::saliMinerali() const {
    return 90 * kmStrada + 95 * kmSterrato;
}

bool Corsa::operator==(const Allenamento& al) const {
    try {
        if(typeid(al) == typeid(const Corsa&))
            return Allenamento::operator==(al) &&
                kmStrada == (dynamic_cast<const Corsa&>(al)).kmStrada &&
                kmSterrato == (dynamic_cast<const Corsa&>(al)).kmSterrato;
        return false;
    } catch (std::bad_cast e) {
        return false;
    }

}

bool Corsa::operator>=(const Allenamento& al) const {
    try {
        if(typeid(al) == typeid(const Corsa&))
            return Allenamento::operator>=(al) &&
                kmStrada >= (dynamic_cast<const Corsa&>(al)).kmStrada &&
                kmSterrato >= (dynamic_cast<const Corsa&>(al)).kmSterrato;
        return false;
    } catch (std::bad_cast e) {
        return false;
    }
}

bool Corsa::operator<=(const Allenamento& al) const {
    try {
        if(typeid(al) == typeid(const Corsa&))
            return Allenamento::operator<=(al) &&
                kmStrada <= (dynamic_cast<const Corsa&>(al)).kmStrada &&
                kmSterrato <= (dynamic_cast<const Corsa&>(al)).kmSterrato;
        return false;
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

void Corsa::setKmSterrato(unsigned int km) {
    kmSterrato = km;
}

void Corsa::setKmStrada(unsigned int km) {
    kmStrada = km;
}
