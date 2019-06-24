#include "caricatorecontenitori.h"
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QString>

CaricatoreContenitori::CaricatoreContenitori(Contenitore<std::shared_ptr<Persona>>& atl_,
                                             Contenitore<DeepPtr<Allenamento>>& all_)
    : atl(atl_), all(all_) {}

void CaricatoreContenitori::leggiFile() {
    QFile fAtleti(":/atleti.json");
    QFile fAllenamenti(":/allenamenti.json");
    //QString lettore;
    QJsonDocument doc;


    fAtleti.open(QIODevice::ReadOnly | QIODevice::Text);
    doc.fromJson(fAtleti.readAll());
    QJsonObject ob = doc.object();

    fAtleti.close();
}

void CaricatoreContenitori::scriviFile() {

}
