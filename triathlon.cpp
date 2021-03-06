/*
 * Andrea Favero
 * 1125545
 * andrea.favero.8@studenti.unipd.it
 */
#include "triathlon.h"
#include "errori.h"
#include <typeinfo>

Triathlon::Triathlon(std::shared_ptr<Persona> atleta,  unsigned int durata,
                     Data data, unsigned int mgMagnesio,
                     unsigned int vascheLibero, unsigned int vascheRana,
                     unsigned int vascheDorso, unsigned int kmSterrato,
                     unsigned int kmStrada, unsigned int kmSalita,
                     unsigned int kmPianura, unsigned int kmDiscesa)
try: Allenamento(atleta, durata, data, mgMagnesio),
    Nuoto(atleta, durata, data, mgMagnesio, vascheLibero, vascheRana, vascheDorso),
    Ciclismo(atleta, durata, data, mgMagnesio, kmSalita, kmPianura, kmDiscesa),
    Corsa(atleta, durata, data, mgMagnesio, kmSterrato, kmStrada)
{} catch(...) { //catch di tutte le eccezioni lanciate dai costruttori dei sottooggetti
    throw;
}

std::string Triathlon::tipo() const {
    return "Triathlon";
}

Triathlon* Triathlon::clone() const {
    return new Triathlon(*this);
}

unsigned int Triathlon::calorie() const {
    return
        // calorie nuoto
        Nuoto::calorie() / 2
        +
        // calorie ciclismo
        Ciclismo::calorie() / 2
        +
        // calorie corsa
        Corsa::calorie() / 2;
}

unsigned int Triathlon::grassoPerso() const {
    return Nuoto::grassoPerso() + Ciclismo::grassoPerso() + Corsa::grassoPerso();
}

unsigned int Triathlon::saliMinerali() const {
    return Nuoto::saliMinerali() + Ciclismo::saliMinerali() + Corsa::saliMinerali();
}

bool Triathlon::operator==(const Allenamento& al) const {
    try {
        if(typeid(al) == typeid(const Triathlon&))
            return Allenamento::operator==(al) &&
                getVascheRana() == (dynamic_cast<const Nuoto&>(al)).getVascheRana() &&
                getVascheStileLibero() == (dynamic_cast<const Nuoto&>(al)).getVascheStileLibero() &&
                getVascheDorso() == (dynamic_cast<const Nuoto&>(al)).getVascheDorso() &&
                getKmSalita() == (dynamic_cast<const Ciclismo&>(al)).getKmSalita() &&
                getKmDiscesa() == (dynamic_cast<const Ciclismo&>(al)).getKmDiscesa() &&
                getKmPianura() == (dynamic_cast<const Ciclismo&>(al)).getKmPianura() &&
                getKmStrada() == (dynamic_cast<const Corsa&>(al)).getKmStrada() &&
                getKmSterrato() == (dynamic_cast<const Corsa&>(al)).getKmSterrato();
        return false;
    } catch (std::bad_cast e) {
        return false;
    }
}

bool Triathlon::operator>=(const Allenamento& al) const {
    try {
        if(typeid(al) == typeid(const Triathlon&))
            return Allenamento::operator>=(al) &&
                getVascheRana() >= (dynamic_cast<const Nuoto&>(al)).getVascheRana() &&
                getVascheStileLibero() >= (dynamic_cast<const Nuoto&>(al)).getVascheStileLibero() &&
                getVascheDorso() >= (dynamic_cast<const Nuoto&>(al)).getVascheDorso() &&
                getKmSalita() >= (dynamic_cast<const Ciclismo&>(al)).getKmSalita() &&
                getKmDiscesa() >= (dynamic_cast<const Ciclismo&>(al)).getKmDiscesa() &&
                getKmPianura() >= (dynamic_cast<const Ciclismo&>(al)).getKmPianura() &&
                getKmStrada() >= (dynamic_cast<const Corsa&>(al)).getKmStrada() &&
                getKmSterrato() >= (dynamic_cast<const Corsa&>(al)).getKmSterrato();
        return false;
    } catch (std::bad_cast e) {
        return false;
    }
}

bool Triathlon::operator<=(const Allenamento& al) const {
    try {
        if(typeid(al) == typeid(const Triathlon&))
            return Allenamento::operator<=(al) &&
                getVascheRana() <= (dynamic_cast<const Nuoto&>(al)).getVascheRana() &&
                getVascheStileLibero() <= (dynamic_cast<const Nuoto&>(al)).getVascheStileLibero() &&
                getVascheDorso() <= (dynamic_cast<const Nuoto&>(al)).getVascheDorso() &&
                getKmSalita() <= (dynamic_cast<const Ciclismo&>(al)).getKmSalita() &&
                getKmDiscesa() <= (dynamic_cast<const Ciclismo&>(al)).getKmDiscesa() &&
                getKmPianura() <= (dynamic_cast<const Ciclismo&>(al)).getKmPianura() &&
                getKmStrada() <= (dynamic_cast<const Corsa&>(al)).getKmStrada() &&
                getKmSterrato() <= (dynamic_cast<const Corsa&>(al)).getKmSterrato();
        return false;
    } catch (std::bad_cast e) {
        return false;
    }
}

