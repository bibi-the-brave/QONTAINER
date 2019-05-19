#include "deepptratleta.h"
#include "errori.h"

DeepPtrAtleta::DeepPtrAtleta(Persona* a)
try : atleta(a->clone()) {
} catch (...) {
    throw ErrPersona();
}

DeepPtrAtleta::DeepPtrAtleta(const DeepPtrAtleta& dpt)
try : atleta(dpt.atleta->clone()) {
} catch (...) {
    throw ErrPersona();
}

DeepPtrAtleta::~DeepPtrAtleta() {
    delete atleta;
}

DeepPtrAtleta& DeepPtrAtleta::operator=(const DeepPtrAtleta& a) {
    if(this != &a) {
        delete atleta;
        if(a.atleta)
            atleta = a.atleta->clone();
    }
    return *this;
}

bool DeepPtrAtleta::operator==(const DeepPtrAtleta& dptr) const{
    return atleta == dptr.atleta;
}

Persona* DeepPtrAtleta::operator->() const {
    return atleta;
}

Persona& DeepPtrAtleta::operator*() const {
    return *atleta;
}
