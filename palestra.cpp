#include "palestra.h"
#include "errori.h"

Palestra::Palestra(std::string nome, std::string cognome, unsigned int durata,
                   double magnesio, unsigned int addom, unsigned int flex,
                   unsigned int pesi, unsigned int kPesi)
try: Allenamento(nome, cognome, durata, magnesio), addominali(addom),
    flessioni(flex), numeroPesi(pesi), kgPesi(kPesi)
{
    if(addominali + flessioni + numeroPesi + kgPesi == 0)
        throw ErrPalestra();
} catch(ErrAllenamento) {
    throw;
}

Palestra* Palestra::clone() const {
    return new Palestra(*this);
}

unsigned int Palestra::calorie() const {
    return 3 * addominali + 3 * flessioni + (numeroPesi * kgPesi) / 3;
}

unsigned int Palestra::massaMuscolare() const  {
    return 1;
}

double Palestra::grassoPerso() const {
    return (calorie() / 7500);
}

double Palestra::saliMinerali() const {
    return 5.0 * addominali + 3.0 * flessioni + 10.0 * numeroPesi * kgPesi;
}

unsigned int Palestra::getAddominali() const {
    return addominali;
}

unsigned int Palestra::getFlessioni() const {
    return flessioni;
}

unsigned int Palestra::getNumeroPesi() const {
    return numeroPesi;
}

unsigned int Palestra::getKgPesi() const {
    return kgPesi;
}
