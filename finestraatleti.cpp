#include "finestraatleti.h"

#include <QStringList>
#include <QStandardItemModel>
#include <QtGlobal>

#include "dialoginserimentoatleta.h"
#include <QHeaderView>

FinestraAtleti::FinestraAtleti(Contenitore<std::shared_ptr<Persona>>& a, QWidget *parent)
                               : QWidget(parent), atleti(a), modello(atleti)
{
    lblTitolo.setText("ATLETI");
    btnNuovoAtleta.setText("Nuovo Atleta");

    layout.addWidget(&lblTitolo);
    layout.setAlignment(&lblTitolo, Qt::AlignHCenter);
    layout.addWidget(&tabAtleti);
    layout.addWidget(&btnNuovoAtleta);
    layout.setAlignment(&btnNuovoAtleta, Qt::AlignHCenter);

    setLayout(&layout);

    tabAtleti.setModel(&modello);
    // "stira" le colonne per occupare tutta la larghezza della tabella
    tabAtleti.horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    setWindowModality(Qt::ApplicationModal); //le altre finestre non sono usabili

    connect(&btnNuovoAtleta, SIGNAL(clicked(bool)), this, SLOT(avviaDialogInserimento(bool)));
}

void FinestraAtleti::avviaDialogInserimento(bool cliccato) {
    Q_UNUSED(cliccato);
    DialogInserimentoAtleta da(atleti);
    connect(&da, SIGNAL(reset()), &modello, SLOT(inserimentoNuovoAtletaEsterno()));
    da.exec();
}
