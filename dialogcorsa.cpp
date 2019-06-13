#include "dialogcorsa.h"

DialogCorsa::DialogCorsa(Contenitore<std::shared_ptr<Persona>>& cp_,
                         Contenitore<DeepPtr<Allenamento>>& ca_,
                         QWidget* parent)
                     : DialogAllenamento(cp_,ca_,parent)
{
    wCorsa = new WidgetCorsa();
    layoutPrincipale->addWidget(wCorsa);
    aggiungiBottoni();

    connect(bReset, SIGNAL(clicked()), wCorsa, SLOT(reset()));
    connect(bReset, SIGNAL(clicked()), this, SLOT(reset()));
}

void DialogCorsa::setLabelTitolo() {
    lblTitolo->setText("ALLENAMENTO CORSO");
}

