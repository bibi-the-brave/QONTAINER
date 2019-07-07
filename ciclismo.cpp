#include "ciclismo.h"
#include "errori.h"
#include <typeinfo>

Ciclismo::Ciclismo(std::shared_ptr<Persona> atleta, unsigned int durata,
                   Data data, unsigned int mgMagnesio, unsigned int salita,
                   unsigned int pianura, unsigned int discesa)
try: Allenamento(atleta, durata, data, mgMagnesio), kmSalita(salita),
     kmPianura(pianura), kmDiscesa(discesa)
{
    if(kmSalita + kmPianura + kmDiscesa == 0)
        throw ErrCiclismo();
} catch (ErrAllenamento) {
    throw;
}

std::string Ciclismo::tipo() const {
    return "Ciclismo";
}

Ciclismo* Ciclismo::clone() const {
    return new Ciclismo(*this);
}

unsigned int Ciclismo::calorie() const {
    unsigned int kmTot = kmSalita + kmDiscesa + kmPianura;
    return (400 * kmTot) + 2000;
}

unsigned int Ciclismo::grassoPerso() const {
    return (calorie() / 200) + (110 * kmSalita)/2500
            + (45 * kmDiscesa)/3500 + (90 * kmPianura)/2500;
}

unsigned int Ciclismo::saliMinerali() const {
    return 110 * kmSalita + 90 * kmPianura;
}

bool Ciclismo::operator==(const Allenamento& al) const {
    try {
        if(typeid(al) == typeid(const Ciclismo&))
            return Allenamento::operator==(al) &&
                kmSalita == (dynamic_cast<const Ciclismo&>(al)).kmSalita &&
                kmDiscesa == (dynamic_cast<const Ciclismo&>(al)).kmDiscesa &&
                kmPianura == (dynamic_cast<const Ciclismo&>(al)).kmPianura;
        return false;
    } catch (std::bad_cast e) {
        return false;
    }

}

bool Ciclismo::operator>=(const Allenamento& al) const {
    try {
        if(typeid(al) == typeid(const Ciclismo&))
            return Allenamento::operator>=(al) &&
                kmSalita >= (dynamic_cast<const Ciclismo&>(al)).kmSalita &&
                kmDiscesa >= (dynamic_cast<const Ciclismo&>(al)).kmDiscesa &&
                kmPianura >= (dynamic_cast<const Ciclismo&>(al)).kmPianura;
        return false;
    } catch (std::bad_cast e) {
        return false;
    }
}

bool Ciclismo::operator<=(const Allenamento& al) const {
    try {
        if(typeid(al) == typeid(const Ciclismo&))
            return Allenamento::operator<=(al) &&
                kmSalita <= (dynamic_cast<const Ciclismo&>(al)).kmSalita &&
                kmDiscesa <= (dynamic_cast<const Ciclismo&>(al)).kmDiscesa &&
                kmPianura <= (dynamic_cast<const Ciclismo&>(al)).kmPianura;
        return false;
    } catch (std::bad_cast e) {
        return false;
    }
}

unsigned int Ciclismo::getKmSalita() const {
    return kmSalita;
}

unsigned int Ciclismo::getKmDiscesa() const {
    return kmDiscesa;
}

unsigned int Ciclismo::getKmPianura() const {
    return kmPianura;
}

void Ciclismo::setKmSalita(unsigned int km) {
    kmSalita = km;
}

void Ciclismo::setKmDiscesa(unsigned int km) {
    kmDiscesa = km;
}

void Ciclismo::setKmPianura(unsigned int km) {
    kmPianura = km;
}
