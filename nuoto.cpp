#include "nuoto.h"
#include "errori.h"
#include <string>

Nuoto::Nuoto(std::string nome, std::string cognome, unsigned int durata,
             double mgMagnesio, unsigned int sLibero, unsigned int sRana,
             unsigned int sDorso)
try: Allenamento (nome, cognome, durata, mgMagnesio), vascheStileLibero(sLibero),
    vascheRana(sRana), vascheDorso(sDorso)
{
    if(vascheStileLibero + vascheRana + vascheDorso == 0)
        throw ErrNuoto();
} catch(ErrAllenamento) {
    throw;
}

Nuoto* Nuoto::clone() const {
    return new Nuoto(*this);
}

unsigned int Nuoto::calorie() const {
    return 50 * vascheStileLibero + 25 * vascheRana + 40 * vascheDorso;
}


unsigned int Nuoto::massaMuscolare() const  {
    return 1;
}


double Nuoto::grassoPerso() const {
    return (calorie() / 7500) + 0.5 * vascheStileLibero + 0.5 * vascheRana
            + 0.25 * vascheDorso;
}

double Nuoto::saliMinerali() const {
    return 25.0 * vascheStileLibero + 10.0* vascheDorso + 15.0 *vascheRana;
}

unsigned int Nuoto::getVascheStileLibero() const {
    return vascheStileLibero;
}

unsigned int Nuoto::getVascheRana() const {
    return  vascheRana;
}

unsigned int Nuoto::getVascheDorso() const {
    return vascheDorso;
}
