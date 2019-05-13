#ifndef PERSONA_H
#define PERSONA_H

#include <string>

class Persona {
    std::string nome, cognome;
public:
    Persona(std::string, std::string);
    std::string getNome() const;
    std::string getCognome() const;
    void setNome(std::string);
    void setCognome(std::string);
};

#endif // PERSONA_H
