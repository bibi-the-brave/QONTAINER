#include "finestraprincipale.h"
#include <QtGlobal>
#include <QDesktopWidget>
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
}

FinestraPrincipale::~FinestraPrincipale() {
    CaricatoreContenitori salvataggio(cp,ca);
    salvataggio.scritturaFileAtleti();
    salvataggio.scritturaFileAllenamenti();
}
