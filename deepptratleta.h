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
    bool operator==(const DeepPtrAtleta&);
    DeepPtrAtleta* operator->() const;
    DeepPtrAtleta& operator*() const;
};

#endif // DEEPPTRATLETA_H
