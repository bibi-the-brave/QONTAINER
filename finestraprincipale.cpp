#include "finestraprincipale.h"
#include <QtGlobal>
#include <QDesktopWidget>
#include "finestrasceltasport.h"
#include "widgetatleti.h"
#include "widgetallenamenti.h"
#include "widgetricerca.h"

FinestraPrincipale::FinestraPrincipale(Contenitore<DeepPtr<Allenamento*>>& a,
                                       Contenitore<std::shared_ptr<Persona>>& p,
                                       QWidget *parent)
    : QMainWindow(parent), ca(a), cp(p)
{
    tabFunzionalita = new QTabWidget();

    fa = new WidgetAtleti(cp);
    tabFunzionalita->addTab(fa, "Atleti");

    wa = new WidgetAllenamenti(ca);
    tabFunzionalita->addTab(wa, "Allenamenti");

    wr = new WidgetRicerca(ca);
    tabFunzionalita->addTab(wr, "Ricerca");
    setCentralWidget(tabFunzionalita);

    //largezza iniziale finestra 60% schermo
    resize(QDesktopWidget().availableGeometry(this).size() * 0.6);
}
