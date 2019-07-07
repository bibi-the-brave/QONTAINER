#include "nuoto.h"
#include "errori.h"
#include <string>
#include <typeinfo>

Nuoto::Nuoto(std::shared_ptr<Persona> atleta, unsigned int durata, Data data,
             unsigned int mgMagnesio, unsigned int sLibero, unsigned int sRana,
             unsigned int sDorso)
try: Allenamento (atleta, durata, data, mgMagnesio), vascheStileLibero(sLibero),
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

unsigned int Nuoto::grassoPerso() const {
    return static_cast<unsigned int>( (calorie() / 7500) + 0.5 * vascheStileLibero + 0.5 * vascheRana
            + 0.25 * vascheDorso );
}

unsigned int Nuoto::saliMinerali() const {
    return static_cast<unsigned int>( 25 * vascheStileLibero + 10 * vascheDorso + 15 * vascheRana);
}

bool Nuoto::operator==(const Allenamento& al) const {
    try {
        if(typeid(al) == typeid(const Nuoto&))
            return Allenamento::operator==(al) &&
                vascheRana == (dynamic_cast<const Nuoto&>(al)).vascheRana &&
                vascheStileLibero == (dynamic_cast<const Nuoto&>(al)).vascheStileLibero &&
                vascheDorso == (dynamic_cast<const Nuoto&>(al)).vascheDorso;
        return false;
    } catch (std::bad_cast e) {
        return false;
    }

}

bool Nuoto::operator>=(const Allenamento& al) const {
    try {
        if(typeid(al) == typeid(const Nuoto&))
            return Allenamento::operator>=(al) &&
                vascheRana >= (dynamic_cast<const Nuoto&>(al)).vascheRana &&
                vascheStileLibero >= (dynamic_cast<const Nuoto&>(al)).vascheStileLibero &&
                vascheDorso >= (dynamic_cast<const Nuoto&>(al)).vascheDorso;
        return false;
    } catch (std::bad_cast e) {
        return false;
    }
}

bool Nuoto::operator<=(const Allenamento& al) const {
    try {
        if(typeid(al) == typeid(const Nuoto&))
            return Allenamento::operator<=(al) &&
                vascheRana <= (dynamic_cast<const Nuoto&>(al)).vascheRana &&
                vascheStileLibero <= (dynamic_cast<const Nuoto&>(al)).vascheStileLibero &&
                vascheDorso <= (dynamic_cast<const Nuoto&>(al)).vascheDorso;
        return false;
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

void Nuoto::setVascheStileLibero(unsigned int v) {
    vascheStileLibero = v;
}

void Nuoto::setVascheRana(unsigned int v) {
    vascheRana = v;
}

void Nuoto::setVascheDorso(unsigned int v) {
    vascheDorso = v;
}
