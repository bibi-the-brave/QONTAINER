#ifndef CARICATORECONTENITORI_H
#define CARICATORECONTENITORI_H

#include "contenitore.h"
#include <memory>
#include "persona.h"
#include "allenamento.h"
#include "nuoto.h"
#include "ciclismo.h"
#include "corsa.h"
#include "triathlon.h"
#include "deepptr.h"
#include <QFile>
#include <QJsonDocument>

class CaricatoreContenitori {
public:
    CaricatoreContenitori(Contenitore<std::shared_ptr<Persona>>&,
                          Contenitore<DeepPtr<Allenamento>>&);
    void leggiFile();
    void scriviFile();
private:
    Contenitore<std::shared_ptr<Persona>>& atl;
    Contenitore<DeepPtr<Allenamento>>& all;
};

#endif // CARICATORECONTENITORI_H
