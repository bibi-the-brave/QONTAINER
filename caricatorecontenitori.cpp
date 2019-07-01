#include "caricatorecontenitori.h"
#include <QFile>
#include <QString>
#include <memory>
#include <QXmlStreamReader>
#include <QXmlStreamWriter>
#include "contenitore.h"
#include "persona.h"
#include "allenamento.h"
#include "nuoto.h"
#include "ciclismo.h"
#include "corsa.h"
#include "triathlon.h"
#include "deepptr.h"
#include <string>

#include <QDebug>
#include <QDir>
CaricatoreContenitori::CaricatoreContenitori(Contenitore<std::shared_ptr<Persona>>& atl_,
                                             Contenitore<DeepPtr<Allenamento>>& all_)
    : atl(atl_), all(all_) {}

void CaricatoreContenitori::leggiFile() {
    //qDebug() <<  QDir::currentPath();
    QFile fileAtleti("atleti.xml");
    if (fileAtleti.open(QIODevice::ReadOnly | QIODevice::Text)) {
        lxml.setDevice(&fileAtleti);
        lxml.readNext();

        while(!lxml.atEnd() && !lxml.hasError()) {
            lxml.readNext();
            if(lxml.isStartDocument())
                continue;
            if(lxml.isStartElement()) {
                if(lxml.name() == "atleti")
                    continue;

                if(lxml.name() == "atleta") {
                    Persona p = letturaAtleta();
                    auto sp = std::make_shared<Persona>(p.getNome(), p.getCognome(), p.getSesso());
                    if( !atl.elementoPresente(sp) )
                        atl.pushBack(sp);
                }
            }
        }
        fileAtleti.close();
    } else {
        qDebug() << "errore apertura file";
    }

    lxml.clear();

    QFile fileAllenamenti("allenamenti.xml");
    if (fileAllenamenti.open(QIODevice::ReadOnly | QIODevice::Text)) {
        lxml.setDevice(&fileAllenamenti);
        lxml.readNext();
        while(!lxml.atEnd() && !lxml.hasError()) {
            lxml.readNext();
            //qDebug() << lxml.name() + " 1";
            if(lxml.isStartDocument())
                continue;
            if(lxml.isStartElement()) {
                if(lxml.name() == "allenamenti")
                    continue;
                QString allenamento = lxml.name().toString();
                Allenamento* a = letturaAllenamento(allenamento);
                if( !all.elementoPresente(a) ) {
                    all.pushBack(a);
                    delete a; //perché all fa la copia profonda
                }
            }
        }

        fileAllenamenti.close();
    } else {
        qDebug() << "errore apertura file";
    }
}

Allenamento* CaricatoreContenitori::letturaAllenamento(QString allenamento) {
    Allenamento *a = nullptr;
    lxml.readNextStartElement();
    if(lxml.isStartElement()) {
        Persona p("prova","prova",false);
        if(lxml.name() == "atleta")
            p = letturaAtleta();
        lxml.readNext();
        lxml.readNextStartElement();
        int durata = lxml.readElementText().toInt();
        lxml.readNextStartElement();
        Data data(0,0,0);
        if(lxml.isStartElement()) {
            if(lxml.name() == "data")
                data = letturaData();
        }
        lxml.readNext();
        lxml.readNext();
        lxml.readNextStartElement();
        int magnesio = lxml.readElementText().toInt();

        auto sp = std::make_shared<Persona>(p.getNome(), p.getCognome(), p.getSesso());
        Contenitore<std::shared_ptr<Persona>>::iterator it = atl.begin();
        std::shared_ptr<Persona> pr;
        bool trovato = false;
        for(; it != atl.end() && !trovato; ++it) {
            if(*(it->get()) == *sp.get()) {
                trovato = true;
                pr = *it;
            }
        }

        if(allenamento == "nuoto") {
            int stile, rana, dorso;
            lxml.readNextStartElement();
            stile = lxml.readElementText().toInt();
            lxml.readNextStartElement();
            rana = lxml.readElementText().toInt();
            lxml.readNextStartElement();
            dorso = lxml.readElementText().toInt();
            if(trovato) {
                a = new Nuoto(pr,
                              static_cast<unsigned int>(durata),
                              data,
                              static_cast<unsigned int>(magnesio),
                              static_cast<unsigned int>(stile),
                              static_cast<unsigned int>(rana),
                              static_cast<unsigned int>(dorso));
            }
        } else if(allenamento == "corsa") {
            int sterrato, strada;
            lxml.readNextStartElement();
            sterrato = lxml.readElementText().toInt();
            lxml.readNextStartElement();
            strada = lxml.readElementText().toInt();
            if(trovato) {
                a = new Corsa(pr,
                              static_cast<unsigned int>(durata),
                              data,
                              static_cast<unsigned int>(magnesio),
                              static_cast<unsigned int>(sterrato),
                              static_cast<unsigned int>(strada));
            }
        } else if(allenamento == "ciclismo") {
            int salita, discesa, pianura;
            lxml.readNextStartElement();
            salita = lxml.readElementText().toInt();
            lxml.readNextStartElement();
            discesa = lxml.readElementText().toInt();
            lxml.readNextStartElement();
            pianura = lxml.readElementText().toInt();
            if(trovato) {
                a = new Ciclismo(pr,
                                 static_cast<unsigned int>(durata),
                                 data,
                                 static_cast<unsigned int>(magnesio),
                                 static_cast<unsigned int>(salita),
                                 static_cast<unsigned int>(discesa),
                                 static_cast<unsigned int>(pianura));
            }
        } else if(allenamento == "triathlon") {
            int stile, rana, dorso;
            lxml.readNextStartElement();
            stile = lxml.readElementText().toInt();
            lxml.readNextStartElement();
            rana = lxml.readElementText().toInt();
            lxml.readNextStartElement();
            dorso = lxml.readElementText().toInt();
            int salita, discesa, pianura;
            lxml.readNextStartElement();
            salita = lxml.readElementText().toInt();
            lxml.readNextStartElement();
            discesa = lxml.readElementText().toInt();
            lxml.readNextStartElement();
            pianura = lxml.readElementText().toInt();
            int sterrato, strada;
            lxml.readNextStartElement();
            sterrato = lxml.readElementText().toInt();
            lxml.readNextStartElement();
            strada = lxml.readElementText().toInt();
            if(trovato) {
                a = new Triathlon(pr,
                                  static_cast<unsigned int>(durata),
                                  data,
                                  static_cast<unsigned int>(magnesio),
                                  static_cast<unsigned int>(stile),
                                  static_cast<unsigned int>(rana),
                                  static_cast<unsigned int>(dorso),
                                  static_cast<unsigned int>(salita),
                                  static_cast<unsigned int>(discesa),
                                  static_cast<unsigned int>(pianura),
                                  static_cast<unsigned int>(sterrato),
                                  static_cast<unsigned int>(strada));
            }
        }
        lxml.readNext();
    }
    return a;
}

Data CaricatoreContenitori::letturaData() {
    int d,m,y;
    lxml.readNextStartElement();
    d = lxml.readElementText().toInt();
    lxml.readNextStartElement();
    m = lxml.readElementText().toInt();
    lxml.readNextStartElement();
    y = lxml.readElementText().toInt();
    lxml.readNext();
    return Data(y,m,d);
}

Persona CaricatoreContenitori::letturaAtleta() {
    std::string nome, cognome;
    bool sesso;
    lxml.readNextStartElement();
    nome = lxml.readElementText().toStdString();//qDebug() << QString::fromStdString(nome);
    lxml.readNextStartElement();
    cognome = lxml.readElementText().toStdString();//qDebug() << QString::fromStdString(cognome);
    lxml.readNextStartElement();
    sesso = lxml.readElementText() == "true" ? true : false;//qDebug() << sesso;
    lxml.readNext();
    return Persona(nome, cognome, sesso);
}

/*
qDebug() << "stile " + QString::fromStdString(std::to_string(stile)) +
            " rana " + QString::fromStdString(std::to_string(rana)) +
            " dorso " + QString::fromStdString(std::to_string(dorso));
            "salita " + QString::fromStdString(std::to_string(salita)) +
            " discesa " + QString::fromStdString(std::to_string(discesa)) +
            " pianura " + QString::fromStdString(std::to_string(pianura)) +
            " sterrato " + QString::fromStdString(std::to_string(sterrato)) +
            " strada " + QString::fromStdString(std::to_string(strada));
 */

void CaricatoreContenitori::scriviFile() {

}

void CaricatoreContenitori::scritturaFileAtleti() {
    /*QFile file("atleti.xml");
    file.open(QIODevice::WriteOnly);

    sxml.
    QXmlStreamWriter xmlWriter(&file);
    xmlWriter.setAutoFormatting(true);
    xmlWriter.writeStartDocument();*/
}
