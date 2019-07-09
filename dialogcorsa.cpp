/*
 * Andrea Favero
 * 1125545
 * andrea.favero.8@studenti.unipd.it
 */
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
    setLabelTitolo();

    layoutPrincipale->setSizeConstraint( QLayout::SetFixedSize );

    connect(bReset, SIGNAL(clicked()), wCorsa, SLOT(reset()));
    connect(bReset, SIGNAL(clicked()), this, SLOT(reset()));
    if(!modifica)
        connect(bConferma, SIGNAL(clicked()), this, SLOT(inserimentoAllenamento()));
    else {
        compilazioneFormModifica();
        connect(bConferma, SIGNAL(clicked()), this, SLOT(modificaAllenamento()));
    }
}

void DialogCorsa::setLabelTitolo() {
    if(!modifica)
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
                                static_cast<unsigned int>(spinMagnesio->value()),
                                static_cast<unsigned int>(wCorsa->kmSterrato()),
                                static_cast<unsigned int>(wCorsa->kmStrada()));

    if(ca.elementoPresente(al)) {
        dialogErroreDoppione();
        delete al;
        return;
    }
    ca.pushBack(DeepPtr<Allenamento>(al));
    emit aggiungereAllenamento();
    delete al; //DeepPtr costruisce di copia i suoi elementi
    close();
}

void DialogCorsa::modificaAllenamento() {
    Corsa* allenamentoSelezionato = dynamic_cast<Corsa*>(ca.At(rigaMod).get());
    if(!allenamentoSelezionato)
        return;

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
                                static_cast<unsigned int>(spinMagnesio->value()),
                                static_cast<unsigned int>(wCorsa->kmSterrato()),
                                static_cast<unsigned int>(wCorsa->kmStrada()));


    if(*allenamentoSelezionato == *al) {
        visualizzaMessaggioAllenamentoNonModificato();
        delete al;
        this->close();
        return; //lo metto perché è capitato che prima di eseguire close venga eseguita
        //la parte in cui si controlla doppione. Penso perché close possa essere multithread
    }


    if(ca.elementoPresente(al)) {
        dialogErroreDoppione();
        delete al;
        return;
    } else { //modifico l'atleta. Il model e la view si aggiornano in automatico
        allenamentoSelezionato->setData(al->getData());
        allenamentoSelezionato->setDurata(al->getDurata());
        allenamentoSelezionato->setMgMagnesio(al->getMgMagnesioAssunti());
        allenamentoSelezionato->setKmSterrato(dynamic_cast<Corsa*>(al)->getKmSterrato());
        allenamentoSelezionato->setKmStrada(dynamic_cast<Corsa*>(al)->getKmStrada());
        delete al;
        this->close();
    }

}
