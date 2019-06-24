#include "caricatorecontenitori.h"
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QString>
#include <QJsonArray>
#include "contenitore.h"
#include <memory>
#include "persona.h"
#include "allenamento.h"
#include "nuoto.h"
#include "ciclismo.h"
#include "corsa.h"
#include "triathlon.h"
#include "deepptr.h"
#include <QDebug>
CaricatoreContenitori::CaricatoreContenitori(Contenitore<std::shared_ptr<Persona>>& atl_,
                                             Contenitore<DeepPtr<Allenamento>>& all_)
    : atl(atl_), all(all_) {}

void CaricatoreContenitori::leggiFile() {
    QFile fAtleti(":/file/atleti.json");
    QFile fAllenamenti(":/file/allenamenti.json");
    qDebug() << "Sto per leggere gli atleti";
    // LETTURA ATLETI
    ///////////////////////////////////////////////////////////////
    if(fAtleti.open(QIODevice::ReadOnly)) {qDebug() << "yooooo";
        QJsonDocument docjson;
        docjson.fromJson(fAtleti.readAll());
        QJsonObject json = docjson.object();

        QJsonArray valori = json["atleta"].toArray();
        foreach(const QJsonValue& v , valori) {qDebug() << "ehi, sexy ladyy";
            QJsonObject valore = v.toObject();

            //VALORI DELL'ATLETA
            QJsonObject atleta = valore["atleta"].toObject();
            QString nome = atleta["nome"].toString();
            QString cognome = atleta["cognome"].toString();
            bool sesso = atleta["sesso"].toBool();

            auto sp = std::make_shared<Persona>(nome.toStdString(), cognome.toStdString(), sesso);
            if( !atl.elementoPresente(sp) )
                atl.pushBack(sp);
        }

        fAtleti.close();
    }
    ////////////////////////////////////////////////////////////////////
    // Lettura allenamenti
    ////////////////////////////////////////////////////////////////////
    if(fAllenamenti.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QJsonDocument docjson;
        docjson.fromJson(fAllenamenti.readAll());
        QJsonObject json = docjson.object();

        /////////////////////////////////////////////////
        // Nuoto
        /////////////////////////////////////////////////
        QJsonArray valori = json.value("nuoto").toArray();
        foreach(const QJsonValue& v , valori){
            QJsonObject valore = v.toObject();

            //VALORI DELL'ATLETA
            QJsonObject atleta = valore["atleta"].toObject();
            QString nome = atleta["nome"].toString();
            QString cognome= atleta["cognome"].toString();
            bool sesso= atleta["sesso"].toBool();

            int durata = valore["durata"].toInt();

            //valori data
            QJsonObject data = valore["data"].toObject();
            int d=  data ["d"].toInt();
            int m =  data["m"].toInt();
            int y=  data["y"].toInt();

            int magnesio = valore["magnesio"].toInt();

            // valori relativi al #vasche
            int stile = valore["stile"].toInt();
            int rana = valore["rana"].toInt();
            int dorso = valore["dorso"].toInt();

            auto sp = std::make_shared<Persona>(nome.toStdString(), cognome.toStdString(), sesso);
            Contenitore<std::shared_ptr<Persona>>::iterator it = atl.begin();
            std::shared_ptr<Persona> p;
            for(bool trovato = false; it != atl.end() && !trovato; ++it) {
                if(*(it->get()) == *sp.get()) {
                    trovato = true;
                    p = *it;
                }
            }
            Allenamento* al = new Nuoto(p,
                                        static_cast<unsigned int>(durata),
                                        Data(y,m,d),
                                        static_cast<unsigned int>(magnesio),
                                        static_cast<unsigned int>(stile),
                                        static_cast<unsigned int>(rana),
                                        static_cast<unsigned int>(dorso));
            if( !all.elementoPresente(al) ) {
                all.pushBack(al);
                delete al; //perché all fa la copia profonda
            }

        }

        /////////////////////////////////////////////////
        // Ciclismo
        /////////////////////////////////////////////////
        valori = json.value("nuoto").toArray();
        foreach(const QJsonValue& v , valori){
            QJsonObject valore = v.toObject();

            //VALORI DELL'ATLETA
            QJsonObject atleta = valore["atleta"].toObject();
            QString nome = atleta["nome"].toString();
            QString cognome= atleta["cognome"].toString();
            bool sesso= atleta["sesso"].toBool();

            int durata = valore["durata"].toInt();

            //valori data
            QJsonObject data = valore["data"].toObject();
            int d=  data ["d"].toInt();
            int m =  data["m"].toInt();
            int y=  data["y"].toInt();

            int magnesio = valore["magnesio"].toInt();

            // valori relativi alla pedalata
            int salita = valore["salita"].toInt();
            int discesa = valore["discesa"].toInt();
            int pianura = valore["pianura"].toInt();

            auto sp = std::make_shared<Persona>(nome.toStdString(), cognome.toStdString(), sesso);
            Contenitore<std::shared_ptr<Persona>>::iterator it = atl.begin();
            std::shared_ptr<Persona> p;
            for(bool trovato = false; it != atl.end() && !trovato; ++it) {
                if(*(it->get()) == *sp.get()) {
                    trovato = true;
                    p = *it;
                }
            }
            Allenamento* al = new Ciclismo(p,
                                        static_cast<unsigned int>(durata),
                                        Data(y,m,d),
                                        static_cast<unsigned int>(magnesio),
                                        static_cast<unsigned int>(pianura),
                                        static_cast<unsigned int>(salita),
                                        static_cast<unsigned int>(discesa));
            if( !all.elementoPresente(al) ) {
                all.pushBack(al);
                delete al; //perché all fa la copia profonda
            }

        }

        /////////////////////////////////////////////////
        // Corsa
        /////////////////////////////////////////////////
        valori = json.value("nuoto").toArray();
        foreach(const QJsonValue& v , valori){
            QJsonObject valore = v.toObject();

            //VALORI DELL'ATLETA
            QJsonObject atleta = valore["atleta"].toObject();
            QString nome = atleta["nome"].toString();
            QString cognome= atleta["cognome"].toString();
            bool sesso= atleta["sesso"].toBool();

            int durata = valore["durata"].toInt();

            //valori data
            QJsonObject data = valore["data"].toObject();
            int d=  data ["d"].toInt();
            int m =  data["m"].toInt();
            int y=  data["y"].toInt();

            int magnesio = valore["magnesio"].toInt();

            // valori relativi alla corsa
            int sterrato = valore["sterrato"].toInt();
            int strada = valore["strada"].toInt();

            auto sp = std::make_shared<Persona>(nome.toStdString(), cognome.toStdString(), sesso);
            Contenitore<std::shared_ptr<Persona>>::iterator it = atl.begin();
            std::shared_ptr<Persona> p;
            for(bool trovato = false; it != atl.end() && !trovato; ++it) {
                if(*(it->get()) == *sp.get()) {
                    trovato = true;
                    p = *it;
                }
            }
            Allenamento* al = new Corsa(p,
                                        static_cast<unsigned int>(durata),
                                        Data(y,m,d),
                                        static_cast<unsigned int>(magnesio),
                                        static_cast<unsigned int>(sterrato),
                                        static_cast<unsigned int>(strada));
            if( !all.elementoPresente(al) ) {
                all.pushBack(al);
                delete al; //perché all fa la copia profonda
            }

        }

        /////////////////////////////////////////////////
        // Triathlon
        /////////////////////////////////////////////////
        valori = json.value("nuoto").toArray();
        foreach(const QJsonValue& v , valori){
            QJsonObject valore = v.toObject();

            //VALORI DELL'ATLETA
            QJsonObject atleta = valore["atleta"].toObject();
            QString nome = atleta["nome"].toString();
            QString cognome= atleta["cognome"].toString();
            bool sesso= atleta["sesso"].toBool();

            int durata = valore["durata"].toInt();

            //valori data
            QJsonObject data = valore["data"].toObject();
            int d=  data ["d"].toInt();
            int m =  data["m"].toInt();
            int y=  data["y"].toInt();

            int magnesio = valore["magnesio"].toInt();

            // valori relativi al #vasche
            int stile = valore["stile"].toInt();
            int rana = valore["rana"].toInt();
            int dorso = valore["dorso"].toInt();

            // valori relativi alla pedalata
            int salita = valore["salita"].toInt();
            int discesa = valore["discesa"].toInt();
            int pianura = valore["pianura"].toInt();

            // valori relativi alla corsa
            int sterrato = valore["sterrato"].toInt();
            int strada = valore["strada"].toInt();

            auto sp = std::make_shared<Persona>(nome.toStdString(), cognome.toStdString(), sesso);
            Contenitore<std::shared_ptr<Persona>>::iterator it = atl.begin();
            std::shared_ptr<Persona> p;
            for(bool trovato = false; it != atl.end() && !trovato; ++it) {
                if(*(it->get()) == *sp.get()) {
                    trovato = true;
                    p = *it;
                }
            }
            Allenamento* al = new Triathlon(p,
                                        static_cast<unsigned int>(durata),
                                        Data(y,m,d),
                                        static_cast<unsigned int>(magnesio),
                                        static_cast<unsigned int>(stile),
                                        static_cast<unsigned int>(rana),
                                        static_cast<unsigned int>(dorso),
                                        static_cast<unsigned int>(sterrato),
                                        static_cast<unsigned int>(strada),
                                        static_cast<unsigned int>(salita),
                                        static_cast<unsigned int>(pianura),
                                        static_cast<unsigned int>(discesa));
            if( !all.elementoPresente(al) ) {
                all.pushBack(al);
                delete al; //perché all fa la copia profonda
            }

        }

        fAllenamenti.close();
    }


}

void CaricatoreContenitori::scriviFile() {

}
