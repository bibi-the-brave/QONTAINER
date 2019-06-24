#include "dialogciclismo.h"
#include "ciclismo.h"
#include "deepptr.h"

DialogCiclismo::DialogCiclismo(Contenitore<std::shared_ptr<Persona>>& cp_,
                               Contenitore<DeepPtr<Allenamento>>& ca_,
                               bool modifica,
                               int rigaMod,
                               QWidget* parent)
    : DialogAllenamento(cp_,ca_,modifica, rigaMod,parent)
{
    wCiclismo = new WidgetCiclismo();
    layoutPrincipale->addWidget(wCiclismo);
    aggiungiBottoni();

    setWindowTitle("CICLISMO");
    setLabelTitolo();

    connect(bReset, SIGNAL(clicked()), wCiclismo, SLOT(reset()));
    connect(bReset, SIGNAL(clicked()), this, SLOT(reset()));
    if(!modifica)
        connect(bConferma, SIGNAL(clicked()), this, SLOT(inserimentoAllenamento()));
    else {
        compilazioneFormModifica();
        connect(bConferma, SIGNAL(clicked()), this, SLOT(modificaAllenamento()));
    }
}

void DialogCiclismo::setLabelTitolo() {
    if(!modifica)
        lblTitolo->setText("NUOVO ALLENAMENTO CICLISMO");
    else
        lblTitolo->setText("MODIFICA ALLENAMENTO CICLISMO");
}

void DialogCiclismo::compilazioneFormModifica() {
    Ciclismo* a = dynamic_cast<Ciclismo*>(ca.At(rigaMod).get());
    if(!a)
        return;

    wCiclismo->setKmSalita(static_cast<int>(a->getKmSalita()));
    wCiclismo->setKmDiscesa(static_cast<int>(a->getKmDiscesa()));
    wCiclismo->setKmPianura(static_cast<int>(a->getKmPianura()));
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

    std::string strData = deData->date().toString("dd/MM/yyyy").toStdString();
    Allenamento* al = new Ciclismo(cp.At(cmbAtleti->currentIndex()),
                                static_cast<unsigned int>(spinDurata->value()),
                                Data(strData),
                                spinMagnesio->value(),
                                static_cast<unsigned int>(wCiclismo->kmSalita()),
                                static_cast<unsigned int>(wCiclismo->kmPianura()),
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

void DialogCiclismo::modificaAllenamento() {
    Ciclismo* allenamentoSelezionato = dynamic_cast<Ciclismo*>(ca.At(rigaMod).get());
    if(!allenamentoSelezionato)
        return;

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

    std::string strData = deData->date().toString("dd/MM/yyyy").toStdString();
    Allenamento* al = new Ciclismo(cp.At(cmbAtleti->currentIndex()),
                                   static_cast<unsigned int>(spinDurata->value()),
                                   Data(strData),
                                   spinMagnesio->value(),
                                   static_cast<unsigned int>(wCiclismo->kmSalita()),
                                   static_cast<unsigned int>(wCiclismo->kmPianura()),
                                   static_cast<unsigned int>(wCiclismo->kmDiscesa()));


    if(*allenamentoSelezionato == *al) {
        visualizzaMessaggioAllenamentoNonModificato();
        this->close();
        return; //lo metto perché è capitato che prima di eseguire close venga eseguita
        //la parte in cui si controlla doppione. Penso perché close possa essere multithread
    }


    if(ca.elementoPresente(al)) {
        dialogErroreDoppione();
        return;
    } else { //modifico l'atleta. Il model e la view si aggiornano in automatico
        allenamentoSelezionato->setData(al->getData());
        allenamentoSelezionato->setDurata(al->getDurata());
        allenamentoSelezionato->setMgMagnesio(al->getMgMagnesioAssunti());
        allenamentoSelezionato->setKmPianura(dynamic_cast<Ciclismo*>(al)->getKmPianura());
        allenamentoSelezionato->setKmSalita(dynamic_cast<Ciclismo*>(al)->getKmSalita());
        allenamentoSelezionato->setKmDiscesa(dynamic_cast<Ciclismo*>(al)->getKmDiscesa());
        this->close();
    }

}
