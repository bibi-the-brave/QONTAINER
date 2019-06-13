#include "nuoto.h"
#include "errori.h"
#include <string>
#include <typeinfo>

Nuoto::Nuoto(std::shared_ptr<Persona> atleta, unsigned int durata,
             double mgMagnesio, unsigned int sLibero, unsigned int sRana,
             unsigned int sDorso)
try: Allenamento (atleta, durata, mgMagnesio), vascheStileLibero(sLibero),
    vascheRana(sRana), vascheDorso(sDorso)
{
    if(vascheStileLibero + vascheRana + vascheDorso == 0)
        throw ErrNuoto();
} catch(ErrAllenamento) {
    throw;
}

std::string Nuoto::tipo() const {
    return "Nuoto";
}

Nuoto* Nuoto::clone() const {
    return new Nuoto(*this);
}

unsigned int Nuoto::calorie() const {
    return 50 * vascheStileLibero + 25 * vascheRana + 40 * vascheDorso;
}

double Nuoto::grassoPerso() const {
    return (calorie() / 7500) + 0.5 * vascheStileLibero + 0.5 * vascheRana
            + 0.25 * vascheDorso;
}

double Nuoto::saliMinerali() const {
    return 25.0 * vascheStileLibero + 10.0* vascheDorso + 15.0 *vascheRana;
}

bool Nuoto::operator==(const Allenamento& al) const {
    try {
        const Nuoto& t = dynamic_cast<const Nuoto&>(al); //se ok non viene lanciata eccezione
        return Allenamento::operator==(al) &&
                vascheRana == (dynamic_cast<const Nuoto&>(al)).vascheRana &&
                vascheStileLibero == (dynamic_cast<const Nuoto&>(al)).vascheStileLibero &&
                vascheDorso == (dynamic_cast<const Nuoto&>(al)).vascheDorso;
    } catch (std::bad_cast e) {
        return false;
    }

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
