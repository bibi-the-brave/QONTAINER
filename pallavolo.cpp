#include "pallavolo.h"
#include "errori.h"

Pallavolo::Pallavolo(std::shared_ptr<Persona> atleta, unsigned int durata,
                     double magnesio, unsigned int schiacc, unsigned int batt,
                     unsigned int bagh)
try: Allenamento(atleta, durata, magnesio), schiacciate(schiacc),
    battute(batt), bagher(bagh)
{
    /* TODO: vedere se lasciare così e toglierlo, magari in allenamento
     ha corso e basta */
    if(schiacc + battute + bagher == 0)
        throw ErrPallavolo();
} catch(ErrAllenamento) {
    throw;
}

std::string Pallavolo::tipo() const {
    return "Pallavolo";
}

Pallavolo* Pallavolo::clone() const {
    return new Pallavolo(*this);
}

unsigned int Pallavolo::calorie() const {
    //TODO: vedere se metterci anche durata, ma lo escludo
    return 2 * schiacciate + 4 * battute + bagher;
}

unsigned int Pallavolo::massaMuscolare() const  {
    return 1;
}

double Pallavolo::grassoPerso() const {
    return (calorie() / 7500) + 0.1 * schiacciate;
}

double Pallavolo::saliMinerali() const {
    return 4 * schiacciate + 4 * battute + 2 * bagher;
}

unsigned int Pallavolo::getSchiacciate() const {
    return schiacciate;
}

unsigned int Pallavolo::getBattute() const {
    return battute;
}

unsigned int Pallavolo::getBagher() const {
    return bagher;
}
