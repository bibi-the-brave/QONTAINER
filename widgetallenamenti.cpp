#include "widgetallenamenti.h"

#include <QStringList>
#include <QStandardItemModel>
#include <QtGlobal>
#include <QHeaderView>
#include <QMessageBox>

WidgetAllenamenti::WidgetAllenamenti(Contenitore<DeepPtr<Allenamento*>>& ca_, QWidget* parent)
    : QWidget(parent), ca(ca_)
{
    lblTitolo = new QLabel("ALLENAMENTI");
    btnNuovoAtleta = new QPushButton("Nuovo Allenamento");

    layout = new QVBoxLayout;
    layout->addWidget(lblTitolo);
    layout->setAlignment(lblTitolo, Qt::AlignHCenter);
    tabAtleti = new QTableView;
    layout->addWidget(tabAtleti);
    layout->addWidget(btnNuovoAtleta);
    layout->setAlignment(btnNuovoAtleta, Qt::AlignHCenter);

    setLayout(layout);


    modello = new ModelTabellaAllenamenti(ca);
    tabAtleti->setModel(modello);
    delegato = new DelegateEliminazione();
    tabAtleti->setItemDelegateForColumn(3, delegato);
    // "stira" le colonne per occupare tutta la larghezza della tabella
    tabAtleti->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    setWindowModality(Qt::ApplicationModal); //le altre finestre non sono usabili
/*
    connect(btnNuovoAtleta, SIGNAL(clicked(bool)), this, SLOT(avviaDialogInserimento(bool)));
    // il delegate avverte che l'utente ha cliccato un bottone e vuole eliminare una riga
    connect(delegato, SIGNAL(avvisoEliminazione(int)), this, SLOT(ricevutaNotificaEliminazioneRiga(int)));
    // se l'utente conferma l'eliminazione viene avertito il delegate
    connect(this, SIGNAL(rimuovereRiga(int)), delegato, SLOT(slotEliminazione(int)));
    // il delegate avverte il model di rimuovere la riga desiderata
    connect(delegato, SIGNAL(eliminaRiga(int)), modello, SLOT(eliminazioneAtleta(int)));*/
}
