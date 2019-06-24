#include "widgetallenamenti.h"
#include "allenamento.h"
#include "nuoto.h"
#include "corsa.h"
#include "ciclismo.h"
#include "triathlon.h"
#include "dialogallenamento.h"
#include "dialognuoto.h"
#include "dialogciclismo.h"
#include "dialogcorsa.h"
#include "dialogtriathlon.h"

#include <QStringList>
#include <QStandardItemModel>
#include <QtGlobal>
#include <QHeaderView>
#include <QMessageBox>

WidgetAllenamenti::WidgetAllenamenti(Contenitore<std::shared_ptr<Persona>>& catleti_,
                                     Contenitore<DeepPtr<Allenamento>>& ca_, QWidget* parent)
    : QWidget(parent), ca(ca_), catleti(catleti_)
{
    lblTitolo = new QLabel("ALLENAMENTI");
    modello = new ModelTabellaAllenamenti(ca);
    widgetCreazione = new WidgetNuovoSport(catleti,ca, *modello);

    layout = new QVBoxLayout;
    layout->addWidget(lblTitolo);
    layout->setAlignment(lblTitolo, Qt::AlignHCenter);
    tabAllenamenti = new QTableView;
    layout->addWidget(tabAllenamenti);
    layout->addWidget(widgetCreazione);

    setLayout(layout);


    tabAllenamenti->setModel(modello);
    delegatoEl = new DelegateEliminazione();
    tabAllenamenti->setItemDelegateForColumn(8, delegatoEl);
    delegatoMod = new DelegateModifica();
    tabAllenamenti->setItemDelegateForColumn(9, delegatoMod);
    // "stira" le colonne per occupare tutta la larghezza della tabella
    tabAllenamenti->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    //setWindowModality(Qt::ApplicationModal); //le altre finestre non sono usabili

    //connect(btnNuovoAllenamento, SIGNAL(clicked(bool)), this, SLOT(avviaFinestraInserimentoAllen(bool)));
    // il delegate avverte che l'utente ha cliccato un bottone e vuole eliminare una riga
    connect(delegatoEl, SIGNAL(avvisoEliminazione(int)), this, SLOT(ricevutaNotificaEliminazioneRiga(int)));
    // se l'utente conferma l'eliminazione viene avertito il delegate
    connect(this, SIGNAL(rimuovereRiga(int)), delegatoEl, SLOT(slotEliminazione(int)));
    // il delegate avverte il model di rimuovere la riga desiderata
    connect(delegatoEl, SIGNAL(eliminaRiga(int)), modello, SLOT(eliminazioneAllenamento(int)));

    // 'Eventi' relativi alla modifica di un allenamento
    connect(delegatoMod, SIGNAL(avvisoModifica(int)), this, SLOT(avviaDialogModifica(int)));
}

ModelTabellaAllenamenti* WidgetAllenamenti::getModello() const {
    return modello;
}

void WidgetAllenamenti::ricevutaNotificaEliminazioneRiga(int riga) {
    QMessageBox boxConfermaEliminazione;
    boxConfermaEliminazione.setIcon(QMessageBox::Question);
    boxConfermaEliminazione.setText("ATTENZIONE:");
    boxConfermaEliminazione.setInformativeText("Vuoi davvero eliminare l'allenamento? L'operazione è definitiva");
    boxConfermaEliminazione.addButton("No", QMessageBox::NoRole);
    boxConfermaEliminazione.addButton("Sì", QMessageBox::YesRole);
    int scelta = boxConfermaEliminazione.exec();
    if(scelta)
        emit rimuovereRiga(riga);
}

void WidgetAllenamenti::avviaDialogModifica(int riga) {
    Allenamento* a = ca.At(riga).get();
    DialogAllenamento* da;

    if(dynamic_cast<Nuoto*>(a)) {
        da = new DialogNuoto(catleti, ca, true,riga);
    } else if(dynamic_cast<Ciclismo*>(a)) {
        da = new DialogCiclismo(catleti, ca, true,riga);
    } else if(dynamic_cast<Corsa*>(a)) {
        da = new DialogCorsa(catleti, ca, true,riga);
    } else if(dynamic_cast<Triathlon*>(a)) {
        da = new DialogTriathlon(catleti, ca, true,riga);
    } else {
        return;
    }

    da->exec();
    delete da;
    // nessuna delete su 'a' perché get ritorna un puntatore grezzo, non copia profonda
    // corrispondente a quello contenuto in DeepPtr<Allenamento>
}
