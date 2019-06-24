#include "dialogcorsa.h"
#include "corsa.h"
#include "deepptr.h"

DialogCorsa::DialogCorsa(Contenitore<std::shared_ptr<Persona>>& cp_,
                         Contenitore<DeepPtr<Allenamento>>& ca_,
                         bool modifica,
                         int rigaMod,
                         QWidget* parent)
    : DialogAllenamento(cp_,ca_,modifica, rigaMod,parent)
{
    wCorsa = new WidgetCorsa();
    layoutPrincipale->addWidget(wCorsa);
    aggiungiBottoni();

    setWindowTitle("CORSA");

    connect(bReset, SIGNAL(clicked()), wCorsa, SLOT(reset()));
    connect(bReset, SIGNAL(clicked()), this, SLOT(reset()));
    if(!modifica)
        connect(bConferma, SIGNAL(clicked()), this, SLOT(inserimentoAllenamento()));
    else {
        compilazioneFormModifica();
    }
}

void DialogCorsa::setLabelTitolo() {
    if(modifica)
        lblTitolo->setText("NUOVO ALLENAMENTO CORSA");
    else
        lblTitolo->setText("MODIFICA ALLENAMENTO CORSA");
}

void DialogCorsa::compilazioneFormModifica() {
    Corsa* a = dynamic_cast<Corsa*>(ca.At(rigaMod).get());
    if(!a)
        return;

    wCorsa->setKmStrada(static_cast<int>(a->getKmStrada()));
    wCorsa->setKmSterrato(static_cast<int>(a->getKmSterrato()));
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

    std::string strData = deData->date().toString("dd/MM/yyyy").toStdString();
    Allenamento* al = new Corsa(cp.At(cmbAtleti->currentIndex()),
                                static_cast<unsigned int>(spinDurata->value()),
                                Data(strData),
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
