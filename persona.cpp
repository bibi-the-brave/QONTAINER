#include "persona.h"
#include "errori.h"

Persona::Persona(std::string n, std::string c) : nome(n), cognome(c)
{
    if( !(nome.find_first_not_of(' ') != std::string::npos) ||
        !(cognome.find_first_not_of(' ') != std::string::npos) )
    {
        throw ErrPersona();
    }
}

std::string Persona::getNome() const{
    return nome;
}

std::string Persona::getCognome() const {
    return cognome;
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
