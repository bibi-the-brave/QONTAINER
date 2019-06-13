#include "ciclismo.h"
#include "errori.h"
#include <typeinfo>

Ciclismo::Ciclismo(std::shared_ptr<Persona> atleta, unsigned int durata,
                   double mgMagnesio, unsigned int salita,
                   unsigned int pianura, unsigned int discesa)
try: Allenamento(atleta, durata, mgMagnesio), kmSalita(salita),
     kmPianura(pianura), kmDiscesa(discesa)
{
    //if(kmSalita + kmPianura + kmDiscesa == 0)
    //    throw ErrCiclismo();
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
    return (400 * kmTot * kmTot) / getDurata() + 30 * kmSalita + 10 * kmPianura;
}

double Ciclismo::grassoPerso() const {
    return (calorie() / 7500) + (110 * kmSalita)/7500
            + (45 * kmDiscesa)/7500 + (90 * kmPianura)/7500;
}

double Ciclismo::saliMinerali() const {
    return 110.0 * kmSalita + 90 * kmPianura;
}

bool Ciclismo::operator==(const Allenamento& al) const {
    try {
        const Ciclismo& t = dynamic_cast<const Ciclismo&>(al); //se ok non viene lanciata eccezione
        return Allenamento::operator==(al) &&
                kmSalita == (dynamic_cast<const Ciclismo&>(al)).kmSalita &&
                kmDiscesa == (dynamic_cast<const Ciclismo&>(al)).kmDiscesa &&
                kmPianura == (dynamic_cast<const Ciclismo&>(al)).kmPianura;
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
