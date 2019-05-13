#include "triathlon.h"
#include "errori.h"

Triathlon::Triathlon(std::string nome, std::string cognome, double mgMagnesio,
                     unsigned int durCorsa,
                     unsigned int durNuoto, unsigned int durCiclismo,
                     unsigned int vascheLibero, unsigned int vascheRana,
                     unsigned int vascheDorso, unsigned int kmSterrato,
                     unsigned int kmStrada, unsigned int kmSalita,
                     unsigned int kmPianura, unsigned int kmDiscesa)
try: Allenamento(nome, cognome, durCorsa+durNuoto+durCiclismo, mgMagnesio),
    Nuoto(nome, cognome, durCorsa+durNuoto+durCiclismo, mgMagnesio,
          vascheLibero, vascheRana, vascheDorso),
    Ciclismo(nome, cognome, durCorsa+durNuoto+durCiclismo, mgMagnesio,
          kmSalita, kmPianura, kmDiscesa),
    Corsa(nome, cognome, durCorsa+durNuoto+durCiclismo, mgMagnesio,
          kmSterrato, kmStrada),
    durataNuoto(durNuoto), durataCiclismo(durCiclismo), durataCorsa(durCorsa)
{
    if(durataNuoto + durataCorsa + durataCiclismo == 0)
        throw ErrTriathlon();
} catch(...) { //catch di tutte le eccezioni lanciate dai costruttori dei sottooggetti
    throw;
}

Triathlon* Triathlon::clone() const {
    return new Triathlon(*this);
}

unsigned int Triathlon::calorie() const {
    unsigned int kmTotCicl = getKmSalita() + getKmDiscesa() + getKmPianura();
    unsigned int kmTotCorsa = getKmSterrato() + getKmStrada();
    return
        // calorie nuoto
        Nuoto::calorie()
        +
        // calorie ciclismo
        (90 * kmTotCicl * kmTotCicl) / durataCiclismo +
            30 * getKmSalita() + 10 * getKmPianura()
        +
        // calorie corsa
        (800 * kmTotCorsa * kmTotCorsa) / durataCorsa + getKmSterrato()/2;
}

unsigned int Triathlon::massaMuscolare() const  {
    return 1;
}

double Triathlon::grassoPerso() const {
    return Nuoto::grassoPerso() + Ciclismo::grassoPerso() + Corsa::grassoPerso();
}

double Triathlon::saliMinerali() const {
    return Nuoto::saliMinerali() + Ciclismo::saliMinerali() + Corsa::saliMinerali();
}

unsigned int Triathlon::getDurataNuoto() const {
    return durataNuoto;
}

unsigned int Triathlon::getDurataCiclismo() const {
    return durataCiclismo;
}

unsigned int Triathlon::getDurataCorsa() const {
    return durataCorsa;
}

