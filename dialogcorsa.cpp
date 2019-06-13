#include "dialogcorsa.h"
#include "corsa.h"
#include "deepptr.h"

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
    connect(bConferma, SIGNAL(clicked()), this, SLOT(inserimentoAllenamento()));
}

void DialogCorsa::setLabelTitolo() {
    lblTitolo->setText("ALLENAMENTO CORSO");
}

void DialogCorsa::inserimentoAllenamento() {
    bool erroriCompilazione;
    controlloForm(erroriCompilazione);
    if(erroriCompilazione) {
        dialogErroreForm();
        return;
    }

    wCorsa->controlloForm(erroriCompilazione);
    if(erroriCompilazione) {
        wCorsa->dialogErroreForm();
        return;
    }

    Allenamento* al = new Corsa(cp.At(cmbAtleti->currentIndex()),
                                static_cast<unsigned int>(spinDurata->value()),
                                spinMagnesio->value(),
                                static_cast<unsigned int>(wCorsa->kmSterrato()),
                                static_cast<unsigned int>(wCorsa->kmStrada()));

    if(ca.elementoPresente(al)) {
        dialogErroreDoppione();
        return;
    }
    ca.pushBack(DeepPtr<Allenamento>(al));
    emit aggiungereAllenamento();
    delete al; //DeepPtr costruisce di copia i suoi elementi
    close();
}
