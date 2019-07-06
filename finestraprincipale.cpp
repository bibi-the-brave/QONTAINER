#include "finestraprincipale.h"
#include <QtGlobal>
#include <QDesktopWidget>
#include "widgetintroduttivo.h"
#include "widgetnuovosport.h"
#include "widgetatleti.h"
#include "widgetallenamenti.h"
#include "widgetricerca.h"
#include "caricatorecontenitori.h"

FinestraPrincipale::FinestraPrincipale(Contenitore<DeepPtr<Allenamento>>& a,
                                       Contenitore<std::shared_ptr<Persona>>& p,
                                       QWidget *parent)
    : QMainWindow(parent), ca(a), cp(p)
{
    tabFunzionalita = new QTabWidget();

    CaricatoreContenitori caricatore(cp,ca);
    caricatore.leggiFile(); // carica cp e ca con gli atleti e gli allenamenti salvati su file

    wi = new WidgetIntroduttivo();
    tabFunzionalita->addTab(wi, "Introduzione");

    fa = new WidgetAtleti(cp);
    tabFunzionalita->addTab(fa, "Atleti");

    wa = new WidgetAllenamenti(cp, ca);
    tabFunzionalita->addTab(wa, "Allenamenti");

    wr = new WidgetRicerca(cp, ca, wa);
    tabFunzionalita->addTab(wr, "Ricerca");
    setCentralWidget(tabFunzionalita);

    setWindowTitle("QONTAINER ALLENAMENTI");

    // largezza iniziale finestra 90% schermo
    resize(QDesktopWidget().availableGeometry(this).size() * 0.9);

    // permette di eliminare a cascata gli allenamenti di un atleta che viene cancellato
    connect(fa->getModello(), SIGNAL(atletaDaEliminare(std::shared_ptr<Persona>)),
            wa->getModello(), SLOT(eliminazioneAllenamenti(std::shared_ptr<Persona>)));

    //eliminazione di una riga visualizzata dal proxy
    connect(wa->getDelEl(), SIGNAL(eliminaRiga(int)), wr, SLOT(rimozioneRigaEliminataModel(int)));

    // segnali e slot relativi alla selezione della tab con i bottoni
    //del widget introduttivo
    connect(wi->getBtnAtleti(), SIGNAL(clicked()), this, SLOT(impostaTab()));
    connect(wi->getBtnAllenamenti(), SIGNAL(clicked()), this, SLOT(impostaTab()));
    connect(wi->getBtnRicerca(), SIGNAL(clicked()), this, SLOT(impostaTab()));
}

FinestraPrincipale::~FinestraPrincipale() {
    CaricatoreContenitori salvataggio(cp,ca);
    salvataggio.scritturaFileAtleti();
    salvataggio.scritturaFileAllenamenti();
}

void FinestraPrincipale::impostaTab() {
    QObject *sender = QObject::sender();
    if(sender == wi->getBtnAtleti()) {
        tabFunzionalita->setCurrentIndex(1);
    } else if(sender == wi->getBtnAllenamenti()) {
        tabFunzionalita->setCurrentIndex(2);
    } else if (sender == wi->getBtnRicerca()) {
        tabFunzionalita->setCurrentIndex(3);
    }
}
