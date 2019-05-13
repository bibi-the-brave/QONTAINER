#include "ciclismo.h"
#include "errori.h"

Ciclismo::Ciclismo(std::string nome, std::string cognome, unsigned int durata,
                   double mgMagnesio, unsigned int salita,
                   unsigned int discesa, unsigned int pianura)
try: Allenamento(nome, cognome, durata, mgMagnesio), kmSalita(salita),
    kmDiscesa(discesa), kmPianura(pianura)
{
    //if(kmSalita + kmPianura + kmDiscesa == 0)
    //    throw ErrCiclismo();
} catch (ErrAllenamento) {
    throw;
}

Ciclismo* Ciclismo::clone() const {
    return new Ciclismo(*this);
}

unsigned int Ciclismo::calorie() const {
    unsigned int kmTot = kmSalita + kmDiscesa + kmPianura;
    return (400 * kmTot * kmTot) / getDurata() + 30 * kmSalita + 10 * kmPianura;
}

unsigned int Ciclismo::massaMuscolare() const  {
    return 1;
}

double Ciclismo::grassoPerso() const {
    return (calorie() / 7500) + (110 * kmSalita)/7500
            + (45 * kmDiscesa)/7500 + (90 * kmPianura)/7500;
}

double Ciclismo::saliMinerali() const {
    return 110.0 * kmSalita + 90 * kmPianura;
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
