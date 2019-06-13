#include "dialogciclismo.h"

DialogCiclismo::DialogCiclismo(Contenitore<std::shared_ptr<Persona>>& cp_,
                               Contenitore<DeepPtr<Allenamento>>& ca_,
                               QWidget* parent)
    : DialogAllenamento(cp_,ca_,parent)
{
    wCiclismo = new WidgetCiclismo();
    layoutPrincipale->addWidget(wCiclismo);
    aggiungiBottoni();

    connect(bReset, SIGNAL(clicked()), wCiclismo, SLOT(reset()));
    connect(bReset, SIGNAL(clicked()), this, SLOT(reset()));
}

void DialogCiclismo::setLabelTitolo() {
    lblTitolo->setText("ALLENAMENTO CICLISMO");
}
