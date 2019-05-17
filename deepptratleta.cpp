#include "deepptratleta.h"

DeepPtrAtleta::DeepPtrAtleta(Persona*) {

}

DeepPtrAtleta::DeepPtrAtleta(const DeepPtrAtleta&) {

}

DeepPtrAtleta::~DeepPtrAtleta() {

}

bool DeepPtrAtleta::operator==(const DeepPtrAtleta& dptr){
    return atleta->getNome() == dptr.atleta->getNome() &&
           atleta->getCognome() == dptr.atleta->getCognome();
}

DeepPtrAtleta* DeepPtrAtleta::operator->() const {

}

DeepPtrAtleta& DeepPtrAtleta::operator*() const {

}
