#include "dialogtriathlon.h"

DialogTriathlon::DialogTriathlon(Contenitore<std::shared_ptr<Persona>>& cp_,
                                 Contenitore<DeepPtr<Allenamento>>& ca_,
                                 QWidget* parent)
    : DialogAllenamento(cp_,ca_,parent)
{

    wNuoto = new WidgetNuoto();
    layoutPrincipale->addWidget(wNuoto);
    wCorsa = new WidgetCorsa();
    layoutPrincipale->addWidget(wCorsa);
    wCiclismo = new WidgetCiclismo();
    layoutPrincipale->addWidget(wCiclismo);
    aggiungiBottoni();

    connect(bReset, SIGNAL(clicked()), wNuoto, SLOT(reset()));
    connect(bReset, SIGNAL(clicked()), wCorsa, SLOT(reset()));
    connect(bReset, SIGNAL(clicked()), wCiclismo, SLOT(reset()));
    connect(bReset, SIGNAL(clicked()), this, SLOT(reset()));
}

void DialogTriathlon::setLabelTitolo() {
    lblTitolo->setText("ALLENAMENTO TRIATHLON");
}
