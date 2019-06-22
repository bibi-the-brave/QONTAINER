#include "finestraprincipale.h"
#include <QtGlobal>
#include <QDesktopWidget>
#include "widgetnuovosport.h"
#include "widgetatleti.h"
#include "widgetallenamenti.h"
#include "widgetricerca.h"

FinestraPrincipale::FinestraPrincipale(Contenitore<DeepPtr<Allenamento>>& a,
                                       Contenitore<std::shared_ptr<Persona>>& p,
                                       QWidget *parent)
    : QMainWindow(parent), ca(a), cp(p)
{
    tabFunzionalita = new QTabWidget();

    fa = new WidgetAtleti(cp);
    tabFunzionalita->addTab(fa, "Atleti");

    wa = new WidgetAllenamenti(cp, ca);
    tabFunzionalita->addTab(wa, "Allenamenti");

    wr = new WidgetRicerca(ca);
    tabFunzionalita->addTab(wr, "Ricerca");
    setCentralWidget(tabFunzionalita);

    setWindowTitle("QONTAINER ALLENAMENTI");

    //largezza iniziale finestra 70% schermo
    resize(QDesktopWidget().availableGeometry(this).size() * 0.8);
}
