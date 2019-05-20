#include "calcio.h"
#include "errori.h"
#include <memory>

Calcio::Calcio(std::shared_ptr<Persona> atleta,
               unsigned int durata, double magnesio,
               unsigned int km, unsigned int filtranti, unsigned int collo,
               unsigned int laterali, unsigned int fondo, unsigned int tPorta)
try: Allenamento (atleta, durata, magnesio), kmPercorsi(km),
    passaggiFiltranti(filtranti), passaggiDiCollo(collo),
    rimesseLaterali(laterali), rimesseDalFondo(fondo), tiriPorta(tPorta)
{
    //if(kmPercorsi == 0)
    //    throw  ErrCalcio();
} catch(ErrAllenamento) {
    throw;
}

Calcio* Calcio::clone() const {
    return new Calcio(*this);
}

unsigned int Calcio::calorie() const {
    return (600 * kmPercorsi)/getDurata() + passaggiFiltranti / 6
            + passaggiDiCollo / 4 + rimesseLaterali / 8
            + rimesseDalFondo / 3 + tiriPorta / 2;
}

unsigned int Calcio::massaMuscolare() const {
    return 1;
}

double Calcio::grassoPerso() const {
    return (calorie() / 7500) + (90 * kmPercorsi)/7500
            + 0.2 * rimesseDalFondo + 0.1 * tiriPorta;
}

double Calcio::saliMinerali() const {
    return 90.0 * kmPercorsi + passaggiDiCollo + rimesseDalFondo + 2 * tiriPorta
            + 0.25 * rimesseLaterali + 0.25 * passaggiFiltranti;
}
