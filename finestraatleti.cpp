#include "finestraatleti.h"

#include <QStringList>
#include <QStandardItemModel>
#include <QtGlobal>
#include <QHeaderView>
#include <QMessageBox>

#include "dialoginserimentoatleta.h"

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
    tabAtleti.setItemDelegateForColumn(3,&delegato);
    // "stira" le colonne per occupare tutta la larghezza della tabella
    tabAtleti.horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    setWindowModality(Qt::ApplicationModal); //le altre finestre non sono usabili

    connect(&btnNuovoAtleta, SIGNAL(clicked(bool)), this, SLOT(avviaDialogInserimento(bool)));
    // il delegate avverte che l'utente ha cliccato un bottone e vuole eliminare una riga
    connect(&delegato, SIGNAL(avvisoEliminazione(int)), this, SLOT(ricevutaNotificaEliminazioneRiga(int)));
    // se l'utente conferma l'eliminazione viene avertito il delegate
    connect(this, SIGNAL(rimuovereRiga(int)), &delegato, SLOT(slotEliminazione(int)));
    // il delegate avverte il model di rimuovere la riga desiderata
    connect(&delegato, SIGNAL(eliminaRiga(int)), &modello, SLOT(eliminazioneAtleta(int)));
}

void FinestraAtleti::avviaDialogInserimento(bool cliccato) {
    Q_UNUSED(cliccato);
    DialogInserimentoAtleta da(atleti);
    connect(&da, SIGNAL(reset()), &modello, SLOT(inserimentoNuovoAtletaEsterno()));
    da.exec();
    da.disconnect();
}

void FinestraAtleti::ricevutaNotificaEliminazioneRiga(int riga) {
    QMessageBox boxConfermaEliminazione;
    boxConfermaEliminazione.setIcon(QMessageBox::Question);
    boxConfermaEliminazione.setText("ATTENZIONE:");
    boxConfermaEliminazione.setInformativeText("Vuoi davvero eliminare l'atleta? L'operazione è definitiva");
    boxConfermaEliminazione.addButton("No", QMessageBox::NoRole);
    boxConfermaEliminazione.addButton("Sì", QMessageBox::YesRole);
    int scelta = boxConfermaEliminazione.exec();
    if(scelta)
        emit rimuovereRiga(riga);
}
