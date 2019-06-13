#include "triathlon.h"
#include "errori.h"
#include <typeinfo>

Triathlon::Triathlon(std::shared_ptr<Persona> atleta, double mgMagnesio, unsigned int durata,
                     unsigned int vascheLibero, unsigned int vascheRana,
                     unsigned int vascheDorso, unsigned int kmSterrato,
                     unsigned int kmStrada, unsigned int kmSalita,
                     unsigned int kmPianura, unsigned int kmDiscesa)
try: Allenamento(atleta, durata, mgMagnesio),
    Nuoto(atleta, durata, mgMagnesio, vascheLibero, vascheRana, vascheDorso),
    Ciclismo(atleta, durata, mgMagnesio, kmSalita, kmPianura, kmDiscesa),
    Corsa(atleta, durata, mgMagnesio, kmSterrato, kmStrada)
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
        Nuoto::calorie()
        +
        // calorie ciclismo
        Ciclismo::calorie()
        +
        // calorie corsa
        Corsa::calorie();
}

double Triathlon::grassoPerso() const {
    return Nuoto::grassoPerso() + Ciclismo::grassoPerso() + Corsa::grassoPerso();
}

double Triathlon::saliMinerali() const {
    return Nuoto::saliMinerali() + Ciclismo::saliMinerali() + Corsa::saliMinerali();
}
#include <QDebug>
bool Triathlon::operator==(const Allenamento& al) const {
    try {
        Triathlon& t = dynamic_cast<Triathlon&>(t);
        return Nuoto::operator==(al) && Corsa::operator==(al) && Ciclismo::operator==(al);
    } catch (std::bad_cast e) {
        return false;
    }
}


