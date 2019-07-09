/*
 * Andrea Favero
 * 1125545
 * andrea.favero.8@studenti.unipd.it
 */
#include "gestorefile.h"
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
#include <QMessageBox>

GestoreFile::GestoreFile(Contenitore<std::shared_ptr<Persona>>& atl_,
                         Contenitore<DeepPtr<Allenamento>>& all_)
    : atl(atl_), all(all_) {}

void GestoreFile::letturaFile(QString atleti, QString allenamenti) {
    QFile fileAtleti(atleti);
    if (fileAtleti.open(QIODevice::ReadOnly | QIODevice::Text)) {
        try {
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
        } catch(...) {
            viasualizzaDialogErrore();
        }
    } else {
        viasualizzaDialogErrore();
    }

    lxml.clear();

    QFile fileAllenamenti(allenamenti);
    if (fileAllenamenti.open(QIODevice::ReadOnly | QIODevice::Text)) {
        lxml.setDevice(&fileAllenamenti);
        lxml.readNext();
        while(!lxml.atEnd() && !lxml.hasError()) {
            lxml.readNext();
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
        //viasualizzaDialogErrore();
    }
}

Allenamento* GestoreFile::letturaAllenamento(QString allenamento) {
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
            pianura = lxml.readElementText().toInt();
            lxml.readNextStartElement();
            discesa = lxml.readElementText().toInt();
            if(trovato) {
                a = new Ciclismo(pr,
                                 static_cast<unsigned int>(durata),
                                 data,
                                 static_cast<unsigned int>(magnesio),
                                 static_cast<unsigned int>(salita),
                                 static_cast<unsigned int>(pianura),
                                 static_cast<unsigned int>(discesa));
            }
        } else if(allenamento == "triathlon") {
            int stile, rana, dorso;
            lxml.readNextStartElement();
            stile = lxml.readElementText().toInt();
            lxml.readNextStartElement();
            rana = lxml.readElementText().toInt();
            lxml.readNextStartElement();
            dorso = lxml.readElementText().toInt();
            int sterrato, strada;
            lxml.readNextStartElement();
            sterrato = lxml.readElementText().toInt();
            lxml.readNextStartElement();
            strada = lxml.readElementText().toInt();
            int salita, pianura, discesa;
            lxml.readNextStartElement();
            salita = lxml.readElementText().toInt();
            lxml.readNextStartElement();
            pianura = lxml.readElementText().toInt();
            lxml.readNextStartElement();
            discesa = lxml.readElementText().toInt();
            if(trovato) {
                a = new Triathlon(pr,
                                  static_cast<unsigned int>(durata),
                                  data,
                                  static_cast<unsigned int>(magnesio),
                                  static_cast<unsigned int>(stile),
                                  static_cast<unsigned int>(rana),
                                  static_cast<unsigned int>(dorso),
                                  static_cast<unsigned int>(sterrato),
                                  static_cast<unsigned int>(strada),
                                  static_cast<unsigned int>(salita),
                                  static_cast<unsigned int>(pianura),
                                  static_cast<unsigned int>(discesa));
            }
        }
        lxml.readNext();
    }
    return a;
}

Data GestoreFile::letturaData() {
    int d,m,y;
    lxml.readNextStartElement();
    y = lxml.readElementText().toInt();
    lxml.readNextStartElement();
    m = lxml.readElementText().toInt();
    lxml.readNextStartElement();
    d = lxml.readElementText().toInt();
    lxml.readNext();
    return Data(y,m,d);
}

Persona GestoreFile::letturaAtleta() {
    std::string nome, cognome;
    bool sesso;
    lxml.readNextStartElement();
    nome = lxml.readElementText().toStdString();
    lxml.readNextStartElement();
    cognome = lxml.readElementText().toStdString();
    lxml.readNextStartElement();
    sesso = lxml.readElementText() == "true" ? true : false;
    lxml.readNext();
    return Persona(nome, cognome, sesso);
}

void GestoreFile::scritturaFileAtleti() {
    QFile file("atleti.xml");
    if (file.open(QIODevice::WriteOnly)) {
        sxml.setDevice(&file);
        sxml.setAutoFormatting(true);
        sxml.writeStartDocument();

        sxml.writeStartElement("atleti");
        Contenitore<std::shared_ptr<Persona>>::iterator it = atl.begin();
        for (;it != atl.end(); ++it) {
            scritturaAtleta(QString::fromStdString((*it)->getNome()),
                            QString::fromStdString((*it)->getCognome()),
                            QString((*it)->getSessoStr() == "Uomo" ? "false" : "true"));
        }
        sxml.writeEndElement(); // atleti

        sxml.writeEndDocument();
    }
    file.close();
}

void GestoreFile::scritturaFileAllenamenti() {
    QFile file("allenamenti.xml");
    if (file.open(QIODevice::WriteOnly)) {
        sxml.setDevice(&file);
        sxml.setAutoFormatting(true);
        sxml.writeStartDocument();

        sxml.writeStartElement("allenamenti");
        Contenitore<DeepPtr<Allenamento>>::iterator it = all.begin();
        for (;it != all.end(); ++it) {
            std::string tipo = (*it)->tipo();
            if(tipo == "Nuoto") {
                sxml.writeStartElement("nuoto");
                scritturaNuoto((*it).get());
                sxml.writeEndElement();
            } else if(tipo == "Ciclismo") {
                sxml.writeStartElement("ciclismo");
                scritturaCiclismo((*it).get());
                sxml.writeEndElement();
            } else if(tipo == "Corsa") {
                sxml.writeStartElement("corsa");
                scritturaCorsa((*it).get());
                sxml.writeEndElement();
            } else if (tipo == "Triathlon") {
                sxml.writeStartElement("triathlon");
                scritturaTriathlon((*it).get());
                sxml.writeEndElement();
            }
        }
        sxml.writeEndElement(); // allenamenti

        sxml.writeEndDocument();
    }
    file.close();
}

bool GestoreFile::filePresente(QString file) const {
    QFile fileDaAprire(file);
    if (fileDaAprire.open(QIODevice::ReadOnly | QIODevice::Text)) {
        fileDaAprire.close();
        return true;
    }
    return false;

}

void GestoreFile::scritturaData(int y, int m, int d) {
    sxml.writeStartElement("data");
    sxml.writeTextElement("y", QString::fromStdString(std::to_string(y)));
    sxml.writeTextElement("m", QString::fromStdString(std::to_string((m))));
    sxml.writeTextElement("d", QString::fromStdString(std::to_string((d))));
    sxml.writeEndElement();
}

void GestoreFile::scritturaAttributiNuoto(int stile, int rana, int dorso) {
    sxml.writeTextElement("stile", QString::fromStdString(std::to_string((stile))));
    sxml.writeTextElement("rana", QString::fromStdString(std::to_string((rana))));
    sxml.writeTextElement("dorso", QString::fromStdString(std::to_string((dorso))));
}

void GestoreFile::scritturaAttributiCiclismo(int salita, int pianura, int discesa) {
    sxml.writeTextElement("salita", QString::fromStdString(std::to_string((salita))));
    sxml.writeTextElement("pianura", QString::fromStdString(std::to_string((pianura))));
    sxml.writeTextElement("discesa", QString::fromStdString(std::to_string((discesa))));
}

void GestoreFile::scritturaAttributiCorsa(int sterrato, int strada) {
    sxml.writeTextElement("sterrato", QString::fromStdString(std::to_string((sterrato))));
    sxml.writeTextElement("strada", QString::fromStdString(std::to_string((strada))));
}

void GestoreFile::scritturaAtleta(QString nome, QString cognome, QString sesso) {
    sxml.writeStartElement("atleta");
    sxml.writeTextElement("nome", nome);
    sxml.writeTextElement("cognome", cognome);
    sxml.writeTextElement("sesso", sesso);
    sxml.writeEndElement();
}

void GestoreFile::scritturaNuoto(Allenamento* a) {
    scritturaAtleta(QString::fromStdString(a->getAtleta().getNome()),
                    QString::fromStdString(a->getAtleta().getCognome()),
                    QString(a->getAtleta().getSessoStr() == "Uomo" ? "false" : "true"));
    sxml.writeTextElement("durata",
                          QString::fromStdString(std::to_string((a->getDurata()))));
    scritturaData(a->getData().getY(),
                  a->getData().getM(),
                  a->getData().getD());
    sxml.writeTextElement("magnesio",
                          QString::fromStdString(std::to_string((a->getMgMagnesioAssunti()))));
    Nuoto* n = dynamic_cast<Nuoto*>(a);
    scritturaAttributiNuoto(static_cast<int>(n->getVascheStileLibero()),
                            static_cast<int>(n->getVascheRana()),
                            static_cast<int>(n->getVascheDorso()));
}

void GestoreFile::scritturaCiclismo(Allenamento* a) {
    scritturaAtleta(QString::fromStdString(a->getAtleta().getNome()),
                    QString::fromStdString(a->getAtleta().getCognome()),
                    QString(a->getAtleta().getSessoStr() == "Uomo" ? "false" : "true"));
    sxml.writeTextElement("durata",
                          QString::fromStdString(std::to_string((a->getDurata()))));
    scritturaData(a->getData().getY(),
                  a->getData().getM(),
                  a->getData().getD());
    sxml.writeTextElement("magnesio",
                          QString::fromStdString(std::to_string((a->getMgMagnesioAssunti()))));
    Ciclismo* c = dynamic_cast<Ciclismo*>(a);
    scritturaAttributiCiclismo(static_cast<int>(c->getKmSalita()),
                               static_cast<int>(c->getKmPianura()),
                               static_cast<int>(c->getKmDiscesa()));
}

void GestoreFile::scritturaCorsa(Allenamento* a) {
    scritturaAtleta(QString::fromStdString(a->getAtleta().getNome()),
                    QString::fromStdString(a->getAtleta().getCognome()),
                    QString(a->getAtleta().getSessoStr() == "Uomo" ? "false" : "true"));
    sxml.writeTextElement("durata",
                          QString::fromStdString(std::to_string((a->getDurata()))));
    scritturaData(a->getData().getY(),
                  a->getData().getM(),
                  a->getData().getD());
    sxml.writeTextElement("magnesio",
                          QString::fromStdString(std::to_string((a->getMgMagnesioAssunti()))));
    Corsa* c = dynamic_cast<Corsa*>(a);
    scritturaAttributiCorsa(static_cast<int>(c->getKmSterrato()),
                            static_cast<int>(c->getKmStrada()));
}

void GestoreFile::scritturaTriathlon(Allenamento* a) {
    scritturaAtleta(QString::fromStdString(a->getAtleta().getNome()),
                    QString::fromStdString(a->getAtleta().getCognome()),
                    QString(a->getAtleta().getSessoStr() == "Uomo" ? "false" : "true"));
    sxml.writeTextElement("durata",
                          QString::fromStdString(std::to_string((a->getDurata()))));
    scritturaData(a->getData().getY(),
                  a->getData().getM(),
                  a->getData().getD());
    sxml.writeTextElement("magnesio",
                          QString::fromStdString(std::to_string((a->getMgMagnesioAssunti()))));
    Nuoto* n = dynamic_cast<Nuoto*>(a);
    scritturaAttributiNuoto(static_cast<int>(n->getVascheStileLibero()),
                            static_cast<int>(n->getVascheRana()),
                            static_cast<int>(n->getVascheDorso()));
    Corsa* cr = dynamic_cast<Corsa*>(a);
    scritturaAttributiCorsa(static_cast<int>(cr->getKmSterrato()),
                            static_cast<int>(cr->getKmStrada()));
    Ciclismo* c = dynamic_cast<Ciclismo*>(a);
    scritturaAttributiCiclismo(static_cast<int>(c->getKmSalita()),
                               static_cast<int>(c->getKmPianura()),
                               static_cast<int>(c->getKmDiscesa()));
}

void GestoreFile::viasualizzaDialogErrore() const {
    QMessageBox mes;
    mes.setIcon(QMessageBox::Information);
    mes.setText("Errore!");
    mes.setInformativeText("Impossibile reperire le informazioni dell'applicazione");
    mes.setStandardButtons(QMessageBox::Ok);
    mes.exec();
}
