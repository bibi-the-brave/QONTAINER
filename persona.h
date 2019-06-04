#ifndef PERSONA_H
#define PERSONA_H

#include <string>

class Persona {
    std::string nome, cognome;
    bool sesso; //0 uomo, 1 donna
public:
    Persona(std::string, std::string, bool = 0);
    Persona(const Persona&);
    Persona& operator=(const Persona&);
    bool operator==(const Persona&) const;
    std::string getNome() const;
    std::string getCognome() const;
    bool getSesso() const;
    void setNome(std::string);
    void setCognome(std::string);
    void setSesso(bool);
    Persona getPersona() const;
    Persona* clone() const;
};

#endif // PERSONA_H
