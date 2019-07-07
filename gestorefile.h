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

class GestoreFile {
public:
    GestoreFile(Contenitore<std::shared_ptr<Persona>>&,
                          Contenitore<DeepPtr<Allenamento>>&);
    void letturaFile(QString, QString);
    void scritturaFileAtleti();
    void scritturaFileAllenamenti();
    bool filePresente(QString) const;
private:
    Contenitore<std::shared_ptr<Persona>>& atl;
    Contenitore<DeepPtr<Allenamento>>& all;

    QXmlStreamReader lxml;
    QXmlStreamWriter sxml;

    Allenamento* letturaAllenamento(QString);
    Data letturaData();
    Persona letturaAtleta();

    void scritturaData(int y, int m, int d);
    void scritturaAttributiNuoto(int, int, int);
    void scritturaAttributiCiclismo(int, int, int);
    void scritturaAttributiCorsa(int, int);
    void scritturaAtleta(QString, QString, QString);
    void scritturaNuoto(Allenamento*);
    void scritturaCiclismo(Allenamento*);
    void scritturaCorsa(Allenamento*);
    void scritturaTriathlon(Allenamento*);
    void viasualizzaDialogErrore() const;
};

#endif // CARICATORECONTENITORI_H
