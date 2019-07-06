#include "allenamento.h"
#include "errori.h"
#include "persona.h"
#include "data.h"

Allenamento::Allenamento(std::shared_ptr<Persona> atl,
                         unsigned int dur,
                         Data d,
                         unsigned int mgMagnesio)
try: atleta(atl), durata(dur), data(d), mgMagnesioAssunti(mgMagnesio)
{
   if(durata == 0)
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

bool Allenamento::operator>=(const Allenamento& al) const {
    return atleta->getPersona() == al.getAtleta() &&
            durata >= al.durata &&
            data >= al.data &&
            mgMagnesioAssunti >= al.mgMagnesioAssunti;
}

bool Allenamento::operator<=(const Allenamento& al) const {
    return atleta->getPersona() == al.getAtleta() &&
            durata <= al.durata &&
            data <= al.data &&
            mgMagnesioAssunti <= al.mgMagnesioAssunti;
}

Persona Allenamento::getAtleta() const {
    return atleta->getPersona();
}

std::shared_ptr<Persona> Allenamento::getSharedAtleta() const {
    return atleta;
}

unsigned int Allenamento::getMgMagnesioAssunti() const {
    return mgMagnesioAssunti;
}

unsigned int Allenamento::getDurata() const {
    return durata;
}

Data Allenamento::getData() const {
    return data;
}

void Allenamento::setAtleta(std::shared_ptr<Persona> a) {
    atleta = a;
}

void Allenamento::setData(const Data& d) {
    data = d;
}

void Allenamento::setMgMagnesio(unsigned int mgM) {
    mgMagnesioAssunti = mgM;
}

void Allenamento::setDurata(unsigned int d){
    durata = d;
}
