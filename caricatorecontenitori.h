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
#include <QXmlStreamReader>
#include <QXmlStreamWriter>

class CaricatoreContenitori {
public:
    CaricatoreContenitori(Contenitore<std::shared_ptr<Persona>>&,
                          Contenitore<DeepPtr<Allenamento>>&);
    void leggiFile();
    void scriviFile();
private:
    Contenitore<std::shared_ptr<Persona>>& atl;
    Contenitore<DeepPtr<Allenamento>>& all;

    QXmlStreamReader lxml;
    QXmlStreamWriter sxml;

    Allenamento* letturaAllenamento(QString);
    Data letturaData();
    Persona letturaAtleta();
};

#endif // CARICATORECONTENITORI_H
