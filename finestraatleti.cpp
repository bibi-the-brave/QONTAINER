#include "finestraatleti.h"

#include <QStringList>
#include <QStandardItemModel>
#include "dialoginserimentoatleta.h"
#include "modeltabellaatleti.h"

FinestraAtleti::FinestraAtleti(Contenitore<std::shared_ptr<Persona*>>& a, QWidget *parent)
                               : QWidget(parent), cp(a)
{
    QStringList header;
    header << "Nome" << "Cognome" << "Elimina";

    //tabAtleti.setHorizontalHeader(header);
    lblTitolo.setText("ATLETI");
    btnNuovoAtleta.setText("Nuovo Atleta");

    layout.addWidget(&lblTitolo);
    layout.setAlignment(&lblTitolo, Qt::AlignHCenter);
    layout.addWidget(&tabAtleti);
    layout.addWidget(&btnNuovoAtleta);
    layout.setAlignment(&btnNuovoAtleta, Qt::AlignHCenter);

    setLayout(&layout);

    connect(&btnNuovoAtleta, SIGNAL(clicked(bool)), this, SLOT(avviaDialogInserimento(bool)));

    /*QStandardItemModel modello(this);
    modello.setHeaderData(0, Qt::Horizontal, QObject::tr("Nome"));
    modello.setHeaderData(1, Qt::Horizontal, QObject::tr("Cognome"));
    modello.setHeaderData(2, Qt::Horizontal, QObject::tr("Sesso"));*/
#include "contenitore.h"
#include "persona.h"

    ModelTabellaAtleti modello(cp,this);

    tabAtleti.setModel(&modello);

}


void FinestraAtleti::avviaDialogInserimento(bool cliccato) {
    DialogInserimentoAtleta da;
    da.exec();
}
