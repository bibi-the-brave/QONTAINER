#include "allenamento.h"
#include "errori.h"
#include "persona.h"
#include "data.h"

Allenamento::Allenamento(std::shared_ptr<Persona> atl,
                         unsigned int dur,
                         Data d,
                         double mgMagnesio)
try: atleta(atl), durata(dur), data(d), mgMagnesioAssunti(mgMagnesio)
{
   if(mgMagnesio < 0 || durata == 0)
       throw ErrAllenamento();
} catch(ErrPersona) {
    throw;
}

bool Allenamento::operator==(const Allenamento& allenamento) const {
    return atleta->getPersona() == allenamento.getAtleta() &&
           durata == allenamento.durata &&
           data == allenamento.data &&
           mgMagnesioAssunti == allenamento.mgMagnesioAssunti;
}

Persona Allenamento::getAtleta() const {
    return atleta->getPersona();
}

double Allenamento::getMgMagnesioAssunti() const {
    return mgMagnesioAssunti;
}

unsigned int Allenamento::getDurata() const {
    return durata;
}

Data Allenamento::getData() const {
    return data;
}
