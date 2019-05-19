#ifndef DEEPPTRATLETA_H
#define DEEPPTRATLETA_H
//qmake make
#include "persona.h"
#include <QString>

class DeepPtrAtleta {
private:
    Persona* atleta;
public:
    DeepPtrAtleta(Persona*);
    DeepPtrAtleta(const DeepPtrAtleta&);
    ~DeepPtrAtleta();
    DeepPtrAtleta& operator=(const DeepPtrAtleta&);
    bool operator==(const DeepPtrAtleta&) const;
    Persona* operator->() const;
    Persona& operator*() const;
};

#endif // DEEPPTRATLETA_H
