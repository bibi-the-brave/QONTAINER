#include "allenamento.h"
#include "errori.h"
#include "persona.h"

Allenamento::Allenamento(std::string nomeAtleta,
                         std::string cognomeAtleta,
                         unsigned int dur,
                         double mgMagnesio)
try: atleta(nomeAtleta, cognomeAtleta), durata(dur), mgMagnesioAssunti(mgMagnesio)
{
   if( mgMagnesio < 0 || durata == 0 )
       throw ErrAllenamento();
} catch(ErrPersona) {
    throw;
}

Persona Allenamento::getAtleta() const {
    return atleta;
}

double Allenamento::getMgMagnesioAssunti() const {
    return mgMagnesioAssunti;
}

unsigned int Allenamento::getDurata() const {
    return durata;
}
