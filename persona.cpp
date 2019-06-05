#include "persona.h"
#include "errori.h"
#include <string>

Persona::Persona(std::string n, std::string c, bool s) : nome(n), cognome(c), sesso(s)
{
    if( !(nome.find_first_not_of(' ') != std::string::npos) ||
        !(cognome.find_first_not_of(' ') != std::string::npos) )
    {
        throw ErrPersona();
    }
}

Persona::Persona(const Persona& persona) {
    nome = persona.nome;
    cognome = persona.cognome;
    sesso = persona.sesso;
}

Persona& Persona::operator=(const Persona& p) {
    if(this != &p) {
        nome = p.nome;
        cognome = p.cognome;
        sesso = p.sesso;
    }
    return *this;
}

bool Persona::operator==(const Persona& p) const {
    return nome == p.nome && cognome == p.cognome && sesso == p.sesso;
}

std::string Persona::getNome() const{
    return nome;
}

std::string Persona::getCognome() const {
    return cognome;
}

bool Persona::getSesso() const {
    return sesso;
}

std::string Persona::getSessoStr() const {
    if(!sesso)
        return std::string("Uomo");
    return std::string("Donna");
}

void Persona::setNome(std::string n) {
    if(!(n.find_first_not_of(' ') != std::string::npos))
        throw ErrPersona();
    nome = n;
}

void Persona::setCognome(std::string c) {
    if(!(c.find_first_not_of(' ') != std::string::npos))
        throw ErrPersona();
    cognome = c;
}

void Persona::setSesso(bool s) {
    sesso = s;
}

Persona Persona::getPersona() const {
    return Persona(*this);
}

Persona* Persona::clone() const {
    return new Persona(*this);
}

