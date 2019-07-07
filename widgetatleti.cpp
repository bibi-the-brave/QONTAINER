#include "widgetatleti.h"

#include <QStringList>
#include <QStandardItemModel>
#include <QtGlobal>
#include <QHeaderView>
#include <QMessageBox>

#include "dialogatleta.h"

WidgetAtleti::WidgetAtleti(Contenitore<std::shared_ptr<Persona>>& a, QWidget *parent)
                               : QWidget(parent), atleti(a)
{
    lblTitolo = new QLabel("ATLETI");
    btnNuovoAtleta = new QPushButton("Nuovo Atleta");

    layout = new QVBoxLayout;

    layout->addWidget(lblTitolo);
    layout->setAlignment(lblTitolo, Qt::AlignHCenter);
    tabAtleti = new QTableView;
    layout->addWidget(tabAtleti);
    layout->addWidget(btnNuovoAtleta);
    layout->setAlignment(btnNuovoAtleta, Qt::AlignHCenter);

    setLayout(layout);

    modello = new ModelTabellaAtleti(atleti);
    tabAtleti->setModel(modello);
    delegatoEl = new DelegateEliminazione;
    tabAtleti->setItemDelegateForColumn(3,delegatoEl);
    delegatoMod = new DelegateModifica;
    tabAtleti->setItemDelegateForColumn(4,delegatoMod);
    // "stira" le colonne per occupare tutta la larghezza della tabella
    tabAtleti->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    //setWindowModality(Qt::ApplicationModal); //le altre finestre non sono usabili

    // creazione di un nuovo atleta
    connect(btnNuovoAtleta, SIGNAL(clicked(bool)), this, SLOT(avviaDialogInserimento(bool)));

    // 'Eventi' relativi all'eleliminazione di un atleta
    // il delegate avverte che l'utente ha cliccato un bottone e vuole eliminare una riga
    connect(delegatoEl, SIGNAL(avvisoEliminazione(int)), this, SLOT(ricevutaNotificaEliminazioneRiga(int)));
    // se l'utente conferma l'eliminazione viene avertito il delegate
    connect(this, SIGNAL(rimuovereRiga(int)), delegatoEl, SLOT(slotEliminazione(int)));
    // il delegate avverte il model di rimuovere la riga desiderata
    connect(delegatoEl, SIGNAL(eliminaRiga(int)), modello, SLOT(eliminazioneAtleta(int)));

    // 'Eventi' relativi alla modifica di un atleta
    connect(delegatoMod, SIGNAL(avvisoModifica(int)), this, SLOT(avviaDialogModifica(int)));
}

ModelTabellaAtleti* WidgetAtleti::getModello() const {
    return modello;
}

DelegateEliminazione* WidgetAtleti::getDelegatoEl() const {
    return delegatoEl;
}

void WidgetAtleti::avviaDialogInserimento(bool cliccato) {
    Q_UNUSED(cliccato);
    DialogAtleta da(atleti);
    connect(&da, SIGNAL(reset()), modello, SLOT(inserimentoNuovoAtletaEsterno()));
    da.exec();
    da.disconnect();
}

void WidgetAtleti::ricevutaNotificaEliminazioneRiga(int riga) {
    QMessageBox boxConfermaEliminazione;
    boxConfermaEliminazione.setIcon(QMessageBox::Question);
    boxConfermaEliminazione.setText("ATTENZIONE:");
    boxConfermaEliminazione.setInformativeText(
                QString("Vuoi davvero eliminare l'atleta?") +
                " L'operazione è definitiva e verranno eliminati "
                + "tutti gli allenamenti associati a tale atleta.");
    boxConfermaEliminazione.addButton("No", QMessageBox::NoRole);
    boxConfermaEliminazione.addButton("Sì", QMessageBox::YesRole);
    int scelta = boxConfermaEliminazione.exec();
    if(scelta)
        emit rimuovereRiga(riga);
}

void WidgetAtleti::avviaDialogModifica(int atl) {
    DialogAtleta da(atleti,true, atl);
    connect(&da, SIGNAL(reset()), modello, SLOT(inserimentoNuovoAtletaEsterno()));
    da.exec();
    da.disconnect();
}
