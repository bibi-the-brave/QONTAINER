#include "dialogciclismo.h"
#include "ciclismo.h"
#include "deepptr.h"

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
    connect(bConferma, SIGNAL(clicked()), this, SLOT(inserimentoAllenamento()));
}

void DialogCiclismo::setLabelTitolo() {
    lblTitolo->setText("ALLENAMENTO CICLISMO");
}

void DialogCiclismo::inserimentoAllenamento() {
    bool erroriCompilazione;
    controlloForm(erroriCompilazione);
    if(erroriCompilazione) {
        dialogErroreForm();
        return;
    }

    wCiclismo->controlloForm(erroriCompilazione);
    if(erroriCompilazione) {
        wCiclismo->dialogErroreForm();
        return;
    }

    Allenamento* al = new Ciclismo(cp.At(cmbAtleti->currentIndex()),
                                static_cast<unsigned int>(spinDurata->value()),
                                spinMagnesio->value(),
                                static_cast<unsigned int>(wCiclismo->kmPianura()),
                                static_cast<unsigned int>(wCiclismo->kmSalita()),
                                static_cast<unsigned int>(wCiclismo->kmDiscesa()));

    if(ca.elementoPresente(al)) {
        dialogErroreDoppione();
        return;
    }
    ca.pushBack(DeepPtr<Allenamento>(al));
    emit aggiungereAllenamento();
    delete al; //DeepPtr costruisce di copia i suoi elementi
    close();
}
